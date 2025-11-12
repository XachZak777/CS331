#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 8

int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

typedef struct {
	int start;
	int end;
} Range;

void* sum(void* arg) {
	if (arg == NULL) {
		perror("[ERROR] Argument Cannot be NULL \n");
		return (void *)1;
	}

	Range* range = (Range*)arg;
	int sum = 0;
	for (int i = range->start; i < range->end; i++) {
		sum += arr[i];
	}

	printf("[THREAD] Sum of Elements %d-%d = %d \n", range->start, range->end - 1, sum);

	return NULL;

}

int main () {
	printf("[INFO] Starting Program... \n");

	pthread_t thread_1; 
	pthread_t thread_2;

	Range range_1 = {0, SIZE / 2};
	Range range_2 = {SIZE / 2, SIZE};

	printf("[TASK] Creating Thread 1... \n");

	if (pthread_create(&thread_1, NULL, sum, &range_1) != 0) {
		perror("[ERROR] Thread Creation Failed \n");
		return 1;
	}

	printf("[TASK] Creating Thread 2... \n");

	if (pthread_create(&thread_2, NULL, sum, &range_2) != 0) {
		perror("[ERROR] Thread Creation Failed \n");
		return 1;
	}

	printf("[TASK] Joining Thread 1... \n");
	if (pthread_join(thread_1, NULL) != 0) {
		perror("[ERROR] Thread Join Failed \n");
		return 1;
	}

	printf("[TASK] Joining Thread 2... \n");
	if (pthread_join(thread_2, NULL) != 0) {
		perror("[ERROR] Thread Join Failed \n");
		return 1;
	}

	printf("[INFO] All Threads Executed Successfully... \n");
	printf("[INFO] Completing Program... \n");

	return 0;
}


