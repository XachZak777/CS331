#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	int sum = 0;
	printf("Input the number of elements: ");
	scanf("%d", &n);

	int *arr = (int *)malloc(n * sizeof(int));

	if (arr == NULL) {
		printf("Memory Allocation Failed.\n");
		return 1;
	}

	printf("Input %d integer values: ", n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	printf("Sum of Array Values: %d\n:", sum);

	free(arr);
	return 0;
}	
