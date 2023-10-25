/*
Author:

This file provides a function called palindrome.  The function palindrome
returns takes a string (char *) and returns 1 if the string is a palindrome and
0 otherwise.  A string is a palindrome if it is exactly the same as its
reverse.  I.e. racecar is a palindrome, but Racecar is not.
*/

#include <string.h> /* strlen */
#include <assert.h> /* assert */

int palindrome(char *s) {}

int main() {
    assert(palindrome("abba") == 1);
    assert(palindrome("abbc") == 0);
    assert(palindrome("a bba") == 0);
    assert(palindrome("a bb a") == 1);
    assert(palindrome("aba") == 1);
    assert(palindrome("") == 1);
    assert(palindrome("ab") == 0);
    assert(palindrome("racecar") == 1);
    assert(palindrome("baac") == 0);
}
