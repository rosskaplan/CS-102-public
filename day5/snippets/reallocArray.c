#include <stdlib.h>
#include <stdio.h>

int main() {
    int *a = malloc(sizeof(int) * 8);
	if (a == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    a[7] = 5;
    a = realloc(a, sizeof(int) * 16);
    printf("%d\n", a[7]);
    a[15] = 15;
    printf("%d\n", a[15]);
}
