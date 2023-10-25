/*
Author:

This program implements a function 'lower' which accepts a string (character
pointer) and modifies the string, converting each alphabetic character to
lowercase.
*/

#include <ctype.h> /* isalpha */
#include <string.h> /* tolower */
#include <assert.h> /* assert */

void lower(char *s) {}

int main() {
    char s[80];

    strcpy(s, "ABbA");
    lower(s);
    assert(strcmp(s, "abba") == 0);

    strcpy(s, "A.BB!A");
    lower(s);
    assert(strcmp(s, "a.bb!a") == 0);

    strcpy(s, "AmanaplanacanalPanama");
    lower(s);
    assert(strcmp(s, "amanaplanacanalpanama") == 0);
}
