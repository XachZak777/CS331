#include <stdio.h>

#pragma pack(2)
struct Pack2 {
    char a;
    int b;
    double c;
};

#pragma pack(4)
struct Pack4 {
    char a;
    int b;
    double c;
};

#pragma pack() // reset alignment

int main() {
    struct Pack2 s2;
    struct Pack4 s4;

    printf("With #pragma pack(2)\n");
    printf("Size of Pack2: %zu bytes\n", sizeof(s2));

    printf("\nWith #pragma pack(4)\n");
    printf("Size of Pack4: %zu bytes\n", sizeof(s4));

    return 0;
}

