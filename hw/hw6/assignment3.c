#include <stdio.h>

struct NormalStruct {
    char a;
    int b;
    double c;
};

#pragma pack(1)
struct PackedStruct {
    char a;
    int b;
    double c;
};
#pragma pack()

int main() {
    struct NormalStruct s1;
    struct PackedStruct s2;

    printf("Without #pragma pack \n");
    printf("Size of NormalStruct: %zu bytes\n", sizeof(s1));
    printf("&a: %p\n", (void*)&s1.a);
    printf("&b: %p\n", (void*)&s1.b);
    printf("&c: %p\n", (void*)&s1.c);

    printf("\n With #pragma pack(1) \n");
    printf("Size of PackedStruct: %zu bytes\n", sizeof(s2));
    printf("&a: %p\n", (void*)&s2.a);
    printf("&b: %p\n", (void*)&s2.b);
    printf("&c: %p\n", (void*)&s2.c);

    return 0;
}

