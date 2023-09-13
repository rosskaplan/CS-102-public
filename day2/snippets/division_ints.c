#include <stdio.h> /* printf */

int main() {
    int dividend = 30;
    int divisor = 4;
    int quotient = dividend / divisor;
    int remaining = dividend - quotient * divisor;
    printf("%d / %d = %d\n", dividend, divisor, quotient);
    printf("%d = %d * %d + %d\n", dividend, divisor, quotient, remaining);
}
