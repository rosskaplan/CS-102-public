/*
Author:

This file simulates Conway's game of life on a 18x11 grid from an initial state
provided in 'game.txt'  The file 'game.txt' consists of 18 lines of length
11 (plus a newline).  An 'X' represents a live cell and a '.' represents a
dead cell. 

The program works as follows:
First, the 'load' function loads the initial state in 'game.txt' into a fixed size
18x11 integer array.
Then, in an infinite loop:
    * The array is displayed with the "display" function
    * The array is updated according to the rules.
    * There is 0.1 seconds of delay

The Rules:
    1. Any live cell with fewer than two live neighbours dies
    2. Any live cell with two or three live neighbours lives
    3. Any live cell with more than three live neighbours dies
    4. Any dead cell with exactly three live neighbours becomes a live cell

A neighbor is any cell to the immediate left, right, up, down, or diagonal of a
given cell.
*/

#include <stdio.h>
#include <unistd.h>

#define HEIGHT 18
#define WIDTH 11


void update(int g[HEIGHT][WIDTH]) {}

void display(int g[HEIGHT][WIDTH]) {}

void load(char path[], int g[HEIGHT][WIDTH]) {}

int main() {}
