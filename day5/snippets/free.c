#include <stdlib.h>
#include <stdio.h>

int main() {
    int *a = malloc(sizeof(int) * 8);
	if (a == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    a[7] = 5;
    printf("%d\n", a[7]);
    free(a); // 'a' is now a "Dangling Pointer"
    printf("%d\n", a[7]); // Anything could happen
    free(NULL); // Freeing a NULL pointer does nothing
}
