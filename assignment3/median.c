/*
Author:

This file provides a function called median3.  The function median3
takes three doubles and returns the median of them as a double.
*/
#include <stdio.h> /* printf */
#include <assert.h> /* assert */

double median3(double a, double b, double c) {}

int main() {
    assert(median3(0, 0, 0) == 0);
    assert(median3(0, 0, 1) == 0);
    assert(median3(1, 0, 0) == 0);
    assert(median3(1, 0, 1) == 1);

    assert(median3(1, 2, 3) == 2);
    assert(median3(2, 1, 3) == 2);
    assert(median3(1, 3, 2) == 2);
    assert(median3(3, 2, 1) == 2);
    assert(median3(2, 3, 1) == 2);
    assert(median3(3, 1, 2) == 2);

    assert(median3(1, -1, 0) == 0);
    assert(median3(1.5, -1.2, 0.3) == 0.3);

    return 0;
}
