#include <stdio.h>
#include <stdlib.h>

int main() {
	int n;
	
	printf("Input the number of Students: ");
	scanf("%d", &n);

	int *grades = (int *)malloc(n * sizeof(int));
	if (grades == NULL) {
		printf("Memory Allocation Failed\n");
		return 1;
	}

	printf("Input Grades: ");
	for (int i = 0; i < n; i++) {
		scanf("%d", &grades[i]);
	}

	int max = grades[0];
	int min = grades[0];

	for (int i = 1; i < n; i++) {
		if (grades[i] > max) {
			max = grades[i];
		}
		
		if (grades[i] < min) {
			min = grades[i];
		}
	}

	printf("Max Grade: %d\n", max);
	printf("Min Grade: %d\n", min);

	free(grades);
	return 0;
}
