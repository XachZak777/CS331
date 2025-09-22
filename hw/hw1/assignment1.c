#include <stdio.h>

void assignment1() {

    int num1 = 21;
    int *pointer1 = &num1;

    printf("Address of number using &num1 %p\n", &num1);
    printf("Address of number using pointer1 %p\n", pointer1);

    *pointer1 = 12;

    printf("New number after modification using pointer %d\n", num1);
}

void assignment2() {

    int arr2[5] = {12, 13, 14, 15, 16};
    int *pointer2 = arr2;

    printf("Original Array: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(pointer2+i));
    }

    printf("\n");

    printf("Modified Array Values (Using pointer notation): ");
    for (int i = 0; i < 5; i++) {
        *(pointer2+i) += 100;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(pointer2+i));
    }

    printf("\n");

    printf("Modified Array Values (Using array name notation): ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
}

void swap(int *val1, int *val2) {
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;
}

void assignment3() {

    int num3 = 21; 
    int num4 = 31;

    printf("Number 1 before swap: %d\n", num3);
    printf("Number 2 before swap: %d\n", num4);

    swap(&num3, &num4);

    printf("Number 1 after swap: %d\n", num3);
    printf("Number 2 after swap: %d\n", num4);
}

void assignment4() {

    int num5;
    int *pointer3 = &num5;
    int **pointer4 = &pointer3;
    **pointer4 = 69;

    printf("Value Using Pointer: %d\n", *pointer3);
    printf("Value Using Pointer to the Pointer: %d\n", **pointer4);
}

void assignment5() {

    char arr3[] = "Hripsime Hakobyan";
    char *pointer5 = arr3;

    while (*pointer5 != '\0') {
        printf("%c", *pointer5);
        pointer5++;
    }
    printf("\n");

    pointer5 = arr3;
    int count = 0;
    while (*pointer5 != '\0') { // Reset pointer
        count++;
        pointer5++;
    }
    printf("Length Of String: %d\n", count);
}

int main() {

    printf("Assignment 1 \n");
    assignment1();

    printf("Assignment 2 \n");
    assignment2();

    printf("Assignment 3 \n");
    assignment3();

    printf("Assignment 4 \n");
    assignment4();

    printf("Assignment 5 \n");
    assignment5();

    return 0;

}
