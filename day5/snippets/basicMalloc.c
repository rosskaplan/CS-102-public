#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    char *str;
};

int main() {
    struct Node *np = (struct Node *) malloc(sizeof(struct Node));
	if (np == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    np->str = "Hello";
    np->next = NULL;
    printf("(%p, %s)\n", np->next, np->str);
}
