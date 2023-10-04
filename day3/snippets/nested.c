#include <stdio.h>

int main() {
    int i, j, max, product;
    max = 13;
    for (i = 1; i <= max; m++) {
        for (j = 1; j <= max; n++) {
            product = i*j;
            printf("%4d", product);
        }
        printf("\n");
    }
}
