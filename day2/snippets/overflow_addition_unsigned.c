#include <stdio.h> /* printf */

int main() {
    unsigned short a = 65535;
    unsigned short b = 1;
    unsigned short c = a + b;
    printf("%d + %d = %d\n", a, b, c);
}

