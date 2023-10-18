#include <stdio.h>

int main() {
    char *names[4];
    names[0] = "Ross";
    names[1] = "Cory";
    names[2] = "Gordon";
    names[3] = "Hala";
    int n;
    for (n = 0; n < 4; n++) {
        printf("name %d: %s\n", n, names[n]);
    }
}
