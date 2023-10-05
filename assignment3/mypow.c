/*
Author:

This C program defines 2 functions 'myPow' and 'myPowRecursive' that calculates the power of an integer base
raised to an integer exponent. The function takes two integer arguments, 'base' and 'exponent',
and returns the result of base^exponent as an integer.

You must implement myPow iteratively, i.e. using a loop (for, while, do).  You must implement
myPowRecursive recursively, i.e. without any loops.

Function Signature:
long long int myPow(int base, int exponent);

long long int myPowRecursive(int base, int exponent);

Note:
- The function assumes that the exponent is a non-negative integer.
- The result of raising any number to the power of 0 is 1.
- The result can be assumed to fit inside a long long int.

You may delete these hints upon submission if you want.
*/

#include <stdio.h> /* printf */
#include <assert.h> /* assert */

int main () {
	assert(myPow(2, 0) == 1LL);
	assert(myPow(2, 3) == 8LL);
	assert(myPow(5, 2) == 25LL);
	assert(myPow(0, 10) == 0LL);
	assert(myPow(1, 100) == 1LL);
	assert(myPow(10, 10) == 10000000000LL);
	assert(myPow(2, 40) == 1099511627776LL);
	assert(myPow(7, 15) == 4747561509943LL);

	assert(myPowRecursive(2, 0) == 1LL);
	assert(myPowRecursive(2, 3) == 8LL);
	assert(myPowRecursive(5, 2) == 25LL);
	assert(myPowRecursive(0, 10) == 0LL);
	assert(myPowRecursive(1, 100) == 1LL);
	assert(myPowRecursive(10, 10) == 10000000000LL);
	assert(myPowRecursive(2, 40) == 1099511627776LL);
	assert(myPowRecursive(7, 15) == 4747561509943LL);

    return 0;
}
