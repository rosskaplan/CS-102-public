# Structures

Structures are a C concept that you can use to organize your data.  In all
of our previous examples, we usually passed two related pieces of data as
two separate units into a function.  For example, whenever we had to process
an array, we also passed it's length.  When we wanted to find a Pythagorean
triple, we passed three different ints separately.  You can imagine other
cases where this becomes excessive, for example, when storing information
about a person or a user of a system, we would naturally want sone way
of grouping the related information.  This is where structures come into
play.

## Structure Syntax

A structure is defined with the following syntax:

```c
// snippets/structure_form.c

struct STRUCT_TAG {
    TYPE_1 MEMBER_1;
    TYPE_2 MEMBER_2;
    ...
    TYPE_N MEMBER_N;
};

```

The text following `struct` is called the *structure tag* which can be used
to reference it later.  The text following types within the braces are
called *members*.  Let's take a look at a simple example, creating a
structure that represents a simple two dimensional point.

```c
// snippets/simpleStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    return 0;
}

```

A variable of structure type can be declared and initialized similar to
an array:

```
struct STRUCT_TAG VAR_NAME = {MEMBER_1, MEMBER_2, ... MEMBER_N};
```

which is demonstrated in the following code.

```c
// snippets/declareStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point pt = {3, 4};
}

```

To access the values of the members of a struct, you can use the *structure
member operator*, also called the *dot operator*.

```
TYPE_1 VAR = STRUCT_VAR.MEMBER_1;
```

This is demonstrated in the following code.

```c
// snippets/accessStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

int main() {
    struct Point pt = {3, 4};
    printf("(%d, %d)\n", pt.x, pt.y);
}

```

```
(3, 4)
```

One very useful property of structs is that you can compose them as many
times as you want.  That is, the members of a struct can be structs themselves.
This is demonstrated below, where we create a line struct from two points,
and access the individual members by using the member operator twice.

### Problem

How can we define a structure representing a circle?

Answer: A circle's center and radius should work!

## Structures And Functions

Structures interact with functions in basically the same way that regular
variables do.  They can be regular arguments, and return values from functions,
and they can also be initialized from a function call.  First, let's create
a function that can initialize a point.

```c
// snippets/functionStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point makePoint(int x, int y) {
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

int main() {
    struct Point pt = makePoint(3, 4);
    printf("(%d, %d)\n", pt.x, pt.y);
}

```

```
(3, 4)
```

You can see it pretty much works as expected.  Note however that this
method of creating a new struct allows the programmer to enter some common
boilerplate code into the creation of the struct.

Now we show some code demonstrating the use of a struct as an argument by
adding two points together.

```c
// snippets/argumentStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

struct Point makePoint(int x, int y) {
    struct Point p;
    p.x = x;
    p.y = y;
    return p;
}

struct Point addPoints(struct Point p1, struct Point p2) {
    struct Point p;
    p.x = p1.x + p2.x;
    p.y = p1.y + p2.y;
    return p;
}

int main() {
    struct Point p1 = makePoint(3, 4);
    struct Point p2 = makePoint(4, 5);
    struct Point pt = addPoints(p1, p2);
    printf("(%d, %d)\n", pt.x, pt.y);
}

```

```
(7, 9)
```

Now, just as we went over pointers for regular variables in the last session,
so too can you have pointers to structs.  In fact, if you have a large struct
containing many members, it can be much more efficient to pass a pointer to
that struct rather the struct itself.  Remember, anything passed into a function is
passed by value, so for a large struct, passing the pointer by value is much smaller
than passing the struct itself by value.  Let's look at the simple example of
using a struct pointer to modify a point in place.

```c
// snippets/pointerStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

void negatePoint(struct Point *p) {
    (*p).x = -(*p).x;
    (*p).y = -(*p).y;
}

int main() {
    struct Point pt = {3, 4};
    negatePoint(&pt);
    printf("(%d, %d)\n", pt.x, pt.y);
}

```

```
(-3, -4)
```

In this example, we first dereference the incoming struct pointer, then
access its member for both reading and writing.  If you think this syntax
is verbose, ugly, and in need of improvement, you are in good company.

In fact the creators of C thought the same, and so they added the *arrow
operator*, which is demonstrated below:

```c
// snippets/arrowStruct.c

#include <stdio.h>

struct Point {
    int x;
    int y;
};

void negatePoint(struct Point *p) {
    p->x = -p->x;
    p->y = -p->y;
}

int main() {
    struct Point pt = {3, 4};
    negatePoint(&pt);
    printf("(%d, %d)\n", pt.x, pt.y);
}

```

