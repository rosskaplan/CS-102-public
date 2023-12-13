# Introduction to Python

## When to Use Python

Python is an *interpreted* language, meaning you do not have to compile your
program.  It is very easy to read and write Python code compared to most other
languages.  However this ease comes at some costs.  It does not have type safety,
and it is generally slow.

These downsides are often reduced by the fact that you can write performance or
safety critical code in other languages, and then use that code in Python.  One
place Python shines is it's *ecosystem* of support from open source communities.
For example, most machine learning and data science libraries target Python as
their main developer interface.

In short, you should use Python if you just need to get something done quickly,
as a prototype for a faster language, or if you need code that exists in the
Python ecosystem.

## Interpreted Languages

The first major difference between Python and C which makes it easier to use is
the fact that it is interpreted.  This convenience comes at the cost of speed.
Other interpreted languages you might need to learn in the future include
MATLAB and JavaScript.

## Type Safety

Python is about the least type safe as you can get.  There is absolutely no
type checking.  One moment a variable can be an integer and the next it can be a
float, and next it is a string.  There is no limit as to what a single variable
can represent.  There is some static type checking available through the *mypy*
library, however it is rarely used.

## Demonstration

You can bring up the Python *interpreter* by running `python` in bash, if you
have it installed.  Now let's see what we can do.

## Output

First, you can print to the screen with `print` (rather than `printf` as in C).
Below is a simple *hello world* program written in Python.

```py
# snippets/output.py

print('Hello, world')

```

## Basic Types

The built in Python types are fairly similar to the built in C types, but we do
get some more functionality as well.  Let's take a look.

### `int`

Integers are mostly the same in Python, with one beautiful exception: they never
overflow!  For example, take a look at the result of this operation which would
certainly overflow on any built in C integer:

```py
# snippets/bigint.py

print(99999999999999**99)

```

By the way, the `**` in that example is exponentiation.

### `float`

Floats again, are very similar to their C counterparts.  The exception is that
really there is no such thing as a 32-bit float in Python.  Everything is a
64-bit double.  That means they are still susceptible to underflow and overflow
just as they were in C.

```py
# snippets/float.py

print(1 / 2)
print(1e-456)
print(1e456)

```

Note that the above code will run differently depending on whether you are
running Python 2 or 3.  In Python 2 (now deprecated) the first print statement
will print 0, as it would in C.  However in Python 3 the division of two
integers yields a float by default.

### `str`

Unlike C, there is no `char` type in Python.  Everything is a string, so if you
want a single character, that is just a string of length 1.  Unlike C strings,
you usually do not have to deal with the dirty details of the string like the
null terminator, and there are several built in methods that can help you.
Also, unlike C strings (aside from string literals), Python strings are 
**immutable**.  This means once you create a string, you cannot change it.

```py
# snippets/my_string.py

string = 'Hello, world!'
print(string.endswith('world!'))
print(',' in string)
print(string[0:5])
print(string[-1])
print(string.split())

```

Formatting strings is way easier in Python.  Here are some different
ways you can format a string

```py
# snippets/format.py

age = 23
greeting = 'hi'
gpa = 3.0

str1 = greeting + ' I am ' + str(age) + ' years old and my gpa is ' + str(gpa)
print(str1)

str2 = '%s I am %s years old and my gpa is %s' % (greeting, age, gpa)
print(str2)

str3 = '{} I am {} years old and my gpa is {}'.format(greeting, age, gpa)
print(str3)

str4 = '{greeting} I am {age} years old and my gpa is {gpa}'.format(
        greeting=greeting, age=age, gpa=gpa)
print(str4)

str5 = f'{greeting} I am {age} years old and my gpa is {gpa}'
print(str5)

```

### Tuple

A tuple is similar to an array in C, with they key exception that it is
**immutable** (again meaning it can not be modified once created) and that
it can store any number of different types.

```py
# snippets/tuple.py

a = (1, '2', 3.0)
print(a)
print(a[1])

```

Note in the above case, the parentheses are not necessary,
the same program would work fine removing them.

```py
# snippets/tuplebad.py

a = (1, 2, 3)
a[1] = 3

```

One nice Python feature is tuple assignment.  If you have a
tuple containing N elements, you can easily assign the
values to N variables like so:

```py
# snippets/tupleassign.py

a, b, c = (1, 2, 3)
print(a)
print(b)
print(c)

```

This applies with any tuple stored in variables as well,
for example:

```py
# snippets/tupleassignvar.py

z = 1, 2, 3
a, b, c = z
print(a)
print(b)
print(c)

```

### None

The `None` type is very simple.  It does not hold any value
and you actually can't have a `None` object.  It is just the
type itself.  It is most similar to the `NULL` pointer in C.
You can use it to represent an empty or invalid result.
Usually one does not perform an operation on it, you just
check if something is `None`.  We will see some examples
later on.

### Pointers and Arrays

