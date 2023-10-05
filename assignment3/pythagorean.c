/*
Author:

This file provides a function called triplesInRange which takes two
arguments, lower and upper and returns the number of unique Pythagorean
triples, (a, b, c) such that each number is between lower and upper.

A triple (a, b, c) is a pythagorean triple if a, b, and c are positive
intengers (greater than 0) such that the square of a plus the square of b is
equal to the square of c.

The numbers may include lower and upper, and it does not count duplicates, e.g.
(3, 4, 5) is a duplicate of (5, 4, 3) so triplesInRange(3, 5) is 1.  It does
include multiples however, so even though (6, 8, 10) is a multiple of (3, 4, 5)
it is still valid and therefore triplesInRange(0, 10) is 2.
*/

/*
Instructor Hints (You may delete this when submitting)
You should use nested for loops
*/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */


int triplesInRange(int lower, int upper) {}

int main () {
    assert(triplesInRange(0, 0) == 0);
    assert(triplesInRange(1, 1) == 0);
    assert(triplesInRange(3, 5) == 1);
    assert(triplesInRange(0, 10) == 2);
    assert(triplesInRange(-10, 10) == 2);
    assert(triplesInRange(45, 100) == 9);
    assert(triplesInRange(45, 100) == 9);

    return 0;
}
