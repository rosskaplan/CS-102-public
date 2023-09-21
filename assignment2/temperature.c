/*
Author:

This program converts an integer Fahrenheit temperatue from to floating point
Celsius with one decimal of precision.  An example printed result would be "32F
= 0.0C"
*/

/*
Instructor Hints (You may delete this when submitting)

You can specify precision when printing floating point by prefixing the f in
%f with .{number}.  For example printf("%.2f\n", 1.234) will print "1.23"

The general formula for for temperature in celsius is (F − 32) * 5/9 = 0
*/

#include <stdio.h> /* printf */

int main () {
    int FahrenheitTemperature = 65;
    float CelsiusTemperature;
    printf("%.2f\n", CelsiusTemperature);
}
