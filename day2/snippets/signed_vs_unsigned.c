#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       INT_MIN, INT_MAX */
#include <stdio.h> /* printf */

int main() {
    printf("signed char [min] = %d\n", SCHAR_MIN);
    printf("signed char [max] = %d\n", SCHAR_MAX);
    printf("unisgned char [min] = %u\n", 0);
    printf("unisgned char [max] = %u\n", UCHAR_MAX);

    printf("signed int [min] = %d\n", INT_MIN);
    printf("signed int [max] = %d\n", INT_MAX);
    printf("unisgned int [min] = %u\n", 0);
    printf("unisgned int [max] = %u\n", UINT_MAX);
}
