#include <stdio.h>

int main() {
    char *names[4] = {"Ross", "Cory", "Gordon"};
    names[3] = "Hala";
    int n;
    for (n = 0; n < 4; n++) {
        printf("name %d: %s\n", n, names[n]);
    }
}
