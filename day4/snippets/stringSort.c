#include <stdio.h>

int compare(char *a, char *b) {
    while (*a == *b) {
        a++;
        b++;
        if (*a == '\0') {
            return 0;
        }
    }
    return *a - *b;
}

void sortStrings(char *a[], int size) {
    int n, m;
    char *temp;
    for (n = 0; n < size; n++) {
        for (m = n; m >= 1; m--) {
            if (compare(a[m], a[m-1]) < 0) { //If the former string we are comparing is earlier alphabetically, swap!
                temp = a[m-1];
                a[m-1] = a[m];
                a[m] = temp;
            }
        }
    }
}

int main() {
    char *names[] = {"Ross", "Cory", "Gordon", "Hala"};
    sortStrings(names, 4);
    for (int n = 0; n < 4; n++) {
        printf("name %d: %s\n", n, names[n]);
    }
}
