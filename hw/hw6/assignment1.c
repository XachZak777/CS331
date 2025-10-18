#include <stdio.h>

int main() {
    int i = 10;
    char c = 'A';
    double d = 3.14;
    short s = 5;
    
    printf("Sizes:\n");    
    printf("Size of int: %zu bytes\n", sizeof(i));
    printf("Size of char: %zu bytes\n", sizeof(c));
    printf("Size of double: %zu bytes\n", sizeof(d));
    printf("Size of short: %zu bytes\n", sizeof(s));

    printf("\nAddresses:\n");
    printf("&i: %p\n", (void*)&i);
    printf("&c: %p\n", (void*)&c);
    printf("&d: %p\n", (void*)&d);
    printf("&s: %p\n", (void*)&s);

    return 0;
}

