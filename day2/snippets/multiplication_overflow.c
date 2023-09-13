#include <stdio.h> /* printf */

int main() {
    short int a = 300;
    short int b = 400;
    short int c = a*a + b*b;
    printf("%d*%d + %d*%d = %d\n", a, a, b, b, c);
}
