#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 8
#define TOTAL_ITEMS 16
#define PRODUCERS 2
#define CONSUMERS 2

int buffer[BUFFER_SIZE];
int in_pos = 0;
int out_pos = 0;

sem_t empty_slots;
sem_t full_slots;
pthread_mutex_t buffer_mutex;

int produced_count = 0;
int consumed_count = 0;

void* producer(void* arg) {
    int id = *(int*)arg;
    free(arg);

    while (1) {
        pthread_mutex_lock(&buffer_mutex);
        if (produced_count >= TOTAL_ITEMS) {
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        int item = produced_count + 1;
        produced_count++;
        pthread_mutex_unlock(&buffer_mutex);

        sem_wait(&empty_slots);
        pthread_mutex_lock(&buffer_mutex);
        buffer[in_pos] = item;
        in_pos = (in_pos + 1) % BUFFER_SIZE;
        printf("[INFO] Producer produced %d \n", item);
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full_slots);

        usleep(50000);
    }

    return NULL;
}

void* consumer(void* arg) {
    int id = *(int*)arg;
    free(arg);

    while (1) {
        pthread_mutex_lock(&buffer_mutex);
        if (consumed_count >= TOTAL_ITEMS) {
            pthread_mutex_unlock(&buffer_mutex);
            break;
        }
        pthread_mutex_unlock(&buffer_mutex);

        if (sem_wait(&full_slots) < 0) break;

        pthread_mutex_lock(&buffer_mutex);
        if (consumed_count >= TOTAL_ITEMS) {
            pthread_mutex_unlock(&buffer_mutex);
            sem_post(&full_slots);
            break;
        }

        int item = buffer[out_pos];
        out_pos = (out_pos + 1) % BUFFER_SIZE;
        consumed_count++;
        printf("[INFO] Consumer consumed %d \n", item);
        pthread_mutex_unlock(&buffer_mutex);

        sem_post(&empty_slots);
        usleep(50000);
    }
    return NULL;
}

int main() {
    printf("[INFO] Starting Producer-Consumer Simulation...\n");

    pthread_t producers[PRODUCERS];
    pthread_t consumers[CONSUMERS];

    pthread_mutex_init(&buffer_mutex, NULL);
    sem_init(&empty_slots, 0, BUFFER_SIZE);
    sem_init(&full_slots, 0, 0);

    for (int i = 0; i < PRODUCERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        if (pthread_create(&producers[i], NULL, producer, id) != 0) {
            perror("[ERROR] Failed to create producer thread");
            return 1;
        }
    }

    // create consumer threads
    for (int i = 0; i < CONSUMERS; i++) {
        int* id = malloc(sizeof(int));
        *id = i + 1;
        if (pthread_create(&consumers[i], NULL, consumer, id) != 0) {
            perror("[ERROR] Failed to create consumer thread");
            return 1;
        }
    }

    // join producer threads
    for (int i = 0; i < PRODUCERS; i++) {
        if (pthread_join(producers[i], NULL) != 0) {
            perror("[ERROR] Failed to join producer thread");
            return 1;
        }
    }

    // join consumer threads
    for (int i = 0; i < CONSUMERS; i++) {
        if (pthread_join(consumers[i], NULL) != 0) {
            perror("[ERROR] Failed to join consumer thread");
            return 1;
        }
    }

    printf("[INFO] All Threads Executed Successfully... \n");

    printf("[TASK] Total items produced: %d\n", produced_count);
    printf("[TASK] Total items consumed: %d\n", consumed_count);

    pthread_mutex_destroy(&buffer_mutex);
    sem_destroy(&empty_slots);
    sem_destroy(&full_slots);

    printf("[INFO] Completing Program...\n");
    return 0;
}

