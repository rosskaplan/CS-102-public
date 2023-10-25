/*
Author:

This file provides a function called strip, which takes a string, and
modifies it in place so that it only includes alpha-numeric values with
no spaces in between.  For example, 'a !b.   c' becomes 'abc'.
*/

#include <ctype.h> /* isalnum */
#include <string.h> /* strcpy */
#include <assert.h> /* assert */

void strip(char *s) {}

int main() {
    char s[80];

    strcpy(s, "a bba");
    strip(s);
    assert(strcmp(s, "abba") == 0);

    strcpy(s, "a .bb !a");
    strip(s);
    assert(strcmp(s, "abba") == 0);

    strcpy(s, "A man, a plan, a canal: Panama!");
    strip(s);
    assert(strcmp(s, "AmanaplanacanalPanama") == 0);
}
