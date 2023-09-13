#include <float.h> /* FLT_MAX, FLT_EPSILON, DBL_MAX, DBL_EPSILON, LDBL_MAX
                      LDBL_EPSILON */
#include <stdio.h> /* printf */

int main() {
    double a = -2.7;
    double b = 5.3;
    double c = 2e-6;
    printf("double [max] = %g\n", DBL_MAX);
    printf("double [min] = %g\n", DBL_MIN);
    printf("double [smallest] = %g\n", DBL_EPSILON);
}
