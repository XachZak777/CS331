#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

sem_t semA;
sem_t semB;
sem_t semC;

pthread_mutex_t print_lock;

void* thread_A(void* arg) {
    for (int i = 0; i < N; i++) {
        sem_wait(&semA);

        pthread_mutex_lock(&print_lock);
        printf("[THREAD A] A %d\n", i);
        pthread_mutex_unlock(&print_lock);

        sem_post(&semB);
    }
    return NULL;
}

void* thread_B(void* arg) {
    for (int i = 0; i < N; i++) {
        sem_wait(&semB);

        pthread_mutex_lock(&print_lock);
        printf("[THREAD B] B %d\n", i);
        pthread_mutex_unlock(&print_lock);

        sem_post(&semC);
    }
    return NULL;
}

void* thread_C(void* arg) {
    for (int i = 0; i < N; i++) {
        sem_wait(&semC);

        pthread_mutex_lock(&print_lock);
        printf("[THREAD C] C %d\n", i);
        pthread_mutex_unlock(&print_lock);

        sem_post(&semA);
    }
    return NULL;
}

int main() {
    printf("[INFO] Starting Ordered Printing Program...\n");

    pthread_t threadA;
    pthread_t threadB;
    pthread_t threadC;

    printf("[INFO] Creating Threads A, B, C... \n");
    pthread_mutex_init(&print_lock, NULL);

    sem_init(&semA, 0, 1);
    sem_init(&semB, 0, 0);
    sem_init(&semC, 0, 0);

    if (pthread_create(&threadA, NULL, thread_A, NULL) != 0) {
        perror("[ERROR] Failed to create Thread A");
        return 1;
    }
    if (pthread_create(&threadB, NULL, thread_B, NULL) != 0) {
        perror("[ERROR] Failed to create Thread B");
        return 1;
    }
    if (pthread_create(&threadC, NULL, thread_C, NULL) != 0) {
        perror("[ERROR] Failed to create Thread C");
        return 1;
    }

    printf("[INFO] Waiting for threads to finish...\n");

    if (pthread_join(threadA, NULL) != 0) {
        perror("[ERROR] Failed to join Thread A");
        return 1;
    }

    if (pthread_join(threadB, NULL) != 0) {
        perror("[ERROR] Failed to join Thread B");
        return 1;
    }

    if (pthread_join(threadC, NULL) != 0) {
        perror("[ERROR] Failed to join Thread C");
        return 1;
    }

    printf("[INFO] All threads completed successfully...\n");

    sem_destroy(&semA);
    sem_destroy(&semB);
    sem_destroy(&semC);
    pthread_mutex_destroy(&print_lock);

    printf("[INFO] Program Completed.\n");
    return 0;
}

