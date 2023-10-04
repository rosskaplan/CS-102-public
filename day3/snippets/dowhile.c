#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = -1;
    do {
        n = rand();
    }
    while (n > 100);
    printf("Random number between 0 and 100: %d\n", n);
}
