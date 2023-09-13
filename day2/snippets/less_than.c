#include <stdio.h> /* printf */

int main() {
    int x = 312;
    int y = 256;
    int xlty = x < y;
    int yltx = y < x;
    printf("xlty = %d\n", xlty);
    printf("yltx = %d\n", yltx);
}
