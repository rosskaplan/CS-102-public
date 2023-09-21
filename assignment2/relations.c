/*
Author:

This program checks the following:
* 10 equals 10?
* 8 equals 010?
* 16 equals 0x10?
* 259 equals 0x103?
* 159 equals 0303?
* 255 equals 0xff?
* -1 equals 0xffff?
* -1 equals 0xffffffff?
* -1 equals 0xffffffffU?
* -1 greater than 1U?

Print the question and the answer as a 0 or 1 (examples for the first 3 are shown below)

*/

#include <stdio.h> /* printf */

int main () {
	printf("10 == 10: %d\n", 10 == 10);
	printf("8 == 010: %d\n", 8 == 010);
	printf("16 == 0x10: %d\n", 16 == 0x10);
}
