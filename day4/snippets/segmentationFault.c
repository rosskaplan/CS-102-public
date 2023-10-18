#include <stdio.h>

int main() {
    // Declare array `a`
    int *a;

    for (int i = 0; i < 10000; i++) {
        printf("%d --> %d\n", i, *(a+i));
    }
}
