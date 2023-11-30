#include <assert.h>
#include <math.h>
#include <iostream>

/*
This program implements a simple 'List' *class* and some related *methods* which
can be used to manipulate it.  The List represents a variable sized array that
you can add elements to, or remove elements from.  The class uses *templating*
so that it can store a list of any type.

You should implement the methods in this order:
1. Constructor // Create a new <type> array using the "new" keyword (array = new int[maxlen] creates an array of 'maxlen' integers)
2. resize // resize the array to a given size (use new and delete)
3. push // Add a new <type> to the end of the array
4. pop // Remove and return <type> from the end of the array
5. operator[] // Used to get or set an element of the array (Check https://www.learncpp.com/cpp-tutorial/98-overloading-the-subscript-operator/ for help)
6. sum // Return the sum of all elements
7. Destructor // Free up the array using the "delete" keyword

Hints:
I recommend writing out a pure integer list first, then changing it to a
templated list.  Though this will not work for the provided test, you will
need to modify it.

Using 'new' and 'delete' has some drawbacks compared to 'malloc' and 'free'.
For one, there is no 'realloc' option.  So in order to extend your array, you
will have to create a new one of larger length and delete the old one.
*/

class List {};

int main() {
    List<int> ilist = List<int>();
    ilist.push(1);
    ilist.push(2);
    ilist.push(3);
    assert(ilist.sum() == 6);
    ilist.pop();
    ilist.pop();
    ilist.pop();
    for (int n = 0; n < 100; n++) {
        ilist.push(n);
        assert(ilist[n] == n);
    }
    for (int n = 99; n >= 0; n--) {
        int m = ilist.pop();
        assert(m == n);
    }

    List<double> dlist = List<double>();
    dlist.push(1.5);
    dlist.push(2.7);
    dlist.push(3.1);
    assert(abs(dlist.sum() - 7.3) < 0.000001);
    dlist.pop();
    dlist.pop();
    dlist.pop();
    for (double n = 0; n < 100; n++) {
        dlist.push(n);
        assert(dlist[n] == n);
    }
    for (double n = 99; n >= 0; n--) {
        double m = dlist.pop();
        assert(m == n);
    }
}