There are no pointers in Python!  That's right, the hardest part of C is just
not here.  They are working under the hood but they are virtually never exposed
in pure Python code.  That means with the above types, you can never have the
same kind of behavior you had in C of passing a pointer and modifying it.  We
can still emulate this behavior, but we will need either a class or one of the
following advanced types.

Arrays are technically present in Python, but they are so rarely used that we
will forego any explanation.

## Advanced Types

The types above will give you almost everything you had in C (except pointers)
but now we will go through some "advanced types" which give us even more power.
These are not actually advanced because they are very commonly used in Python,
they just have no C alternative.

### List

Lists are the typical replacement of arrays in C, but they are much more
powerful.  Here is a simple example.

```py
# snippets/list.py

a = [] # Create an empty list
print(a)
a.append(3.14)
print(a)
a.append(1)
print(a)
a.sort()
print(a)
b = a * 2
print(b)
z = [1] * 10 # Create a list of 10 ones
print(z)
r = list(range(10)) # Create a list of 0-9
print(r)
print(sum(r))
print(sum(r)/len(r)) # Get the average
r.reverse()
print(r)
print(max(r))
print(min(r))

```

### Set

A set is a data structure that allows very quick look up for elements.  It has
similar semantics as a list, except it is unordered and faster in most cases.

```py
# snippets/sets.py

a = set(range(100)) # create a set of numbers 1-100
print(a)
print(50 in a)
print(200 in a)
a.remove(50)
a.add(200)
print(50 in a)
print(200 in a)
x = set(range(75)) # Create a set of numbers from 0 to 74
y = set(range(50, 100)) # Create a set of numbers from 50 to 100
print(x.intersection(y)) # Get the numbers that are in boths sets
print(x.union(y)) # Get the numbers that are in either set

```

Here is a speed comparison between a set and a list for looking up a number.

```
python3 -m timeit --setup 'a = set(range(100000))' '50000 in a'
5000000 loops, best of 5: 48.6 nsec per loop
```

```
python3 -m timeit --setup 'a = list(range(100000))' '50000 in a'
500 loops, best of 5: 727 usec per loop
```

As you can see, for a large list of integers, the set lookup (48.6 nanoseconds)
is much much faster than a list lookup (727 microseconds) by a factor of 15000!

Here we used the example of integers, but sets work with almost any **basic**
data type, and they are especially useful with strings.  Note that they do
not work with advanced data types like lists, sets, and dictionaries.

```py
# snippets/setbad.py

a = set() # create an empty set
# These examples all give errors
a.add(list())
s.add(dict())
s.add(set())

```

Sets have no alternative in C, except if you code the data structure itself.
If you want to learn how a set works under the hood, take the data structures
and algorithms class.

### Dictionary (Hash Table)

A dictionary (which is really the more well-known "hash table") is very similar
to a set, except that a value is also stored along with the key.  The dictionary
is one of the most important and frequently used data structures in higher level
programming.  Here are some simple examples of its use in Python.

```py
# snippets/dictionary.py

classroom = {} # Create an empty dictionary (dict)
# Set values in the dict:
classroom['Cory'] = 80
classroom['Ross'] = 90
classroom['Gordon'] = 95
print(classroom)
# Get values in the dict:
print(classroom['Cory'])
print(list(classroom.items()))
print(list(classroom.keys()))
print(list(classroom.values()))
# Store a nested dict:
classroom = dict() # Create an empty dictionary (dict)
classroom['Cory'] = {'Grades': [75, 85, 95]}
classroom['Ross'] = {'Grades': [75, 85, 95, 100]}
classroom['Gordon'] = {'Grades': [95, 95]}
# Nested access
print(classroom)
print(classroom['Ross']['Grades'][-1]) # Get the last grade of Ross

```

As with the set, getting and setting elements is very quick for a `dict`.

## Control Flow

Python has many of the same exact control flow patterns as C, though they are a
bit easier to read and often not even necessary to accomplish a task.  Python
has something called **comprehensions** for replacing simple loops.  A
comprehension is almost always preferable to a loop if you can get away with
it, so where possible, we will show the alternative comprehension.

### If Statement

The `if` statement works the same as in C, but it is written
quite differently.  Let's take a look at a simple example.

```py
# snippets/if1.py

if 3 > 2:
    print('3 > 2?')
    print('duh')
else:
    print('???')

```

The first difference is is that the condition, `3 > 2` does
not need to be surrounded with parentheses, though that would
be valid too.

The second difference is that a colon `:` is required after
the condition.

The third difference is that you don't need curly braces `{}`
even for multiple lines.

In Python, unlike C, whitespace actually matters and changes
the meaning of the program.  Python does not use braces `{}`
to group code, and instead relies on the amount of
indentation.

### For Loop

Lets start with a simple motivating problem.  We want to create a list of
the first 10 positive square numbers.  In C, you would create an array of size
10, loop from 1 to 10 and store the square of the loop index in the array.
In Python you can it this way:

```py
# snippets/for1.py

lst = [0] * 10 # Create 10 zeros
for n in range(1, 11): # Loop from 1 to 10
    lst[n-1] = n*n

print(lst)

```

