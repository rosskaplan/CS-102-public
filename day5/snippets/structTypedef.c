#include <stdio.h>
#include <stdlib.h>

typedef char *String;

typedef struct Node {
    struct Node *next;
    String str;
} Node;

int main() {
    Node *np = (Node *) malloc(sizeof(Node));
	if (np == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    np->str = "Hello";
    np->next = NULL;
    printf("(%p, %s)\n", np->next, np->str);
}
