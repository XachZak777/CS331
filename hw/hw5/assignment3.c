#include <stdio.h>
#include <stdlib.h>

int main() {
	int *arr = (int *)malloc(10 * sizeof(int));

	if (arr == NULL) {
		printf("Memory Allocation Failed\n");
		return 1;
	}

	printf("Input 10 integer values: ");
	for (int i = 0; i < 10; i++) {
		scanf("%d", &arr[i]);
	}

	printf("Array Before Resizing: ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	arr = (int *)realloc(arr, 5 * sizeof(int));
	
	if (arr == NULL) {
		printf("Memory Allocation Failed\n");
		return 1;
	}

	printf("Array After Resizing: ");
	for (int i = 0; i < 5; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	free(arr);
	return 0;
}