You could also create an empty list and add elements as you go

```py
# snippets/for2.py

lst = [] # Create an empty list
for n in range(1, 11): # Loop from 1 to 10
    lst.append(n*n)

print(lst)

```

The reason our last for loop repeated `lst.append(n*n)` but
not `print(lst)` is only because the former was indented under
the loop.  See what happens when we fail to indent properly:

```py
# snippets/for2bad.py

lst = [] # Create an empty list
for n in range(1, 11): # Loop from 1 to 10
    lst.append(n*n)

    print(lst)

```

This example can most easily be done with exactly equivalent
comprehension:

```py
# snippets/for3.py

lst = [n*n for n in range(1, 11)]

print(lst)

```

This comprehension would certainly be prefered as it is less code and more
easily readable.

### Nested For Loop

Just as in C we can have nested for loops, we can have them in Python as well
with the predictable syntax.  Let's take a look at an example that produces
coordinate tuples in list of lists.

```py
# snippets/nestedfor1.py

import pprint

a = []
for m in range(5):
    a.append([])
    for n in range(5):
        a[m].append((m, n))

pprint.pprint(a)

```

Here we are using a list of lists to simulate a 2D array.  We could also create
an array of zeros and then fill in each value rather than appending, like this:

```py
# snippets/nestedfor2.py

import pprint

a = [[0]*5, [0]*5, [0]*5, [0]*5, [0]*5]
for m in range(5):
    for n in range(5):
        a[m][n] = (m, n)

pprint.pprint(a)

```

Finally, we could also use a nested list comprehension.

```py
# snippets/nestedfor3.py

import pprint

a = [[(m, n) for n in range(5)] for m in range(5)]

pprint.pprint(a)

```

At this point, some may consider the comprehension harder to read than the nested
for loop, but it does save a decent amount of lines.  It is a matter of taste
on which one you should use.

### Continue and Break

The keywords `continue` and `break` carry over with the same exactly behavior
as in C.

This example shows how can you can use `continue` to create a
list of filtered elements.  We add elements from 0 to 99 if
the element is not divisible by any element less

```py
# snippets/continue.py

lst = []

for x in range(100):
    if x % 3 or x % 5 == 0:
        continue
    lst.append(x)

print(lst)

```

We can achieve similar behavior with a list comprehension as
well.

```py
# snippets/listfilter.py

lst = [x for x in range(100) if x % 3 != 0 and x % 5 != 0]

print(lst)

```

Here we use break to find the solution to an equation.

```py
# snippets/break.py

for n in range(100):
    if (n * 342) % 333 == 243:
        break

print(n)

```

Python has an additional, very minor, control flow feature
which is uncommon to other languages.  You can actually attach
an `else` at the end of a `for` loop.  According to the Python
developers, they wished they had called it `ifnobreak` because
that is exactly how it works.  The code inside the `else` on
a `for` loop will trigger if the for loop did not exit via
`break`.  We could use this to detect if we did not find a
solution in the last problem.  For example:

```py
# snippets/forelse.py

for n in range(100):
    if (n * 342) % 333 == 242:
        print(n)
        break
else:
    print('No solution')

```

### While Loop

While loops are basically the same as in C.  Here is a simple
example that counts the number of steps of the Collatz process
to reach 1.  (Minor note: we use `//` here to perform an
integer division which ensures the result will be an integer)

### Functions

Functions are similar to their conterparts in C, but they have
a lot more power.  Lets look at a simple example that just
returns the sum of two numbers.

```py
# snippets/function1.py

def plus(a, b):
    return a + b

print(plus(3, 4))

```

