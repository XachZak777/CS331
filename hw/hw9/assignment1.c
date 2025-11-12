#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void* thread_exec(void* arg) {
	if (arg == NULL) {
		perror("[ERROR] Argument Cannot be NULL \n");
		return (void *)1;
	}

	int id = *(int*)arg;
	printf("[THREAD %d] Thread is Running (ID: %lu) \n", id, pthread_self());
	return NULL;
}

int main () {
	printf("[INFO] Starting Program... \n");

	pthread_t threads[3];
	int ids[3];

	printf("[INFO] Creating Threads... \n");

	for (int i = 0; i < 3; i++) {
		ids[i] = i+1;
		printf("[TASK] Creating Thread %d... \n", (i+1));
		if (pthread_create(&threads[i], NULL, thread_exec, &ids[i]) != 0) {
			perror("[ERROR] Thread Creation Failed \n");
			return 1;
		}
	}

	printf("[INFO] Joining Threads... \n");

	for (int i = 0; i < 3; i++) {
		printf("[TASK] Joining Thread %d... \n", (i+1));
		if (pthread_join(threads[i], NULL) != 0) {
			perror("[ERROR] Thread Join Failed \n");
			return 1;
		}
	}

	printf("[INFO] All Threads Executed Successfully... \n");
	printf("[INFO] Completing Program... \n");

	return 0;
}
