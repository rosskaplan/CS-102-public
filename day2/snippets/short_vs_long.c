#include <float.h> /* LDBL_MAX, LDBL_EPSILON */
#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {
    printf("short int [min] = %d\n", SHRT_MIN);
    printf("short int [max] = %d\n", SHRT_MAX);
    printf("long int [min] = %ld\n", LONG_MIN);
    printf("long int [max] = %ld\n", LONG_MAX);
    printf("long long int [min] = %lld\n", LLONG_MIN);
    printf("long long int [max] = %lld\n", LLONG_MAX);

    printf("long double [max] = %Lg\n", LDBL_MAX);
    printf("long double [min] = %Lg\n", LDBL_MIN);
    printf("long double [smallest] = %Lg\n", LDBL_EPSILON);
}

