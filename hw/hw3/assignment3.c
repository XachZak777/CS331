#include <stdio.h>
#include <stdlib.h>

void func1() {
    printf("Function 1 executed.\n");
}

void func2() {
    printf("Function 2 executed.\n");
}

int main() {
    atexit(func1);
    atexit(func2);

    printf("Main Running...\n");

    return 0;
}
