#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {
    char a = 'A';
    char b = '0';
    char c = '-';
    printf("char [min] = %d\n", CHAR_MIN);
    printf("char [max] = %d\n", CHAR_MAX);
}