The first major difference you'll notice is that you don't
need to have any types associated with the arguments to the
function, or the output.  However, you could add optional
type hints if you want (but they won't do anything).

```py
# snippets/function_type_hint.py

def plus(a: int, b: int) -> int:
    return a + b

print(plus(3, 4))

```

One nice feature of Python is the ability to return multiple
outputs from a function.  Technically this is not a feature
of functions, but the feature of assigning tuple values to
variables that we saw before.  Let's take a look:

```py
# snippets/function_return_multi.py

def pythag(maxval):
    for a in range(1, maxval):
        for b in range(1, maxval):
            for c in range(1, maxval):
                if a**2 + b**2 == c**2:
                    return (a, b, c)

    return (None, None, None)

a, b, c = pythag(10)
print(a, b, c)

```

Note that this is a case where the `None` type is useful
to signal to the caller that a solution could not be found.
In this example we check for that case:

```py
# snippets/function_return_none.py

def pythag(maxval):
    for a in range(1, maxval):
        for b in range(1, maxval):
            for c in range(1, maxval):
                if a**2 + b**2 == c**2:
                    return (a, b, c)

    return (None, None, None)

a, b, c = pythag(5)
if a is None:
    print('No solution')
else:
    print(a, b, c)

```

Note that when checking for `None` values, we use the keyword
`is` rather than `==`.  This just checks that the object is
literally exactly the same as the `None` value.  Normally it
will not make a difference, but it is technically possible
for a custom class to implement custom behavior when comparing
to the `None` value.

#### Varadic Functions

In programming, a **varadic function** is a function which
may take any number of sequential inputs.  For example, let's
say we want to write a function which sums all of its inputs.
This can be done like this:

```py
# snippets/varadic_1.py

def sum_inputs(*args):
    total = 0
    for arg in args:
        total += arg

    return total

my_sum = sum_inputs(1, 2, 3)
print(my_sum)

```

You do not have to use the name `args`, you can make that any name you want.
The way this works is that all of the values you feed are put into a list
with the name `args` and you can use that however you want.

This could also be used to ignore or collect extra inputs.

```py
# snippets/varadic_2.py

def add(a, b, *args):
    return a + b

my_sum = add(1, 2, 3)
print(my_sum)

```

This can be useful if you are trying to make multiple functions
that have a compatible interface (meaning they can take the same
number of inputs)

You can also use lists to supply the arguments to a function.

```py
# snippets/varadic_3.py

def add(a, b):
    return a + b

summands = [1, 2]
my_sum = add(*summands)
print(my_sum)

```

This can be useful for programatically grouping and supplying arguments.

#### Keyword Arguments to Functions

Sometimes functions can take a lot of arguments and it can get
confusing at a first glance as to what argument corresponds
to what parameter.  **Keyword Arguments** allow the programmer
to specify an argument by name rather than by position.  For
example:

```py
# snippets/kwargs_1.py

def divide(top, bottom):
    return top / bottom

result = divide(1, 5)
print(result)
result = divide(top=1, bottom=5)
print(result)
result = divide(bottom=5, top=1)
print(result)

```

In case you want to force yourself or another programmer to use
keyword arguments with your function (to avoid common mistakes)
you can place a `*` before the arguments (notice the error).

```py
# snippets/kwargs_2.py

def divide(*, top, bottom):
    return top / bottom

result = divide(1, 5)
print(result)

```

You can automatically gather extra keyword arugments similar to
how you can gather extra positional arguments with `*args` by
using `**kwargs`.  Note again there is nothing special about
the name `kwargs` but it is very commonly used for this case.

```py
# snippets/kwargs_3.py

def divide(**kwargs):
    return kwargs['top'] / kwargs['bottom']

result = divide(top=1, bottom=5)
print(result)

```

Similar to how you can use `*args` when supplying an input
to a function, you can also use `**kwargs` if you want to
supply a dictionary as the input to a function.

```py
# snippets/kwargs_4.py

def divide(top, bottom):
    return top / bottom

kwargs = {'top': 1, 'bottom': 5}
result = divide(**kwargs)
print(result)

```

Combining keyword arugments along with varadic functions, we
can create a function that takes any input at all.

```py
# snippets/kwargs_5.py

def anything(*args, **kwargs):
    for arg in args:
        print(arg)
    for key, value in kwargs.items():
        print(key, ':', value)

anything(1, 'hello', 5.3, boo='!', whatever=[])

```

We will see later on this pattern is very useful when trying
to modify or extend existing functions, because you can feed
anything into this function that you can into any other function.

### Recursion

Recursion works similarly to C.  Here is a simple Fibonacci
example.

```py
# snippets/fibonacci.py

def fib(n):
    if n == 0 or n == 1:
        return 1
    else:
        return fib(n-1) + fib(n-2)

for n in range(10):
    print(fib(n))

```

However there is one weakness: There is a fairly low limit to
how many times you are allowed to recurse in Python.  Usually
only up to a depth of around 1000.  For example:

```py
# snippets/recurse_limit.py

def count(n):
    if n == 0:
        return 0
    else:
        return 1 + count(n-1)

print(count(100))
print(count(1000))

```

### Control Flow Conclusion

That all covers basic control flow in Python.  Just to show
a quick example of more meaningful code, here is the
`mandelbrot` assignment re-written in Python.

```py
# snippets/mandelbrot.py

def in_mandelbrot_set(c):
    x = 0
    for n in range(100):
        x = x*x + c
        if abs(x) > 2:
            return False

    return True

def visualize():
    dx = 0.03125;
    dy = 0.0625;
    for n in range(-16, 16+1):
        for m in range(-64, 16+1):
            if in_mandelbrot_set(m*dx + 1j*n*dy):
                print('*', end='')
            else:
                print(' ', end='')
        print();

visualize()
```

## Advanced Functions

All of that covered the basic control flow we had in C, but
there is even more available in Python.  In particular,
we can do a lot more with functions.

### Functions as Arguments

Similar to C, we can pass functions as arguments to other functions, but the
syntax is a lot simpler in Python.  Watch this:

```py
# snippets/functional_1.py

def add_one(x):
    return x + 1

def apply_function(f, lst):
    length = len(lst)
    for n in range(length):
        lst[n] = f(lst[n])

lst = [1, 2, 3]
print(lst)
apply_function(add_one, lst)
print(lst)

```

### Lambdas

In case we don't have a function readily defined, we can use **lambda** to 
define one on the spot.

```py
# snippets/lambda_1.py

def apply_function(f, lst):
    length = len(lst)
    for n in range(length):
        lst[n] = f(lst[n])

lst = [1, 2, 3]
print(lst)
apply_function(lambda x: x + 1, lst)
print(lst)

```

There is basically no difference in doing this compared to defining a function
beforehand, it's just convenient.

```py
# snippets/lambda_2.py

import pprint
lst = [
    {'name': 'zachary', 'grade': 70},
    {'name': 'cory', 'grade': 80},
    {'name': 'deborah', 'grade': 100},
    {'name': 'ross', 'grade': 90},
    {'name': 'gordon', 'grade': 85},
]
print('Unsorted')
pprint.pprint(lst)
lst.sort(key=lambda record: record['grade'])
print('Sorted by grade')
pprint.pprint(lst)
lst.sort(key=lambda record: record['name'])
print('Sorted by name')
pprint.pprint(lst)
print('Highest Grade')
pprint.pprint(max(lst, key=lambda record: record['grade']))
print('First Name (Alphabetically)')
pprint.pprint(min(lst, key=lambda record: record['name']))

```

You will often see this in the context of some built in functions:

```py
# snippets/lambda_3.py

import pprint
lst = [
    {'name': 'cory', 'grade': 80},
    {'name': 'deborah', 'grade': 100},
    {'name': 'ross', 'grade': 90},
    {'name': 'gordon', 'grade': 85},
]
print('Unsorted')
pprint.pprint(lst)
lst.sort(key=lambda record: record['grade'])
print('Sorted by grade')
pprint.pprint(lst)
lst.sort(key=lambda record: record['name'])
print('Sorted by name')
pprint.pprint(lst)

```

### Functions as Return Values

We can also create or modify functions and then use or return them.
For example, we can create a function that takes in any other function
as a parameter and then returns a function which does the same thing,
and also prints the time it took to run.

```py
# snippets/functional_2.py

import time

def timed(f):
    def wrapper(*args, **kwargs):
        t1 = time.time()
        retval = f(*args, **kwargs)
        t2 = time.time()
        print(f'Calling "{f.__name__}" took {t2-t1} seconds')
        return retval
    return wrapper

def wait(seconds):
    print('waiting')
    time.sleep(seconds)
    print('done waiting!')

timed_wait = timed(wait)

timed_wait(0.1)
timed_wait(0.2)
timed_wait(0.3)

```

This is fairly common for some Python programs, so there is even a
special syntax for doing it:

```py
# snippets/functional_3.py

import time

def timed(f):
    def wrapper(*args, **kwargs):
        t1 = time.time()
        retval = f(*args, **kwargs)
        t2 = time.time()
        print(f'Calling "{f.__name__}" took {t2-t1} seconds')
        return retval
    return wrapper

@timed
def wait(seconds):
    print('waiting')
    time.sleep(seconds)
    print('done waiting!')

timed_wait(0.1)
timed_wait(0.2)
timed_wait(0.3)

```

The `@` basically says to do something like `wait = timed(wait)` just after the
definition.  A function like this, which takes a function and returns a
function is called a **decorator**.

### Generators

In Python, there is a special type of object called a **generator function**.  A
generator function is like a function, except that it maintains state between
calls.  It can maintain data like variables, and even what line of code it
exited from.  It will return to that line of code when you call it again.

Here is a simple generator which counts to 3.

```py
# snippets/generator.py

def count_to_3():
    yield 1
    yield 2
    yield 3

generator = count_to_3()
print(next(generator))
print(next(generator))
print(next(generator))

```

Instead of `return`, you give a value back with `yield`.  You can see that
every time you call `next` on a generator it advances to the next `yield`
statement.  If you go too far, you will get an error.

```py
# snippets/generator_wrong.py

def count_to_3():
    yield 1
    yield 2
    yield 3

generator = count_to_3()
print(next(generator))
print(next(generator))
print(next(generator))
print(next(generator))

```

You can convert any generator into a plain old list by using `list`.

```py
# snippets/generator_list.py

def count_to_3():
    yield 1
    yield 2
    yield 3

generator = count_to_3()
print(list(generator))

```

You can do basically anything you can do with a normal function, and even
create multiple instances of a generator at once:

```py
# snippets/generator_wee.py

def count_to_n(n):
    for i in range(n):
        yield i

generator_10 = count_to_n(10)
generator_100 = count_to_n(100)
print(list(generator_10))
print(list(generator_100))
print(list(generator_10))

```

Just be careful!  Generators come with a huge warning.  Once you've used a value,
that's it.  You cannot get it back again it is forever gone.  That is why when
we print `list(generator_10)` a second time, it is empty.

## Input and (File) Output

You can get command line arguments and inputs by using `sys.argv`.
Here is a simple program that echos the user input back to them
separated by newlines.

### Command Line Input

```py
# snippets/input_1.py

import sys

for arg in sys.argv:
    print(arg)

```

You can get interactive user input with the `input` function.

```py
# snippets/input_2.py

name = input('Enter your name: ')
print(f'Hello, {name}')

```

### File Input

You can read files by using the `open` keyword.

```py
# snippets/input_3.py

opened_file = open('README.md')

content = opened_file.read()

print(f'Number of characters: {len(content)}')
words = content.split()
print(f'Number of words: {len(words)}')
lines = content.split('\n')
print(f'Number of lines: {len(lines)}')
print(f'Number of unique words: {len(set(words))}')

opened_file.close()

```

It is generally good practice to close a file after you are done
using it.  This is so other programs can get access to it.  It
is a common mistake to forget to close it, so in Python you can
using something called a **context manager** which will close it
for you.

```py
# snippets/input_4.py

with open('README.md') as opened_file:
    content = opened_file.read()
    print(f'Number of characters: {len(content)}')
    words = content.split()
    print(f'Number of words: {len(words)}')
    lines = content.split('\n')
    print(f'Number of lines: {len(lines)}')
    print(f'Number of unique words: {len(set(words))}')

```

### File Output

You can write to files in a similar way as you read from them.

```py
# snippets/output_1.py

with open('output.txt', 'w') as opened_file:
    opened_file.write('Hello, ')
    opened_file.write('world')
    opened_file.write('!')

with open('output.txt') as opened_file:
    print(opened_file.read())

```

## Classes

### Basic Example

Classes in Python are similar to classes in C++, just with some different
syntax and more freedom.  You can define a new class by using the `class`
keyword, and create a new instance (object) by "calling" it with parentheses.
Here is a simple example.

```py
# snippets/class_1.py

class Foo():
    pass

foo = Foo()

print(foo)

```

### Methods

Methods of classes can defined the same way functions can.  Just make sure
they are indented and within in your class definition.  One major difference
between Python and C++ (and more languages) is that in Python, the reference
to the object (the `this` keyword in C++) is implicitly provided as an input
to every method.  Here is an example demonstrating this

```py
# snippets/method.py

class Foo():
    def print_hi(self):
        print('hi')

foo = Foo()
foo.print_hi()

```

The name `self` is not special, you could technically put anything there, but
the name `self` is the convention and there is no reason to stray from it.
You must explicitly type `self` as the first input of every method (with few
exceptions we will talk about later)

Here is an example of a common mistake.  Forgetting to write `self` as the first
argument leads to an error because the method is implicitly called with `foo` as
the first argument but as defined the method takes zero arguments.

```py
# snippets/method_wrong.py

class Foo():
    def print_hi():
        print('hi')

foo = Foo()
foo.print_hi()

```

### Constructor

You can create a constructor for a class by implementing the special
`__init__` method.  The double underscores preceding and following `init`
can be pronounced **dunder**, so we can pronounce this as **dunder init**.
This method is known as a **magic method** because it is typically not
called explicitly.  Here is an example of a simple constructor.

```py
# snippets/constructor.py

class Foo():

    def __init__(self, x):
        self.x = x

    def print_x(self):
        print(self.x)

foo = Foo(5)
foo.print_x()

```

Note that as with other methods, `self` is the first argument.  We can
use `self` to add data to the object.  In this cases we added some 
arbitrary `x` value, and then we can reference it later in `print_x`

### Destructor

You don't really have to write destructors in Python because memory is
mostly handled for you.  However the option is there with the magic method
`__del__` which we can see implemented here

```py
# snippets/destructor.py

class Foo():

    def __init__(self, x):
        self.x = x

    def print_x(self):
        print(self.x)

    def __del__(self):
        print('I am being destroyed')

foo = Foo(5)
foo.print_x()
print('getting rid of foo')
foo = 1
print('got rid of foo')

```

You can see that we never explicitly delete the object like in C++, we just
set the variable name containing that object to another variable and Python is
smart enough to destroy the object when it sees we may no longer reference it.

### Static Methods

If the method you are writing does not need a reference to the object calling it,
but you want to logically group it with your class, you can use the `@staticmethod`
decorator to avoid passing `self` like this:

```py
# snippets/staticmethod.py

class Foo():
    @staticmethod
    def print_hi():
        print('hi')

foo = Foo()
foo.print_hi()
Foo.print_hi()

```

In this case, you should consider whether it makes sense to just move the
function out of the class, since it has the same effect.

### Class Methods

If you want to write a method which creates an instance of your class with
some special logic, you can use a `@classmethod`.  In a class method, the
class of the object will be implicitly given as the first paremeter, rather
than the object itself.  This can useful for creating classes from some
other common objects with some additional logic.  Here is an example.

```py
# snippets/classmethod.py

class Foo():
    def __init__(self, one, two, three):
        self.one = one
        self.two = two
        self.three = three

    def print_all(self):
        print(self.one, self.two, self.three)

    @classmethod
    def make_foo_from_list(cls, lst):
        return cls(lst[0], lst[1], lst[2])

foo = Foo.make_foo_from_list(['a', 'b', 'c'])
foo.print_all()

```

### Abstract Methods

Python has **abstract base classes** and **virtual functions**, almost the same
as in C++ but under some new syntax and naming.  Here is an example that
implements an abstract base class with one virtual function (now called an
abstract method)

```py
# snippets/abstractmethod.py

import abc # abstract base class

class Foo(abc.ABC):
    @abc.abstractmethod
    def print_me():
        pass

foo = Foo()

```

You can see if we try to create an instance of an abstract base class that
has an abstract method, we get an error, as we did in C++.  We can fix this
by creating a new class and **inheriting** from the base class, implementing
the method.

```py
# snippets/abstractmethod_correct.py

import abc # abstract base class

class Foo(abc.ABC):
    @abc.abstractmethod
    def print_me(self):
        pass

class XBar(Foo):
    def __init__(self, x):
        self.x = x

    def print_me(self):
        print(self.x.lower())

class YBar(Foo):
    def __init__(self, y):
        self.y = y

    def print_me(self):
        print(self.y.upper())

xbar = XBar('xyz')
ybar = YBar('xyz')
xbar.print_me()
ybar.print_me()

```

### Inheritance

Inheritance works pretty much the same as in C++, let's take a look at an example.

```py
# snippets/inheritance.py

import abc # abstract base class

class Foo():
    def print_hi(self):
        print('hi')
    def print_bye(self):
        print('bye')

class Bar(Foo):
    def print_hi(self):
        print('hello there')

foo = Foo()
foo.print_hi()
foo.print_bye()
bar = Bar()
bar.print_hi()
bar.print_bye()

```

You can use the `super` keyword to call a parent method, when implementing a new
version of that method.  For example, let's say we wanted to extend a class's
constructor to take an additional parameter but otherwise do the same stuff.

### Other Magic Methods

There are a ton of other magic methods that Python lets you override in your
classes.  Here we will go over an example with a couple, but there are a lot
more.


```py
# snippets/dunder.py

class Interval():
    def __init__(self, start, end):
        self.start = start
        self.end = end

    def __repr__(self):
        return f'{self.start} -> {self.end}'

    def __str__(self):
        return f'{self.start} -> {self.end}'

    def __contains__(self, element):
        return bool(self.start < element < self.end)

    def __iter__(self):
        return iter(range(self.start, self.end + 1))

    def __mul__(self, other):
        return Interval(max(self.start, other.start), min(self.end, other.end))

    def __nonzero__(self):
        return bool(len(self))

    def __len__(self):
        return self.end - self.start

foo = Interval(5, 9)
bar = Interval(7, 11)
empty = Interval(7, 7)
print(foo)
print(6 in foo)
print(list(foo))
print(foo * bar)
print(len(empty))
print(bool(empty))

```

## Modules

### Importing

There are several ways to import code from another file.

1. `import x`

```py
# snippets/simple_import.py

import pprint

lst = [[(y, x) for x in range(5)] for y in range(5)]
print(lst)
pprint.pprint(lst)

```

In this case you will always be importing a module object, which you can then
use by accessing its members

2. `import x as y`

```py
# snippets/alias_import.py

import pprint as pp

lst = [[(y, x) for x in range(5)] for y in range(5)]
print(lst)
pp.pprint(lst)


```

This is the same, except you can give it a new name.  This can be helpful if
two custom modules happen to have the same name, or you want a shorter name.

3. `from x import y`

```py
# snippets/from_import.py

from pprint import pprint

lst = [[(y, x) for x in range(5)] for y in range(5)]
print(lst)
pprint(lst)

```

This imports a specific thing (could be a variable, object, function, class,
whatever) from the given module.

4. `from x import y as z`

```py
# snippets/from_alias_import.py

from pprint import pprint as pp

lst = [[(y, x) for x in range(5)] for y in range(5)]
print(lst)
pp(lst)


```

This does the same but gives it a new name.

### Modules

Look here for a full list of built in Python modules:
`https://docs.python.org/3/py-modindex.html`

Most modules are useuless to you, so we will go over some common and useful
ones.

#### `copy`

```py
# snippets/my_copy.py

import copy

def append_one_in_place(lst):
    lst.append(1)
    return lst

def append_one_to_copy(lst):
    lst = copy.copy(lst)
    lst.append(1)
    return lst

def append_one_to_first_elem(lst):
    lst[0].append(1)
    return lst

a = [3, 2]
b = append_one_in_place(a)
print(a)
print(b)

a = [3, 2]
b = append_one_to_copy(a)
print(a)
print(b)

a = [[0]]
b = append_one_to_first_elem(a)
print(a)
print(b)

```

#### `math`

```py
# snippets/my_math.py

import math

print(math.ceil(0.3))
print(math.comb(10, 3))
print(math.factorial(100))
print(math.gcd(7*11, 3*7))
print(math.sqrt(2))
print(math.prod(range(1,101)))
print(math.log(math.exp(2)))

```

#### `random`

```py
# snippets/my_random.py

import random

between_1_and_10 = random.randint(1, 10)
print(between_1_and_10)
between_0_and_1 = random.uniform(0, 1)
print(between_0_and_1)
a_b_or_c = random.choice(['a', 'b', 'c'])
print(a_b_or_c)

```

#### `collections`

```py
# snippets/my_collections.py

import collections
import string
import random

rs = ''.join(random.choices(string.ascii_lowercase, k=1000))
# Create a count of each unique element
count = collections.Counter(rs)
print(count.most_common())
# You can access it like a dictionary
print(count['z'])

dd = collections.defaultdict(list)
dd['new_key'].append(1)
dd['new_key'].append(2)
dd['new_key_2'].append(0)
print(dict(dd))

```

#### `enum`

```py
# snippets/my_enum.py

import enum

class Mode(enum.Enum):
    READ = 1
    WRITE = 2
    EXECUTE = 3

r = Mode.READ
w = Mode.WRITE
e = Mode.EXECUTE

print(r, w, e)

```

#### `functools`

```py
# snippets/my_functools.py

import functools

def add(a, b):
    return a + b

add_one = functools.partial(add, b=1)
print(add_one(4))


@functools.lru_cache(maxsize=128)
def fib_cached(n):
    if n in (0, 1):
        return 1
    else:
        return fib_cached(n-1) + fib_cached(n-2)

def fib(n):
    if n in (0, 1):
        return 1
    else:
        return fib(n-1) + fib(n-2)

print('running fib cached')
print(fib_cached(100))
print('running fib')
print(fib(34))

```

#### `heapq`

```py
# snippets/my_heapq.py

import heapq

h = []
heapq.heappush(h, 2)
heapq.heappush(h, 1)
heapq.heappush(h, 3)
heapq.heappush(h, -1)

print(heapq.heappop(h))
print(heapq.heappop(h))
print(heapq.heappop(h))
print(heapq.heappop(h))


```

#### `itertools`

```py
# snippets/my_itertools.py

import pprint
import itertools

pprint.pprint(list(itertools.product([0, 1, 2], [0, 1, 2])))
pprint.pprint(list(itertools.product([0, 1, 2], repeat=3)))
pprint.pprint(list(itertools.product(['a', 'b', 'c'], [1, 2, 3])))

pprint.pprint(list(itertools.permutations('aabc')))
pprint.pprint(list(itertools.combinations('aabc', 3)))

```

#### `json`

```py
# snippets/my_json.py

import json

lst = [
    {'name': 'cory', 'grade': 80},
    {'name': 'deborah', 'grade': 100},
    {'name': 'ross', 'grade': 90},
    {'name': 'gordon', 'grade': 85},
]

stringified = json.dumps(lst)

print(lst)
print(stringified)
print(lst[0])
print(stringified[0])

objectified = json.loads(stringified)

assert objectified == lst

```

#### `logging`

```py
# snippets/my_logging.py

import logging

# This is the only way you should ever ever ever make a logger
logger = logging.getLogger(__name__)

# Will not print anything
logger.info('Here is a an info log')
logger.warning('Here is a warning log')

log_format = '%(asctime)-15s %(message)s'
logging.basicConfig(format=log_format, level=logging.INFO)

# Will print something
logger.info('Here is a an info log')

```

#### `os`

```py
# snippets/my_os.py

import os

files = os.listdir('.')

print(files)
print(os.getenv('HOME'))

```

#### `re`

```py
# snippets/my_re.py

import re

pattern = ' [0-9].[0-9][0-9] '
string = '$123.0 1.23 12.23'
matches = list(re.finditer(pattern, string))
print(matches)

pattern = '[0-9]'
string = '$123.0 1.23 12.23'
new_string = re.sub(pattern, '#', string)
print(new_string)

pattern = '^[a-zA-Z]+ [a-zA-Z]+$'
print(re.match(pattern, 'Cory Charles Nezin'))
print(re.match(pattern, 'Cory Nezin'))

```

### Packages

#### PIP

You can install other people's code by using `pip`

#### NumPy

```
python -m pip install numpy
```

```py
# snippets/my_numpy.py

import numpy as np

A = np.arange(12).reshape(4,3)
B = np.arange(12).reshape(3,4)

prod = A.dot(B)

print(prod)

```

#### Matplotlib

```
python -m pip install matplotlib
```

```py
# snippets/my_matplotlib.py

import numpy as np
import matplotlib.pyplot as plt

# Time from 0s to 5s in 0.2s intervals
t = np.arange(0.0, 5.0, 0.2)
plt.plot(t, t, 'r--', t, t**2, 'b--', t, t**3, 'g--')
plt.show()

```

#### Requests

```
python -m pip install requests
```

```py
# snippets/my_requests.py

import requests

resp = requests.get('http://google.com')

print(resp.content)

```
