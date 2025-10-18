#include <stdio.h>

struct Struct1 {
    char a;
    int b;
    double c;
};

struct Struct2 {
    double c;
    int b;
    char a;
};

int main() {
    struct Struct1 s1;
    struct Struct2 s2;

    printf("Struct 1 (char, int, double):\n");
    printf("Size: %zu bytes\n", sizeof(s1));
    printf("&a: %p\n", (void*)&s1.a);
    printf("&b: %p\n", (void*)&s1.b);
    printf("&c: %p\n\n", (void*)&s1.c);

    printf("Struct 2 (double, int, char):\n");
    printf("Size: %zu bytes\n", sizeof(s2));
    printf("&c: %p\n", (void*)&s2.c);
    printf("&b: %p\n", (void*)&s2.b);
    printf("&a: %p\n", (void*)&s2.a);

    return 0;
}

