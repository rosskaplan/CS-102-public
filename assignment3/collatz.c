/*
Author:

This file provides three functions called: collatzWhile, collatzRecursive, and
collatzGoto.

each function takes exactly one input, n, and returns the same thing:
the number of steps it takes to get from n to 1 following the Collatz process.
The Collatz process is defined as follows:
1. Given n
2. If n is divisible by 2, divide n by 2
3. Otherwise, multiply n by 3 and add 1
4. Go to 1

collatzWhile is implemented with a while loop, collatzRecursive is implemented
recursively, and collatzGoto is implemented with the goto statement.
*/

#include <assert.h> /* assert */


int collatzGoto(long unsigned int n) {}

int collatzWhile(long unsigned int n) {}

int collatzRecursive(long unsigned int n) {}


int main () {
    assert(collatzRecursive(1) == 0);
    assert(collatzWhile(1) == 0);
    assert(collatzGoto(1) == 0);

    assert(collatzRecursive(27) == 111);
    assert(collatzWhile(27) == 111);
    assert(collatzGoto(27) == 111);

    assert(collatzRecursive(75128138247ul) == 1228);
    assert(collatzWhile(75128138247ul) == 1228);
    assert(collatzGoto(75128138247ul) == 1228);

    return 0;
}
