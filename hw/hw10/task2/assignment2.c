#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

#define NUM_DEPOSIT 4
#define NUM_WITHDRAW 4
#define ITERATIONS 100000

long long balance = 0;

pthread_mutex_t mutex_lock;
pthread_spinlock_t spin_lock;

char lock_type = 'M'; // 'M' = mutex, 'S' = spinlock
char cs_type = 'S';   // 'S' = short, 'L' = long

void lock() {
    if (lock_type == 'M') pthread_mutex_lock(&mutex_lock);
    else pthread_spin_lock(&spin_lock);
}

void unlock() {
    if (lock_type == 'M') pthread_mutex_unlock(&mutex_lock);
    else pthread_spin_unlock(&spin_lock);
}

void* deposit(void* arg) {
    printf("[THREAD] Deposit started\n");
    for (int i = 0; i < ITERATIONS; i++) {
        lock();
        balance++;
        if (cs_type == 'L') {
            usleep(10);
        }
        unlock();
    }
    printf("[THREAD] Deposit finished\n");
    return NULL;
}

void* withdraw(void* arg) {
    printf("[THREAD] Withdraw started\n");
    for (int i = 0; i < ITERATIONS; i++) {
        lock();
        balance--;
        if (cs_type == 'L') {
            usleep(10);
        }
        unlock();
    }
    printf("[THREAD] Withdraw finished\n");
    return NULL;
}

int main(int argc, char** argv) {
    if (argc != 3) {
        printf("[INFO] Usage: ./bank_account [mutex|spin] [short|long]\n");
        return 1;
    }

    if (strcmp(argv[1], "mutex") == 0) {
        lock_type = 'M';
    } else if (strcmp(argv[1], "spin") == 0) {
        lock_type = 'S';
    } else {
        printf("[ERROR] Invalid lock type: %s\n", argv[1]);
        return 1;
    }

    if (strcmp(argv[2], "short") == 0) {
        cs_type = 'S';
    } else if (strcmp(argv[2], "long") == 0) {
        cs_type = 'L';
    } else {
        printf("[ERROR] Invalid critical section type: %s\n", argv[2]);
        return 1;
    }

    printf("[INFO] Starting Bank Simulation\n");
    printf("[INFO] Lock: %s | CS: %s\n",
           lock_type == 'M' ? "MUTEX" : "SPINLOCK",
           cs_type == 'S' ? "SHORT" : "LONG");

    if (lock_type == 'M') {
        printf("[INFO] Initializing mutex...\n");
        pthread_mutex_init(&mutex_lock, NULL);
    } else {
        printf("[INFO] Initializing spinlock...\n");
        pthread_spin_init(&spin_lock, PTHREAD_PROCESS_PRIVATE);
    }

    pthread_t deposits[NUM_DEPOSIT];
    pthread_t withdraws[NUM_WITHDRAW];

    printf("[INFO] Creating threads...\n");

    for (int i = 0; i < NUM_DEPOSIT; i++) {
        if (pthread_create(&deposits[i], NULL, deposit, NULL) != 0) {
            perror("[ERROR] Failed to create deposit thread");
            return 1;
        }
    }

    for (int i = 0; i < NUM_WITHDRAW; i++) {
        if ( pthread_create(&withdraws[i], NULL, withdraw, NULL) != 0) {
            perror("[ERROR] Failed to create withdraw thread");
            return 1;
        }
    }

    printf("[INFO] Waiting for all threads to finish...\n");

    for (int i = 0; i < NUM_DEPOSIT; i++) {
       if (pthread_join(deposits[i], NULL) != 0) {
            perror("[ERROR] Failed to join deposit thread");
            return 1;
       }
    }

    for (int i = 0; i < NUM_WITHDRAW; i++) {
       if (pthread_join(withdraws[i], NULL) != 0) {
            perror("[ERROR] Failed to join withdraw thread");
            return 1;
       }
    }

    if (lock_type == 'M') {
        pthread_mutex_destroy(&mutex_lock);
    } else {
        pthread_spin_destroy(&spin_lock);
    }

    printf("[INFO] All Threads Executed Successfully... \n");
    printf("[RESULT] Expected balance: 0\n");
    printf("[RESULT] Actual balance:   %lld\n", balance);
    printf("[INFO] Bank Simulation Completed\n");
    return 0;
}