```
(-3, -4)
```

This code is exactly equivalent to the last example, but a lot simpler and
easy to read.  This can be especially useful when dealing with structs that
contain pointers to other structs, in which case the operator can be
applied twice.

### Problem

Make a structure with a field for an array of integers and a size, along with functions to zero it out, find its average via a pointer to it.

Answer: 

```c
// snippets/staticallySizedArrayStructure.c

#include <stdio.h>

struct SizedArray {
    int size;
    int data[100];
};

void zeroOutArray(struct SizedArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = 0;
    }
}

double findArrayAverage(struct SizedArray *arr) {
    int sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->data[i];
    }
    return (double)sum / arr->size;
}

int main() {
    int arraySize = 5;
    struct SizedArray myArray = {arraySize, {1, 3, 5, 7, 9}};

	printf("Initially: \n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    double average = findArrayAverage(&myArray);
    printf("Average: %.2f\n", average);

	printf("Zeroing it out!\n");
    zeroOutArray(&myArray);

    printf("Array after zeroing: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    for (int i = 0; i < arraySize; i++) {
        myArray.data[i] = i + 1;
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    average = findArrayAverage(&myArray);
    printf("Average: %.2f\n", average);

    return 0;
}

```

What are some limitations with the above code?  Hint: look at the struct's array size!

## Arrays of Structures

There are two possible methods of handling a large number of related data.
Consider tracking a group of students, their name and their grade.  One
could store an array of names and an array of grades.  However this may
not be ideal since it requires the programmer to keep track of their order
and ensure that they always match.  An alternative method would be to put
the name and grade in a structure, and then create an array of structs.  This
method is demonstrated below.

```c
// snippets/arrayOfStruct.c

#include <stdio.h>

struct Student {
    char *name;
    int grade;
};

int main() {
    struct Student students[] = {
        {"Ross", 90},
        {"Cory", 65},
        {"Gordon", 80},
        {"Deborah", 100},
    };
    printf("%s's grade: %d\n", students[0].name, students[0].grade);
}

```

```
Ross's grade: 90
```

What if we don't know how many students are in the array?

```c
// snippets/arrayOfStructLoop.c

#include <stdio.h>

struct Student {
    char *name;
    int grade;
};

int main() {
    struct Student students[] = {
        {"Ross", 90},
        {"Cory", 80},
        {"Gordon", 80},
        {"Deborah", 100},
    };
    int n;
    int numStudents = sizeof(students) / sizeof(struct Student);
    for (n = 0; n < numStudents; n++) {
        printf("%s's grade: %d\n", students[n].name, students[n].grade);
    }
}

```

```
Ross's grade: 90
Cory's grade: 80
Gordon's grade: 80
Deborah's grade: 100
```

We can use a new unary operator, called `sizeof`.  This operator
yields the size of the object in bytes.  In order to get the number of objects
in the array, we simply divide the size of the overall array by the size of the objects
that compose it.  Note that this cannot be used to get the size of an array
passed into a function, as that is really a pointer, not an array.

### Problem

How can we sort the array by name, or by grade?  How can we sort it by grade
and then names on a tie?

Answer:

```c
// snippets/sortArrayStruct.c

#include <stdio.h>
#include <string.h>

struct Student {
    char *name;
    int grade;
};

void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
	*a = *b;
	*b = temp;
}

void sort(struct Student arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j].grade > arr[j + 1].grade) {
				swap(&arr[j], &arr[j + 1]);
			} else if (arr[j].grade == arr[j + 1].grade && strcmp(arr[j].name, arr[j + 1].name) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    struct Student students[] = {
        {"Ross", 90},
        {"Gordon", 80},
        {"Cory", 80},
        {"Deborah", 100},
    };
    int n;
    int numStudents = sizeof(students) / sizeof(struct Student);
	sort(students, numStudents);

    for (n = 0; n < numStudents; n++) {
        printf("%s's grade: %d\n", students[n].name, students[n].grade);
    }
}

```

## Self-referential Structures

As we showed before, structures can reference other structures, and in fact
they can even reference themselves.  They cannot literally contain one
of themselves, but they can contain a pointer to one of themselves.  We
demonstrated this by creating a "Node" struct which contains a pointer
to a node struct.

If you try to create a struct where a field is a structure of the same type:

