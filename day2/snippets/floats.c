#include <float.h> /* FLT_MAX, FLT_EPSILON, DBL_MAX, DBL_EPSILON, LDBL_MAX
                      LDBL_EPSILON */
#include <stdio.h> /* printf */

int main() {
    float a = -2.7;
    float b = 5.3;
    float c = 2e-6;
    printf("float [max] = %g\n", FLT_MAX);
    printf("float [min] = %g\n", FLT_MIN);
    printf("float [epsilon] = %g\n", FLT_EPSILON);
}
