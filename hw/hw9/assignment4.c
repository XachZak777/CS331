#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define SIZE 5

int nums[SIZE] = {1, 2, 3, 4, 5};

void* square(void* arg) {
	if (arg == NULL) {
		perror("[ERROR] Argument Cannot be NULL");
		return (void *)1;
	}

	int num = *(int*)arg;
	printf("[THREAD %d] Square of %d = %d \n", num, num, num*num);
        return NULL;
}

int main () {

	printf("[INFO] Starting Program... \n");
	pthread_t threads[SIZE];

	printf("[INFO] Creating Threads... \n");
	for (int i = 0; i < SIZE; i++) {
		printf("[TASK] Creating Thread %d... \n", (i+1));
		if (pthread_create(&threads[i], NULL, square, &nums[i]) != 0) {
			perror("[ERROR] Thread Create Failed \n");
			return 1;
		}
	}

	printf("[INFO] Joining Threads... \n");
	for (int i = 0; i < SIZE; i++) {
		printf("[TASK] Joining Thread %d... \n", (i+1));
		if (pthread_join(threads[i], NULL) != 0) {
			perror("[ERROR] Thread Join Failed \n");
			return 1;
		}
	}

	printf("[INFO] All Threads Executed Successfully...  \n");
	printf("[INFO] Completing Program... \n");

	return 0;
}
