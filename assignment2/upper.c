/*
Author:

This program converts a lower-case character to upper case, leaves non lower
case characters the same, and prints the result.  It uses the ternary operator.
*/

/*
Instructor Hints (You may delete this when submitting)

Here is some code which converts a lower-case charater to upper-case, and leaves all other characters the same.

char character = 'd';
char upperCase;
if (character >= 'a' && character <= 'z')
    upperCase = character + ('A' - 'a');
else
    upperCase = character;
    
In english, this reads as "If the character variable is a lower-case character, 
set the upperCase variable to (character + ('A' - 'a')) otherwise set it to (character)"

We haven't learned if/else statements yet so you must do this using the ternary operator.
*/

#include <stdio.h> /* printf */

int main () {
    char character = 'd';
    char upperCase;
    printf("%c\n", upperCase);
}
