#include <stdio.h> /* printf */

int main() {
    int x = 112;
    int xDividedByTwo = x >> 1;
    int xTimesTwo = x << 1;
    printf("x = %d\n", x);
    printf("xDividedByTwo = %d\n", xDividedByTwo);
    printf("xTimesTwo = %d\n", xTimesTwo);
}
