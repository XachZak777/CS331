#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 50

int main() {
	int n = 3;
	int m = 2;

	char **arr = (char **)malloc(n * sizeof(char *));
	if (arr == NULL) {
		printf("Memory Allocation Failed\n");
		return 1;
	}

	for (int i = 0; i < n; i++) {
		arr[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
		if (arr[i] == NULL) {
			printf("Memory Allocation Failed\n");
			return 1;
		}
	}

	printf("Input 3 String values: ");
	for (int i = 0; i < n; i++) {
		scanf("%s", arr[i]);
	}

	arr = (char **)realloc(arr, (n + m) * sizeof(char *));
	if (arr == NULL) {
		printf("Memory Allocation Failed\n");
		return 1;
	}

	for (int i = n; i < n + m; i++) {
		arr[i] = (char *)malloc(MAX_LENGTH * sizeof(char));
		if (arr[i] == NULL) {
			printf("Memory Allocation Failed\n");
			return 1;
		}
	}

	printf("Input 2 String values: ");
	for (int i = n; i < n + m; i++) {
		scanf("%s", arr[i]);
	}

	printf("Final Version: ");
	for(int i = 0; i < n + m; i++) {
		printf("%s ", arr[i]);
	}

	printf("\n");

	for (int i = 0; i < n + m; i++) {
		free(arr[i]);
	}

	free(arr);
	return 0;
}
