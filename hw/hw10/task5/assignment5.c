#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_THREADS 10
#define PRINTER_COUNT 3

sem_t printers;
pthread_mutex_t count_lock;

int active_printers = 0;

void* print_job(void* arg) {
    int id = *(int*)arg;

    printf("[THREAD %d] Waiting for a free printer...\n", id);

    sem_wait(&printers);

    pthread_mutex_lock(&count_lock);
    active_printers++;
    printf("[THREAD %d] Started printing. Active printers: %d\n",
            id, active_printers);
    pthread_mutex_unlock(&count_lock);

    usleep(200000);

    pthread_mutex_lock(&count_lock);
    active_printers--;
    printf("[THREAD %d] Finished printing. Active printers: %d\n",
            id, active_printers);
    pthread_mutex_unlock(&count_lock);

    sem_post(&printers);

    return NULL;
}

int main() {
    printf("[INFO] Starting Printer Pool Simulation...\n");
    printf("[INFO] Total threads: %d, Available printers: %d\n",
           NUM_THREADS, PRINTER_COUNT);

    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    pthread_mutex_init(&count_lock, NULL);

    sem_init(&printers, 0, PRINTER_COUNT);
    printf("[INFO] Semaphore initialized with %d printers.\n", PRINTER_COUNT);

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        if (pthread_create(&threads[i], NULL, print_job, &thread_ids[i]) != 0) {
            perror("[ERROR] Failed to create thread");
            exit(1);
        }
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("[ERROR] Failed to join thread");
            exit(1);
        }
    }

    printf("[INFO] All print jobs completed.\n");

    sem_destroy(&printers);
    pthread_mutex_destroy(&count_lock);

    printf("[INFO] Program Finished.\n");
    return 0;
}

