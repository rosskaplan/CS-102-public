#include <stdio.h> /* printf */

int main() {
    int x = 256;
    int y = 312;
    // Get the larger value
    int z = x > y ? x : y;
    printf("max = %d\n", z);
}
