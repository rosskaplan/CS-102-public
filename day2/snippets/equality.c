#include <stdio.h> /* printf */

int main() {
    int x = 256;
    int y = 256;
    int z = 123;
    int xeqy = x == y;
    int xeqz = x == z;
    printf("xeqy = %d\n", xeqy);
    printf("xeqz = %d\n", xeqz);
}
