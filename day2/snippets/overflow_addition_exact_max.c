#include <stdio.h> /* printf */

int main() {
    short a = 32767;
    short b = 32767;
    short c = a + b;
    printf("%d + %d = %d\n", a, b, c);
}
