/*
Author:

This program impelements a function called 'transform' which accepts three
arguments
1. A function that takes a double and returns a double
2. An array of doubles (double *)
3. The length of that array (int)

The function modifies the array, applying the argument 1 function to each
element.
*/

#include <assert.h> /* assert */
#include <math.h> /* exp */


void transform(/* Put parameters here */) {}

double addOne(double x) {
    return x + 1;
}

double multTwo(double x) {
    return x * 2;
}

int main() {
    double x[3] = {0, 1, 2};
    transform(addOne, x, 3);
    assert(x[0] == 1.0);
    assert(x[1] == 2.0);
    assert(x[2] == 3.0);
    transform(multTwo, x, 3);
    assert(x[0] == 2.0);
    assert(x[1] == 4.0);
    assert(x[2] == 6.0);
    transform(exp, x, 3);
    assert(fabs(x[0] - 7.389056) < 1e-6);
    assert(fabs(x[1] - 54.598150) < 1e-6);
    assert(fabs(x[2] - 403.428793) < 1e-6);
}
