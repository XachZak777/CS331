#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	float avg = 0.0;
	
	printf("Input the number of elements: ");
	scanf("%d", &n);

	int *arr = (int *)calloc(n, sizeof(int));
	if (arr == NULL) {
		printf("Memory Allocation Failed \n");
		return 1;
	}

	printf("Array After calloc(): ");

	for (int i = 0; i < n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Enter %d integers: ", n);
	int sum = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
		sum += arr[i];
	}

	avg = (float)sum/n;

	printf("Array After Update: ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("Avarage Value of the Array: %.3f\n", avg);

	free(arr);
	return 0;
}
