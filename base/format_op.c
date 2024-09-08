#include <stdio.h>
#include<stdbool.h>
int main() {
    int a = 123;
    unsigned int b = 123u;
    long c = 123L;
    long long d = 123LL;
    float e = 123.456f;
    double f = 123.456;
    long double g = 123.456L;
    char h = 's';
    char *i = "Hello, World!";
    void *p = &a;
    bool ascend = false;
    bool desascend = true;

    printf("bool ascend:%d\n",ascend);
    printf("bool ascend:%d\n",desascend);
    printf("Signed integer: %d\n", a);
    printf("Unsigned integer: %u\n", b);
    printf("Long integer: %ld\n", c);
    printf("Long long integer: %lld\n", d);
    printf("Float: %f\n", e);
    printf("Double: %f\n", f);
    printf("Long double: %Lf\n", g);
    printf("Character: %c\n", h);
    printf("String: %s\n", i);
    printf("Pointer: %p\n", p);

    return 0;
}