```c
// snippets/selfReferenceBad.c

#include <stdio.h>

struct Node {
    int value;
    struct Node next;
};

int main() {
    struct Node n1 = {0, NULL};
    struct Node n2 = {0, &n1};
}

```

```
$ gcc snippets/selfReferenceBad.c
snippets/selfReferenceBad.c:5:17: error: field ‘next’ has incomplete type
	 struct Node next;
				 ^
```

If we do it with a pointer to a struct of the same type as a field:

```c
// snippets/selfReference.c

#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

int main() {
    struct Node n1 = {0, NULL};
    struct Node n2 = {0, &n1};
}

```

it compiles just fine!  This is because a struct in C must have a pre-defined size at compile time.  If a struct has a field of the same type, it creates a recursive definition, i.e. a struct can only be defined by having a full struct of the same type in it, which continues infinitely.  The pointer approach solves this, because pointers are a known size!  Pointers are typically either 4 or 8 bytes (which you can find out for yourself with `sizeof(*p_struct)`), which means the size is known at compile time this way!

Now consider a seemingly simple request.  Take a user input of words separated
by spaces and create a node for each one, linking them together.  With what
we have seen so far, it is only possible to create a fixed number of nodes
each of which must be declared explicitly.  This precludes us from doing
anything based on the user input as it may be of variable length.  This
brings us to an important built in C function.

## Memory Allocation

### `malloc`

In order to create objects based on user input, we need to do something called
"dynamically allocating memory".  This means that for once, the amount of space
we are going to use in a program is not known when we compile it.  This can
be achieved by using a built in C function called `malloc` (which is short for
*memory allocation*).  This function reserves a given amount of bytes for us, and
returns a void pointer to that location.  Let's look at a simple example of
using `malloc` to create a single Node.

```c
// snippets/basicMalloc.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    char *str;
};

int main() {
    struct Node *np = (struct Node *) malloc(sizeof(struct Node));
	if (np == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    np->str = "Hello";
    np->next = NULL;
    printf("(%p, %s)\n", np->next, np->str);
}

```

```
((nil), Hello)
```


Working from left to right of the malloc statement:
1. We are creating a pointer to a node
2. Because `malloc` returns a void pointer, we must cast as a node pointer
3. We specify the amount of bytes we want is the size of a node.

Note that we actually check the pointer returned by malloc for a `NULL`, because
if it returns a NULL pointer, our program will have undefined behavior attempting to access memory that was not allocated for you.  As discussed before, hopefully it crashes, but other unexpected behavior is possible.

Beause we have a pointer to a node, we use the arrow operator to set its
members.  Note that we initialize the `next` pointer to `NULL` to signal
that there is no next node.  Otherwise, later code may try to dereference
this next node and cause an error.

Now, let's take a look at a more complex case: creating a node for each user
input, and linking them together.

```c
// snippets/storeInput.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    char *str;
};

int main(int argc, char *argv[]) {
    struct Node n = {NULL, ""};
    struct Node *sp = &n; // Starting pointer
    struct Node *cp = &n; // Current pointer
    int i;
    for (i = 1; i < argc; i++) {
        // Initialize new Node
        struct Node *new = (struct Node *) malloc(sizeof(struct Node));
		if (np == NULL) {
			printf("Memory allocation failed!");
			return 1;
		}
        new->str = argv[i];
        new->next = NULL;
        // Set current pointer to next node
        cp->next = new;
        cp = cp->next;
    }
    // Print Nodes in order
    cp = sp;
    while (cp->next) {
        printf("(%p, %s)->", cp->next->next, cp->next->str);
        cp = cp->next;
    }
    printf("\n");
}

```

```
$ ./a.out word1 word2 word3 word4
(0x9db030, word1)->(0x9db050, word2)->(0x9db070, word3)->((nil), word4)->
```

Now this code might be very hard to understand, and very intimidating to a
beginner, so let's go through it in detail.

1. Create an initial "root" node with no data.
2. Store a "start" pointer to the root so we can always find it.
3. Store a "current" pointer for the node we are looking at.
4. Loop over all user inputs
    1. Create a new node
    2. Store the text in the "new" node
    3. Store a null pointer in the "new" node
    4. Set the "next" of the "current" node to the "new" node
    5. Set the "current" node to the "new" node.
5. Reset the "current" pointer to the "start" pointer.
6. While the "current" pointer has a valid "next" pointer:
    1. Print the contents of the "next" pointer.
    2. Set the "current" pointer to the "next" pointer.

