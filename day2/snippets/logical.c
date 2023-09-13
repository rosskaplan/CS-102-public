#include <stdio.h> /* printf */

int main() {
    int x = 256;
    int inRange = (x > 128) && (x < 512);
    int notInRange = !((x > 128) && (x < 512));
    printf("inRange = %d\n", inRange);
    printf("notInRange = %d\n", notInRange);
}
