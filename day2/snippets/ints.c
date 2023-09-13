#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {
    int a = -30;
    int b = 12;
    int c = 1e5;
    printf("int [min] = %d\n", INT_MIN);
    printf("int [max] = %d\n", INT_MAX);
}