What we have just created, is your first `data structure`, called a `linked list`.  As the name implies, rather than creating an array, we create this new structure of data where each element in our `list` is `linked` together by a pointer.  We will cover *why* this is useful later on as well as a few more data structures.  

Problem: Let's say we'd like to make a struct which has 2 fields, an array and a size for that array.  You'd want an function to create these structs, with function to zero out the array and find the average size of the elements by a pointer to the struct.  How would you do it?  This is an explicit part 2 to "Make a sized array structure, along with functions to zero it out, find its average via a pointer to it.

Answer: 

```c
// snippets/sizedArrayStruct.c

#include <stdio.h>
#include <stdlib.h>

struct SizedArray {
    int size;
    int *data;
};

struct SizedArray initializeSizedArray(int size) {
    struct SizedArray sizedArray;
    sizedArray.size = size;
    sizedArray.data = (int *)malloc(size * sizeof(int));
	if (sizedArray.data == NULL) {
		printf("Memory allocation failed!");
		return -1;
	}

    for (int i = 0; i < size; i++) {
        sizedArray.data[i] = 0;
    }

    return sizedArray;
}

void zeroOutArray(struct SizedArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        arr->data[i] = 0;
    }
}

double findArrayAverage(struct SizedArray *arr) {
    int sum = 0;
    for (int i = 0; i < arr->size; i++) {
        sum += arr->data[i];
    }
    return (double)sum / arr->size;
}

int main() {
    int arraySize = 5;
    struct SizedArray myArray = initializeSizedArray(arraySize);

	for (int i = 0; i < arraySize; i++) {
		myArray.data[i] = 2*i + 1;
	}

	printf("Initially: \n");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    double average = findArrayAverage(&myArray);
    printf("Average: %.2f\n", average);

	printf("Zeroing it out!\n");
    zeroOutArray(&myArray);

    printf("Array after zeroing: ");
    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    for (int i = 0; i < arraySize; i++) {
        myArray.data[i] = i + 1;
    }

    for (int i = 0; i < arraySize; i++) {
        printf("%d ", myArray.data[i]);
    }
    printf("\n");

    average = findArrayAverage(&myArray);
    printf("Average: %.2f\n", average);

    return 0;
}

```

At the top, we create a struct, but you can see the `data[]` is no longer a fixed size (100 in the last example), and is now stored as a pointer to an integer.  It can therefore store any number of elements, as long as you can allocate the space for it.  When we initialize a sized array struct, you can see we malloc an `integer pointer` of size `size * sizeof(int)`, which is exactly as many bytes as it would take to store that many integers!

### `free`

Now, it's not obvious that we did something wrong in the last 2 examples, both the linked list and the sized array examples.  But let's think about what we did: we asked our computer for a bunch of memory in which we can
store our nodes (or in the second case, stored our sized array elements).  We asked for it, and we never gave it back.  We could potentially keep asking for it over and over until our computer runs out of
memory or just refuses to give us more.  This will happen naturally if a
program which dynamically requests memory keeps running.

We can give the memory back to the computer with the `free` function.  The
`free` function is quite simple: it takes a pointer and returns nothing.  But
it has actually given all the memory we took for that particular pointer and
freed it, meaning it has given it back to the computer to use for other programs.
If you use `malloc` without a corresponding `free` that is called a **memory leak**
and that is typically very bad.

let's take a look at a simple example of using this.

```c
// snippets/free.c

#include <stdlib.h>
#include <stdio.h>

int main() {
    int *a = malloc(sizeof(int) * 8);
	if (a == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    a[7] = 5;
    printf("%d\n", a[7]);
    free(a); // 'a' is now a "Dangling Pointer"
    printf("%d\n", a[7]); // Anything could happen
    free(NULL); // Freeing a NULL pointer does nothing
}

```

There are several things to be careful about here I alluded to, but need to call out more specifically.  Malloc and free are 2 of the more complex parts of this course, and even in industry they can be surprisingly tricky to reason about.  Here are some of the risks to be aware of:

1. `Double free`.  This refers to attempting to call `free` on a pointer more than once.  This will cause undefined behavior, because the memory manager does not keep track of whether a particular block of memory has already been freed.
2. `Use after free`.  This refers to when you attempt to access the memory that has already been freed.  In practice, this will look very similar to accessing a pointer you didnt have access to (i.e. dereferencing a null or uninitialized pointer), in that it will cause unpredictable behavior (again, including data corruption or crashes).

