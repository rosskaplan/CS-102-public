#include <stdio.h>
#include <stdlib.h>

void printArgv(char* argv[], int argc) {
	printf("Argv reversed: [");
	for (int i = 1; i < argc; i++) { //Starting at 1 because the executable name, like a.out, is in argv[0]
		printf("%s", argv[i]);
		if (argc - 1 != i) {
			printf(", ");
		}
	}
	printf("]\n");
}

int main(int argc, char *argv[]) {
	char *temp;

	for (int i = 1, j = argc - 1; i < j; i++, j--) {
		temp = argv[i];
		argv[i] = argv[j];
		argv[j] = temp;
	}

	printArgv(argv, argc);
}
