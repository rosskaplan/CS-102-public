#include <stdio.h> /* printf */

int main() {
    float dividend = 77777.0;
    float divisor = 7.0;
    float quotient_a = dividend / divisor;
    float inverse = 1.0 / divisor;
    float quotient_b = dividend * inverse;
    printf("%.10f vs. \n%.10f\n", quotient_a, quotient_b);
}
