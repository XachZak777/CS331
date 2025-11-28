#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>

#define N 4
#define M 1000000

long long counter = 0;

pthread_mutex_t mutex_lock;
pthread_spinlock_t spin_lock;

void* increment(void* arg) {
    char mode = *(char*)arg;

    printf("[THREAD] Started with mode %c\n", mode);

    for (int i = 0; i < M; i++) {

        if (mode == 'A') {
            counter++;
        } else if (mode == 'B') {
            pthread_mutex_lock(&mutex_lock);
            counter++;
            pthread_mutex_unlock(&mutex_lock);
        } else if (mode == 'C') {
            pthread_spin_lock(&spin_lock);
            counter++;
            pthread_spin_unlock(&spin_lock);
        }
    }

    printf("[THREAD] Finished mode %c\n", mode);
    return NULL;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("A = No sync\n");
        printf("B = Mutex\n");
        printf("C = Spinlock\n");
        return 1;
    }

    char mode = argv[1][0];

    if (mode != 'A' && mode != 'B' && mode != 'C') {
        perror("[ERROR] Invalid mode. Use A, B, or C.\n");
        return 1;
    }

    printf("[INFO] Starting Program...\n");
    printf("[INFO] Mode Selected: %c\n", mode);
    printf("[INFO] Creating %d threads \n", N);

    if (mode == 'B') {
        printf("[INFO] Initializing MUTEX...\n");
        pthread_mutex_init(&mutex_lock, NULL);
    }

    if (mode == 'C') {
        printf("[INFO] Initializing SPINLOCK...\n");
        pthread_spin_init(&spin_lock, PTHREAD_PROCESS_PRIVATE);
    }

    pthread_t threads[N];

    printf("[INFO] Creating threads...\n");

    for (int i = 0; i < N; i++) {
        if (pthread_create(&threads[i], NULL, increment, &mode) != 0) {
            perror("[ERROR] Thread Creation Failed \n");
            return 1;
        }
    }

    printf("[INFO] Waiting for threads to complete...\n");

    for (int i = 0; i < N; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
		perror("[ERROR] Thread Join Failed \n");
		return 1;
	}
    }

    if (mode == 'B') {
        pthread_mutex_destroy(&mutex_lock);
    }
    if (mode == 'C') {
        pthread_spin_destroy(&spin_lock);
    }

    long long expected = (long long)N * M;
    printf("[INFO] All Threads Executed Successfully... \n");
    printf("[RESULT] Expected: %lld\n", expected);
    printf("[RESULT] Actual:   %lld\n", counter);
    printf("[INFO] Program Completed.\n");
    return 0;
}

