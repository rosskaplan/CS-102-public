/*
Exercise 2-1, based off of tutorialspoint.com:
https://www.tutorialspoint.com/c_standard_library/limits_h.htm
*/

#include <float.h> /* FLT_MAX, FLT_EPSILON, DBL_MAX, DBL_EPSILON, LDBL_MAX
                      LDBL_EPSILON */
#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {

    printf("The number of bits in a char %d\n", CHAR_BIT);

    printf("signed char [min] = %d\n", SCHAR_MIN);
    printf("signed char [max] = %d\n", SCHAR_MAX);
    printf("unisgned char [max] = %d\n", UCHAR_MAX);
    printf("char [min] = %d\n", CHAR_MIN);
    printf("char [max] = %d\n", CHAR_MAX);

    printf("short int [min] = %d\n", SHRT_MIN);
    printf("short int [max] = %d\n", SHRT_MAX); 

    printf("int [min] = %d\n", INT_MIN);
    printf("int [max] = %d\n", INT_MAX);

    printf("long [min] = %ld\n", LONG_MIN);
    printf("long [max] = %ld\n", LONG_MAX);

    printf("long long [min] = %lld\n", LLONG_MIN);
    printf("long long [max] = %lld\n", LLONG_MAX);

    printf("float [max] = %g\n", FLT_MAX);
    printf("float [smallest] = %g\n", FLT_EPSILON);
    printf("double [max] = %g\n", DBL_MAX);
    printf("double [smallest] = %g\n", DBL_EPSILON);
    printf("long double [max] = %Lg\n", LDBL_MAX);
    printf("long double [smallest] = %Lg\n", LDBL_EPSILON);

    return(0);
}
