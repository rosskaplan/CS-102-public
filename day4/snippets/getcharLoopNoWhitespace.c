#include <stdio.h>

int main() {
    int c;
    while ((c = getchar()) != EOF) {
		if (c != ' ' && c != '\t' && c != '\n') {
			printf("%c", c);
		}
    }
    printf("--Done reading!--\n");
}