### `realloc`

It is also a common operation to extend the amount of space you need.  One
simple way of achieving this would be to `malloc` a new larger size, then
copy all the contents of your smaller array into that, then free the original
array, and reset the original pointer to point to the new array.  However, 
this is a common enough operation that there is a built in function, `realloc`.

The `realloc` function finds enough space for your new size and copies over all
of your old stuff for you.  Here is an example:

```c
// snippets/reallocArray.c

#include <stdlib.h>
#include <stdio.h>

int main() {
    int *a = malloc(sizeof(int) * 8);
	if (a == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    a[7] = 5;
    a = realloc(a, sizeof(int) * 16);
    printf("%d\n", a[7]);
    a[15] = 15;
    printf("%d\n", a[15]);
}

```

```c
$ ./a.out
5
15
```

## Typedef

You may notice that the use of structures can become verbose since you always
have to type `struct` before using one.  One simple way to remedy this is
to use the built in `typedef` keyword.  A simple example given below uses
`typedef` to define a `String` as `char *`

```c
// snippets/basicTypedef.c

#include <stdio.h>
#include <stdlib.h>

typedef char *String;

struct Node {
    struct Node *next;
    String str;
};

int main() {
    struct Node *np = (struct Node *) malloc(sizeof(struct Node));
	if (np == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    np->str = "Hello";
    np->next = NULL;
    printf("(%p, %s)\n", np->next, np->str);
}

```

```
(0x0, Hello)
```

As mentioned however, this can also be applied to structs as demonstrated
below.

```c
// snippets/basicTypedefStructLong.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    char *str;
};

typedef struct Node Node;

int main() {
    Node *np = (struct Node *) malloc(sizeof(struct Node));
	if (np == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    np->str = "Hello";
    np->next = NULL;
    printf("(%p, %s)\n", np->next, np->str);
}

```

```
((nil), Hello)
```

In fact, we can even do one better.  We can both declare the struct and create the typedef in 1 line:

```c
// snippets/basicTypedefStruct.c

#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node *next;
    char *str;
};

typedef struct Node Node;

int main() {
    Node *np = (struct Node *) malloc(sizeof(struct Node));
	if (np == NULL) {
		printf("Memory allocation failed!");
		return 1;
	}
    np->str = "Hello";
    np->next = NULL;
    printf("(%p, %s)\n", np->next, np->str);
}

```

```
((nil), Hello)
```

You can see the code is quite a bit simpler.  Note that `typedef` does not
actually create a new type, but essentially only serves as another name for
an existing type.

## Unions

Sometimes you have need for a variable which can take on one of several types.
For instance, you might want to handle either integers or floating point
numbers in numeric algorithms.  Unions are almost the same as a struct,
except that instead of holding all of the types given, they hold one of them
at a given time.  They have similar syntax as well, which is demonstrated
below.

```c
// snippets/basicUnion.c

#include <stdio.h>
#include <stdlib.h>

typedef union Number {
    int intVal;
    double doubleVal;
} Number;

Number timesTwo(Number n, int type) {
    Number m;
    if (type == 0) {
        m.intVal = 2*n.intVal;
    } else {
        m.doubleVal = 2*n.doubleVal;
    }
    return m;
}

int main() {
    Number n;
    Number m;
    n.intVal = 7;
    m = timesTwo(n, 0);
    printf("%d\n", m.intVal);
}

```

```
14
```

Note that this code still has the drawback that we have to communicate the
type that we want to process as an argument.  This is because the underlying memory that backs the union is the size of the largest member.  If you store a smaller field in a larger one, you are actually just writing to the same memory address (but not completely using all allocated memory of that union).

You can work around this issue by including the type stored in the union as well as the union itself in the same structure, as below.

```c
// snippets/structUnion.c

#include <stdio.h>
#include <stdlib.h>

typedef struct Number {
    int type;
    union {
        int intVal;
        double doubleVal;
    } vals;
} Number;

Number timesTwo(Number n) {
    Number m;
    m.type = n.type;
    if (n.type == 0) {
        m.vals.intVal = 2*n.vals.intVal;
    } else {
        m.vals.doubleVal = 2*n.vals.doubleVal;
    }
    return m;
}

int main() {
    Number n;
    Number m;
    n.type = 0;
    n.vals.intVal = 7;
    m = timesTwo(n);
    printf("%d\n", m.vals.intVal);
}

```

```
14
```
