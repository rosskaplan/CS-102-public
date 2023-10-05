/*
Author:

This file provides a function called uparrow.
uparrow(a, b, n) can also be denoted as a ^(n) b and satisifes:

a ^(n) b = a ^(n-1) (a ^(n-1) (a ^(n-1) ... a)
          [          b copies of a            ]
and a ^(0) b = a * b

More formally,
uparrow(a, b, n) = {
    a * b if n is 0
    1 if n > 0 and b = 0
    uparrow(a, uparrow(a, b-1, n), n-1) otherwise
}

You can think of this operation as the generalization that comes after
addition, multiplication, and exponentiation.  You can find more information
here: https://en.wikipedia.org/wiki/Knuth's_up-arrow_notation
*/

/*
Instructor Hints (You may delete this when submitting)

This function can grow very large even for small inputs.  I am only expecting
that your function works for the test cases below which use reasonable values,
and that your function would continue to work for larger values, if it were not
for the size limitation

I recommend that you use recursion and use a type that can hold large values

You will have to change the types in the function signature to the appropriate
types, do not use void.
*/

#include <assert.h> /* assert */

void uparrow(void a, void b, void n) {}

int main () {
    assert(uparrow(1, 1, 0) == 1);
    assert(uparrow(3, 4, 0) == 12);
    assert(uparrow(3, 4, 1) == 81);
    assert(uparrow(5, 7, 1) == 78125);
    assert(uparrow(1, 1, 2) == 1);
    assert(uparrow(1, 5, 2) == 1);
    assert(uparrow(2, 1, 2) == 2);
    assert(uparrow(3, 2, 2) == 27);
    assert(uparrow(3, 3, 2) == 7625597484987llu);
    assert(uparrow(2, 3, 3) == 65536);
    assert(uparrow(2, 2, 3) == 4);
    assert(uparrow(2, 2, 4) == 4);
    assert(uparrow(2, 2, 5) == 4);
    return 0;
}
