# Data Representation (Reading Binary)

This section gives a brief discussion of how data on a computer is typically
stored, and how we can insert that data into our program.

-------------------------------------------------------------------------------
## Binary

Every piece of data, including the code you write, is stored in the computer as
bits.  A bit is an abstract piece of data represented by a 1 or 0.  Typically
the physical implementation of a bit is a voltage level coming from tiny
devices in your computer.  These devices vary even within a single computer.
The fastest devices for reading and writing bits are the transistors in your
CPU.  The next fastest are the capacitors in your RAM.  The next fastest are
the magnets in your harddrive.  The next fastest is on the internet or
network.

It's all right if that is gibberish to you.  If you'd like to learn more about
all of that, you should take a computer architecture class.  You won't be
needing it here.

It might not seem like you can do a lot with just ones and zeros, but it turns
out you can represent almost basically anything your heart desires.

-------------------------------------------------------------------------------
## Unsigned Integers
Numbers are the first obvious item of interest.  You are used to base 10
(meaning 10 symbols, 0 through 9) but computers obviously prefer base 2
(meaning 2 symbols, 0 and 1).  So how do we represent the numbers we know and
love?  Well let's see if you can find the pattern.

0 and 1 are represented the same as in base 10, 2 is where things get
interesting.  Just as when we get to 10 in base 10, we have to add another
digit when we get to 2 in base 2, giving us the digits one zero.  Here is
a short table of numbers in their decimal and binary representation.

| 0 | 1 | 2  | 3  | 4   | 5   | 6   | 7   |
|---|---|----|----|-----|-----|-----|-----|
| 0 | 1 | 10 | 11 | 100 | 101 | 110 | 111 |

The method of finding the value of an N bit binary number in decimal goes like
this.

1. Number the bits from 0 at the right to N minus 1 at the left
2. For every bit, if it is 1, add 2 to the power of its number otherwise add 0

This method is summarized in this table for finding the decimal value of the
binary integer `10011001` to its decimal representation, `153`.

| `n`       | 7   | 6  | 5  | 4  | 3 | 2 | 1 | 0 | sum |
|:----------|----:|---:|---:|---:|--:|--:|--:|--:|----:|
| `2^n`     | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | 255 |
| `bit`     | 1   | 0  | 0  | 1  | 1 | 0 | 0 | 1 | N/A |
| `2^n*bit` | 128 |    |    | 16 | 8 |   |   | 1 | 153 |

A similar algorithm applies for a decimal number, except you add the digit
times 10 to the power of its number.  Can you generalize this to other
bases?  

**Question: What are the maximum and minimum representable values for an 8-bit
number using this scheme?**

This means if you are using an **unsigned** 8 bit integer, you cannot store a 
larger value than that.  We will see how to get these values in code in a little bit!

Now the question arises, given a decimal number how can we convert it to a
binary number?  The answer is the following method:

1. Start with your value and check the largest value of 2^N
2. If 2^N can be subtracted from your value, subtract it and write down a 1
otherwise move on and write a 0
3. Continue until you reach zero.

In a single sentence: subtract the largest powers of 2 you can and count those
as ones in the binary number.  The following is a table showing this process.

| `n`                 |   7 |  6 |  5 |   4 |  3 |  2 |  1 |   0 | - |
|---------------------|----:|---:|---:|----:|---:|---:|---:|----:|---|
| `2^n`               | 128 | 64 | 32 |  16 |  8 |  4 |  2 |   1 | - |
| fits into remaning? | yes | no | no | yes | yes | no | no | yes | - |
| `bit`               |   1 |  0 |  0 |   1 |  1 |  0 |  0 |   1 | - |
| subtract            | 128 |  0 |  0 |  16 |  8 |  0 |  0 |   1 | - |
| remaining           | 153 | 25 | 25 |  25 |  9 |  1 |  1 |   1 | 0 |

Note that there are more efficient ways to perform the same conversion, but
this is the simplest to understand and do by hand.

-------------------------------------------------------------------------------
## Signed Integers
This is all well and good for positive numbers, but how about negative?
Usually we add a minus sign, but computers only have ones and zeros.  Your
first reaction might be to add another bit to the left and maybe 0 would
represent positive and 1 would represent negative.  Or maybe add an extra bit
to the left and then flip all of the bits if it's negative.  These methods
are called signed magnitude representation and one's complement.  We won't
talk about those because they have some problems and they are rarely used
anymore.  The main representation used now adays is called two's complement.

With two's complement, we add a bit to the left and assign it a numerical value
just like all the other bits.  What value should we assign to make things 
roughly symmetric?  If we give it the value of negative two times the next
largest value, we can represent everything from that negative number to our
original largest value.  Here we demonstrate the conversion of the same number
as before, except we interpret it as a two's complement representation

| `n`                |    7 |  6 |  5 |  4 | 3 | 2 | 1 | 0 |  sum |
|:-------------------|-----:|---:|---:|---:|--:|--:|--:|--:|-----:|
| `2^n(*-1 if n==7)` | -128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 |  255 |
| `bit`              |    1 |  0 |  0 |  1 | 1 | 0 | 0 | 1 |  N/A |
| `2^n*bit`          | -128 |    |    | 16 | 8 |   |   | 1 | -103 |

Note that the process is entirely the same, except for how we interpret the
leftmost bit.  You could also see this as finding the regular value, and
then subtracting 256 (`2^N`).

**Question: What is the maximum representable values for an 8-bit
number using this scheme?**

**Question: What is the minimum representable value for an 8-bit
number using this scheme?**

Interestingly, note that the largest negative number is 1 greater in magnitude than the
largest positive number for signed integers.

-------------------------------------------------------------------------------
## Characters

Characters are similar to numbers.  In fact, you can think of each character as
being represented by a number.  One very common and very basic format is called
ASCII.  Typically any text files on your computer, including code, are stored
in this format.  You may be able to run `man ascii` and get a nice chart of
numbers and their corresponding letters.  Make sure to scroll down to the
decimal set.  Otherwise you can see a table here.  ASCII uses 7 bits to
represent many english characters.  For more complex character sets, UTF8 is
common, though you won't need to know about it here.

|     |         |     |       |     |       |     |       |     |       |     |       |     |       |     |       |
|----:|---------|----:|-------|----:|-------|----:|-------|----:|-------|----:|-------|----:|-------|----:|-------|
|   0 | `nul`   |   1 | `soh` |   2 | `stx` |   3 | `etx` |   4 | `eot` |   5 | `enq` |   6 | `ack` |   7 | `bel` |
|   8 | `bs`    |   9 | `ht`  |  10 | `nl`  |  11 | `vt`  |  12 | `np`  |  13 | `cr`  |  14 | `so`  |  15 | `si`  |
|  16 | `dle`   |  17 | `dc1` |  18 | `dc2` |  19 | `dc3` |  20 | `dc4` |  21 | `nak` |  22 | `syn` |  23 | `etb` |
|  24 | `can`   |  25 | `em`  |  26 | `sub` |  27 | `esc` |  28 | `fs`  |  29 | `gs`  |  30 | `rs`  |  31 | `us`  |
|  32 | `sp`    |  33 | `!`   |  34 | `"`   |  35 | `#`   |  36 | `$`   |  37 | `%`   |  38 | `&`   |  39 | `'`   |
|  40 | `(`     |  41 | `)`   |  42 | `*`   |  43 | `+`   |  44 | `,`   |  45 | `-`   |  46 | `.`   |  47 | `/`   |
|  48 | `0`     |  49 | `1`   |  50 | `2`   |  51 | `3`   |  52 | `4`   |  53 | `5`   |  54 | `6`   |  55 | `7`   |
|  56 | `8`     |  57 | `9`   |  58 | `:`   |  59 | `;`   |  60 | `<`   |  61 | `=`   |  62 | `>`   |  63 | `?`   |
|  64 | `@`     |  65 | `A`   |  66 | `B`   |  67 | `C`   |  68 | `D`   |  69 | `E`   |  70 | `F`   |  71 | `G`   |
|  72 | `H`     |  73 | `I`   |  74 | `J`   |  75 | `K`   |  76 | `L`   |  77 | `M`   |  78 | `N`   |  79 | `O`   |
|  80 | `P`     |  81 | `Q`   |  82 | `R`   |  83 | `S`   |  84 | `T`   |  85 | `U`   |  86 | `V`   |  87 | `W`   |
|  88 | `X`     |  89 | `Y`   |  90 | `Z`   |  91 | `[`   |  92 | `\`   |  93 | `]`   |  94 | `^`   |  95 | `_`   |
|  96 | `` ` `` |  97 | `a`   |  98 | `b`   |  99 | `c`   | 100 | `d`   | 101 | `e`   | 102 | `f`   | 103 | `g`   |
| 104 | `h`     | 105 | `i`   | 106 | `j`   | 107 | `k`   | 108 | `l`   | 109 | `m`   | 110 | `n`   | 111 | `o`   |
| 112 | `p`     | 113 | `q`   | 114 | `r`   | 115 | `s`   | 116 | `t`   | 117 | `u`   | 118 | `v`   | 119 | `w`   |
| 120 | `x`     | 121 | `y`   | 122 | `z`   | 123 | `{`   | 124 | `\|`  | 125 | `}`   | 126 | `~`   | 127 | `del` |

Let's go through some simple conversion examples.

-------------------------------------------------------------------------------
Say someone gives you the binary number `00110101`.  First, convert it to an
integer with the method we discussed earlier, `1 + 4 + 16 + 32 = 53`.  Now
check your handy ASCII table and find that this number corresponds to the
character "5".  Note that this is different than the number 5 which has a
binary representation of `00000101`!

-------------------------------------------------------------------------------
Now how would you find the binary representation of the letter "A"?  Just do
the same in reverse.  Looking up the letter "A" in the ASCII table gives
us `65`.  Converting to binary is relatively easy here.  The largest power
of 2 that fits is 64 (`2^6`), leaving 1 (`2^0`) so the binary representation
is `01000001`.

There you have it, you know know how to read and write letters in binary.

**Question: What binary number represents the character '0'?**

-------------------------------------------------------------------------------
## Floating Point Numbers

Now, there is one more basic kind of number that has a non-obvious
representation, numbers with decimal points.  The main method we will use to
represent these numbers is called "floating point".  This is very similar to
scientific notation.  For example consider the number `1.9e-3` (or `1.9` times
`10` to the `-3`).  While this number can be interpreted as the decimal number
`0.0009`, we can encode its value using only the integers `9` and `-3` (with 1
being implied).  Note how the number to the right of the `e` only serves to
move around the decimal.  This is what is meant by "floating" point.

The formula for a standard floating point number is 
`(-1)^s * 2^(e-127) * (1 + m)`

where:
* `s` is the sign bit, interpreted as an unsigned number
* `e` is the exponent bits, interpreted as an unsigned number
* `m` is the mantissa bits, interpreted as a fraction

to interpret a binary number as a fraction, we follow a similar procedure
to interpreting it as an unsigned integer, except the power of 2 we multiply by
are negative powers, i.e. 0.5, 0.25, 0.125, and so on.  This allows us to
represent values between 0 and 1.  We can also just compute the integer as
normal and then multiply by `2^-N` where N is the number of bits.

**Question: Can you prove that the method of computing the integer and then
multiplying by 2^-N works?**

In the standard 32-bit floating point format, 1 bit is given for the sign, 8
bits are given for the `exponent` (note that the `e` now represents an exponent
of 2 rather than 10) and the remaining 23 bits are given to the `mantissa`

The exact format is typically `[1-sign bit][8-exponent bits][23 mantissa bits]`

Let us take the binary sequence `01000000010010010000111111011011` as an
example.

First break it up into its components:

`0 10000000 10010010000111111011011`

From this,

* `s` is `0`
* `e` is `128`
* the unsigned interpretation of `m` is 4788187, meaning the fraction
interpretation is `4788187 * 2^-23` giving us a value of about `0.5707963`

Plugging this into our formula above, we get 
`(-1)^0 * 2^(128-127) * (1 + 0.5707963) = 3.1415926...`

**Question: Do you see any problems that may arise in floating point?**

## Octal and Hexadecimal

Other common formats are octal and hexadecimal.  These are number systems which
use 8 and 16 symbols respectively, instead of 2 as in binary.  They are
sometimes used to write down numbers in computer science because they are more
compact.  For instance, the binary number `110111010011` is the same as the
octal number `6723`.  Note that you can easily convert between binary and octal
by converting 3 bits at a time to one octal digit:
`110 111 010 011 -> 6 7 2 3`.  In C, you can represent octal numbers with a
leading `0`:

```c
// code/octal.c

#include <stdio.h> /* printf */

int main() {
	printf("06723 = %d\n", 06723);
}

```

```
06723 = 3539
```

Hexadecimal is even more compact, and you can convert 4 binary digits to one
hexadecimal digit.  For example `1101 1101 0011 -> 13 13 3 -> dd3`.  In C,
you can represent hexadecimal numbers with a leading `0x`

```c
// code/hexadecimal.c

#include <stdio.h> /* printf */

int main() {
    printf("0xdd3 = %d\n", 0xdd3);
}

```

```
0xdd3 = 3539
```

-------------------------------------------------------------------------------
# Conclusion

Now that you are armed with knowledge of the fundamental interpretations of
data, we are well prepared to move toward actually using and manipulating these
values in C.
# Variables and Types

This section discusses variables and types.

-------------------------------------------------------------------------------
## Variables

Variables are a fundamental unit of computing.  They are similar, though not
exactly the same as variables from mathematics.  In mathematics, a variable
might be used to represent some unknown.  For example, given an equation, solve
for the variable x.

In computing, on the other hand, the value of a variable
must always be known.  It is only a way of attaching a name to data.

-------------------------------------------------------------------------------
In C, all variables must be declared before being used.  This is an example of
several valid declarations in C.

```c
// snippets/variables.c

#include <stdio.h> /* printf */

int main() {
    int no_value;
    int variable = 0;
    int _variable = 1;
    int my_variable_2 = 2;
    int myVariable3 = 3;
    float pi = 3.14;
}

```

-------------------------------------------------------------------------------
Here are some examples of declarations that are NOT valid.  Any program
including any of these would fail to compile.

```c
// snippets/invalid.c

#include <stdio.h> /* printf */

int main() {
    // None of these declarations are valid
    int 1variable;
    int var!able;
    int my variable;
    int if;
    int void;
    int default;
}

```

```
snippets/invalid.c:5:9: error: expected identifier or '('
    int 1variable;
        ^
snippets/invalid.c:6:12: error: expected ';' at end of declaration
    int var!able;
           ^
           ;
snippets/invalid.c:7:11: error: expected ';' at end of declaration
    int my variable;
          ^
          ;
snippets/invalid.c:8:9: error: expected identifier or '('
    int if;
        ^
snippets/invalid.c:9:9: error: cannot combine with previous 'int' declaration specifier
    int void;
        ^
snippets/invalid.c:9:5: warning: declaration does not declare anything [-Wmissing-declarations]
    int void;
    ^~~~~~~~
snippets/invalid.c:10:9: error: expected identifier or '('
    int default;
        ^
1 warning and 6 errors generated.
```

-------------------------------------------------------------------------------
Basically, your variable can be any permutation of letters, digits, and
underscores, so long as it does not start with a digit, and it is not a
reserved word.  The reserved words of C are shown here.  They all have
special functions which we will learn about later.

```
break else long switch case enum register typedef char extern return union
const float short unsigned continue for signed void default goto sizeof
volatile do if static while
```

-------------------------------------------------------------------------------
While this gives us a lot of possibilities, you should always ask whether you
should before you ask whether you can.  What follows is a quote from "The C
Programming Language" by Brian Kerninghan and Dennis Ritchie.

*It’s wise to choose variable names that are related to the purpose of the
variable, and that are unlikely to get mixed up typographically. We tend to use
short names for local variables, especially loop indices, and longer names for
external variables*

Naming is mundane, but extremely important in all of programming.  You should
err on the side of caution toward longer more descriptive variable names.

-------------------------------------------------------------------------------
# Types

Types are almost as prevalent as variables in programming.  In C, every
variable has a type.  It is there for your own safety, to ensure that you only
do things that you are allowed to do with the data stored in a variable.

Please note that many types do not have standard definition in terms of the
amount of storage provided for them.  In the following descriptions, I will do
my best to tell you the most restrictve scenario, which is typically what you
should design for if you want your program to work across multiple systems.

-------------------------------------------------------------------------------
There are quite few types in C, making it easy to learn all of them.  The
fundamental types are: char, int, float, and double.

* char
* int
* float
* double

-------------------------------------------------------------------------------
## Chars

A char represents a character, like 'A', '0' or hyphen for example.  Note that
if they are declared with a value, that value must be surrounded with single
quotes, not double quotes.

```c
// snippets/chars.c

#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {
    char a = 'A';
    char b = '0';
    char c = '-';
    printf("char [min] = %d\n", CHAR_MIN);
    printf("char [max] = %d\n", CHAR_MAX);
}

```

```
char [min] = -128
char [max] = 127
```

-------------------------------------------------------------------------------
## Ints

An int is used to represent an integer like -30, 12 or 1e5.

```c
// snippets/ints.c

#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {
    int a = -30;
    int b = 12;
    int c = 1e5;
    printf("int [min] = %d\n", INT_MIN);
    printf("int [max] = %d\n", INT_MAX);
}

```

```
int [min] = -2147483648
int [max] = 2147483647
```

-------------------------------------------------------------------------------
## Floats

A float is used to represent non integer numbers like -2.7, 5.3, or 2e-6

```c
// snippets/floats.c

#include <float.h> /* FLT_MAX, FLT_EPSILON, DBL_MAX, DBL_EPSILON, LDBL_MAX
                      LDBL_EPSILON */
#include <stdio.h> /* printf */

int main() {
    float a = -2.7;
    float b = 5.3;
    float c = 2e-6;
    printf("float [max] = %g\n", FLT_MAX);
    printf("float [min] = %g\n", FLT_MIN);
    printf("float [epsilon] = %g\n", FLT_EPSILON);
}

```

```
float [max] = 3.40282e+38
float [min] = 1.17549e-38
float [epsilon] = 1.19209e-07
```

-------------------------------------------------------------------------------
## Doubles

Finally, a double is like a float but it is more precise and takes up more
space.  We will look at the difference in more depth shortly.

```c
// snippets/doubles.c

#include <float.h> /* FLT_MAX, FLT_EPSILON, DBL_MAX, DBL_EPSILON, LDBL_MAX
                      LDBL_EPSILON */
#include <stdio.h> /* printf */

int main() {
    double a = -2.7;
    double b = 5.3;
    double c = 2e-6;
    printf("double [max] = %g\n", DBL_MAX);
    printf("double [min] = %g\n", DBL_MIN);
    printf("double [smallest] = %g\n", DBL_EPSILON);
}

```

```
double [max] = 1.79769e+308
double [min] = 2.22507e-308
double [smallest] = 2.22045e-16
```

-------------------------------------------------------------------------------
## Type Modifiers

Type modifiers allow us to give more detail as to how we want our variable
to be treated and how much space we get for it.  The type modifiers in C
are short, long, signed, and unsigned.

* short
* long
* signed
* unsigned

-------------------------------------------------------------------------------
Some examples of valid usage are given here.  They can be used by placing them
before the type, and other modifiers, but not every modifier is applicable to
every type.

```c
// snippets/modifiers.c

#include <stdio.h> /* printf */

int main() {
    signed char a = 'a';
    short int b = 32767;
    long int c = 2147483647;
    signed int d = -1;
    unsigned int e = 1;
    long double f = 12345.67890;
}

```

-------------------------------------------------------------------------------
### Signed and Unsigned

The signed and unsigned modifiers can be applied only to chars and integers.
Signed means that the value can be negative, and unsigned means it can only be
positive.  By default chars can be either signed or unsigned depending on the
machine.  However, integers are always signed by default.

A char is always one byte, or 8 bits.  Therefore, Unsigned chars can hold
values in the range of 0 to 255, while signed chars can hold values on the
range of -127 to 127.

Signed integers have at least 2 bytes or 16 bits.  Therefore, they can hold
values at least in the range of -32,767 to 32,767.  Unsigned integers have the
same nubmer of bits and therefore can store any value in the range of 0 to
65,635.

|      | bits | signed          | unsigned   |
|------|------|-----------------|------------|
| char | 8    | [-128, 127]     | [0, 255]   |
| int  | 16   | [-32768, 32767] | [0, 65635] |

```c
// snippets/signed_vs_unsigned.c

#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       INT_MIN, INT_MAX */
#include <stdio.h> /* printf */

int main() {
    printf("signed char [min] = %d\n", SCHAR_MIN);
    printf("signed char [max] = %d\n", SCHAR_MAX);
    printf("unisgned char [min] = %u\n", 0);
    printf("unisgned char [max] = %u\n", UCHAR_MAX);

    printf("signed int [min] = %d\n", INT_MIN);
    printf("signed int [max] = %d\n", INT_MAX);
    printf("unisgned int [min] = %u\n", 0);
    printf("unisgned int [max] = %u\n", UINT_MAX);
}

```

```
signed char [min] = -128
signed char [max] = 127
unisgned char [min] = 0
unisgned char [max] = 255
signed int [min] = -2147483648
signed int [max] = 2147483647
unisgned int [min] = 0
unisgned int [max] = 4294967295
```

-------------------------------------------------------------------------------
### Short and Long

The short and long modifiers can be applied only to integers and doubles,
though a long double is relatively rare.  Note that in the case of integers,
one may apply the long modifier up to two times, and combine it with the signed
or unsigned modifiers.

Short integers have at least 2 bytes and are guaranteed to have equal or fewer
bytes than an int.  This means that short integers can hold values at least in
the range -32,767 to 32,767.  Long integers have at least 4 bytes, and long
long integers have at least 8 bytes.  The resulting maximum values are shown
in the table.

Finally, a long double typically has more precision than a double, but the
exact size is not specified in the C standard.  This means it is implementation
dependent but typically ranges from 10 to 16 bytes.  The math for determining
its range is harder than the math for integers, and we won't go through it
here.

|               | bits | min value            | max value           | smallest difference |
|---------------|------|----------------------|---------------------|---------------------|
| short int     | 16   | -32768               | 32767               | 1                   |
| long int      | 32   | -2147483647          | 2147483647          | 1                   |
| long long int | 64   | -9223372036854775807 | 9223372036854775807 | 1                   |
| long double   | 128  | -1.18973e+4932       | 1.18973e+4932       | 1.0842e-19          |

```c
// snippets/short_vs_long.c

#include <float.h> /* LDBL_MAX, LDBL_EPSILON */
#include <limits.h> /* CHAR_BIT, SCHAR_MIN, SCHAR_MAX, CHAR_MIN, CHAR_MAX
                       SHRT_MIN, SHRT_MAX, INT_MIN, INT_MAX, LONG_MIN,
                       LONG_MAX LLONG_MIN, LLONG_MAX */
#include <stdio.h> /* printf */

int main() {
    printf("short int [min] = %d\n", SHRT_MIN);
    printf("short int [max] = %d\n", SHRT_MAX);
    printf("long int [min] = %ld\n", LONG_MIN);
    printf("long int [max] = %ld\n", LONG_MAX);
    printf("long long int [min] = %lld\n", LLONG_MIN);
    printf("long long int [max] = %lld\n", LLONG_MAX);

    printf("long double [max] = %Lg\n", LDBL_MAX);
    printf("long double [min] = %Lg\n", LDBL_MIN);
    printf("long double [smallest] = %Lg\n", LDBL_EPSILON);
}


```

```
short int [min] = -32768
short int [max] = 32767
long int [min] = -9223372036854775808
long int [max] = 9223372036854775807
long long int [min] = -9223372036854775808
long long int [max] = 9223372036854775807
long double [max] = 1.18973e+4932
long double [min] = 3.3621e-4932
long double [smallest] = 1.0842e-19
```

# `printf`

Here we have been using `printf` but not paying much attention to it.  `printf`
lets us actually see the data we are manipulating and so it is important to
take a moment and figure out how it works.

One thing you should notice about `printf` is that we actually have to specify
the type that we are giving it.  The reason we have to tell it the type
explicitly is because it is not able to figure out the type of a variable
itself.  This is because is is `varadic` meaning we can feed any number of
variables of different types, and it doesn't know them beforehand.

A helpful table, adapted from 
[cplusplus.com][http://www.cplusplus.com/reference/cstdio/printf/]
is show below.  There are a few more data types we have not yet covered that
are there, which we will cover in the future when they come up.

| Specifier | Output                                             | Example      |
|-----------|----------------------------------------------------|--------------|
| d or i    | Signed decimal integer                             | 392          |
| u         | Unsigned decimal integer                           | 7235         |
| o         | Unsigned octal                                     | 610          |
| x         | Unsigned hexadecimal integer                       | 7fa          |
| X         | Unsigned hexadecimal integer (uppercase)           | 7FA          |
| f         | Decimal floating point, lowercase                  | 392.65       |
| F         | Decimal floating point, uppercase                  | 392.65       |
| e         | Scientific notation (mantissa/exponent), lowercase | 3.9265e+2    |
| E         | Scientific notation (mantissa/exponent), uppercase | 3.9265E+2    |
| g         | Use the shortest representation: %e or %f          | 392.65       |
| G         | Use the shortest representation: %E or %F          | 392.65       |
| a         | Hexadecimal floating point, lowercase              | -0xc.90fep-2 |
| A         | Hexadecimal floating point, uppercase              | -0XC.90FEP-2 |
| c         | Character                                          | a            |

Also, so far, we've seen examples where we print using %d.  However there are actually
a handful of optional `format tags` you can provide as well to influence the output.
The exact format it accepts is `%[flags][width][.precision][length]`.  Let's peek at each one:

The flags permit:
- '-', for left justify (right justify is the default)
- '+', for forcing the output to be preceeded by a + or - sign (for positive and negative numbers)
- ' ', for inserting a space before the value for padding
- '#', for forcing integers to be printed with 0, 0x or 0X respecrively for non-zero octal and hex values
- '#', (same character) for forcing floats and exponents to be printed with a decimal point
- '0', for forcing the output to be padded with preceeding 0's.

The width field permits:
- A number, for how many characters to print at minimum, padding with blanks if needed
- * for permitting a second value to be passed to printf which accepts the width as a variable

The precision field permits the same values as the with (but with a . before it) which, for integers, specifies the minimum number of digits to be printed, preceeded by zeros if too short.  For floats and doubles this is the number of digits to be printed after teh decimal point (default 6).

Lastly, the length field permits: modifiers such as `l` for `long`, `ll` for `long long`, `u` for `unsigned` and so on.  An example from 
[cplusplus.com][http://www.cplusplus.com/reference/cstdio/printf/]
is (slightly modified and) shown below.

```c
// snippets/printf.c

#include <stdio.h> /* printf */

int main()
{
   printf ("Characters: %c %c \n", 'a', 65);
   printf ("Decimals: %d %ld\n", 1977, 650000L);
   printf ("Preceding with blanks: %10d \n", 1977);
   printf ("Preceding with zeros: %010d \n", 1977);
   printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
   printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
   printf ("Width trick: \'%*d\' \n", 5, 10);
   printf ("%s \n", "A string");
   return 0;
}

```

```
Characters: a A 
Decimals: 1977 650000
Preceding with blanks:       1977 
Preceding with zeros: 0000001977 
Some different radices: 100 64 144 0x64 0144 
floats: 3.14 +3e+00 3.141600E+00 
Width trick: '   10'
A string 
```

-------------------------------------------------------------------------------
# Conclusion

This is a lot to information to absorb.  Lucky for you, all of this information
is built into the C language itself.  Use the built in constants in the code
examples in this chapter, and find more in these excellent documentation pages:

* [limits.h][http://www.cplusplus.com/reference/climits/]
* [float.h][http://www.cplusplus.com/reference/cfloat/]

-------------------------------------------------------------------------------

# Operators and Expressions

This section discusses operators and expressions.

Operators are special symbols which produce some result given 1, 2, or 3
values.  They are usually similar to the operators you would see on a four
function calculator, for example `+ - * /` are all operators in C, and they
behave similar to how you might expect.

Unary operators act on 1 operand
Binary operators act on 2 operands
Ternary operators act on 3 operands

-------------------------------------------------------------------------------
## Binary Operators

### Addition (`+`)

This is an example of a addition of two integers:

```c
// snippets/addition.c

#include <stdio.h> /* printf */

int main() {
    int a = 3;
    int b = 4;
    int c = a + b;
    printf("%d + %d = %d\n", a, b, c);
}

```

```
3 + 4 = 7
```

Pretty straightforward right?  Ok, let's look at one more example

```c
// snippets/overflow_addition.c

#include <stdio.h> /* printf */

int main() {
    short a = 30000;
    short b = 30000;
    short c = a + b;
    printf("%d + %d = %d\n", a, b, c);
}

```

```
30000 + 30000 = -5536
```

Huh...  That's weird.

### Overflow

You should remember from the last section that short integers typically can't
hold values greater than `32,767`.  Here we tried to add two short integers to
a value larger than the maximum.  C does not cause any errors in this case, it
merely plays along, and adds them as it would normally.  Except in this case,
there is a carry at the end that the variable simply as no space for, and it
discards it.  This is called overflow.  You should notice then that the result
isn't completely random.  The result is what happens when you add the numbers
normally, except that past 32,767 it loops around to `-32,768`.

However when dealing with signed ints this behavior is not defined in the
standard, and a different compiler on a different machine may produce a
different result!  

```c
// snippets/overflow_addition_exact.c

#include <stdio.h> /* printf */

int main() {
    short a = 32767;
    short b = 1;
    short c = a + b;
    printf("%d + %d = %d\n", a, b, c);
}

```
```
32767 + 1 = -32768
```

However, the behavior is well defined for unsigned integers
meaning you can count on an unsigned integer wrapping to `0` when you exceed
it maximum value via addition.

```c
// snippets/overflow_addition_unsigned.c

#include <stdio.h> /* printf */

int main() {
    unsigned short a = 65535;
    unsigned short b = 1;
    unsigned short c = a + b;
    printf("%d + %d = %d\n", a, b, c);
}


```

```
65535 + 1 = 0
```

In this course, it will generally be okay to use long integers and hope for the
best.

**Question: Can you write code to check if an overflow will occur before
actually performing an addition?**

In fact, in C23, the version of C released in 2023, they added a new standard header file `stdckdint.h` which contains functions that check if your addition, subtraction, or multiplication overflow.  This is outside the scope of this lesson as it requires concepts we'll cover in a few weeks!

### Suffixes

Overflow can also occur in more unexpected places, like the middle of an
expression.  Consider the following piece of code:

```c
// snippets/overflow_expression.c

#include <stdio.h> /* printf */

int main() {
    long long int i = 60000 * 60000;
    printf("%lld\n", i);
}

```

```
snippets/overflow_expression.c:4:29: warning: overflow in expression; result is -694967296 with type 'int' [-Winteger-overflow]
    long long int i = 60000 * 60000;
                            ^
1 warning generated.
```
While the result `3600000000` is representable by a `long long int`, it is not
representable by our machine's default `int`, resulting in overflow before the
actual assignment takes place.  This can be fixed by explicitly saying that
the constants are of type `long int` with suffixes:

```c
// snippets/overflow_expression_fixed.c

#include <stdio.h> /* printf */

int main() {
    long long int i = 60000L * 60000L;
    printf("%lld\n", i);
}

```

```
3600000000
```

The suffix `L` or `l` specifies that the constant is a `long int`
The suffix `LL` or `ll` specifies that the constant is a `long long int`
The suffix `F` or `f` specifies that the constant is a `float`

### Subtraction (`-`)

Subtraction works similar to addition, and has more or less the same overflow
potential.

### Multiplication (`*`)

This is an example of a multiplication of two integers:

```c
// snippets/multiplication.c

#include <stdio.h> /* printf */

int main() {
    int a = 3;
    int b = 4;
    int c = a*a + b*b;
    printf("%d*%d + %d*%d = %d\n", a, a, b, b, c);
}

```

```
3*3 + 4*4 = 25
```

As mentioned in the previous section, overflow is still an issue, and it is
even easier to overflow with multiplication.

```c
// snippets/multiplication_overflow.c

#include <stdio.h> /* printf */

int main() {
    short int a = 300;
    short int b = 400;
    short int c = a*a + b*b;
    printf("%d*%d + %d*%d = %d\n", a, a, b, b, c);
}

```

```
300*300 + 400*400 = -12144
```

**Question: In general, what is the maximum number of bits you would need to
store the product of two N-bit numbers? **

Multiplication of floating point numbers is similar.  While overflow is still a
possibility, it is less of a concern due to the large range of floating point
numbers.

### Division (`/`)

This is an example of division for two integers:

```c
// snippets/division_ints.c

#include <stdio.h> /* printf */

int main() {
    int dividend = 30;
    int divisor = 4;
    int quotient = dividend / divisor;
    int remaining = dividend - quotient * divisor;
    printf("%d / %d = %d\n", dividend, divisor, quotient);
    printf("%d = %d * %d + %d\n", dividend, divisor, quotient, remaining);
}

```

```
30 / 4 = 7
30 = 4 * 7 + 2
```

Note that if you divide two integers, the result itself is an integer, even
if the numbers do not divide evenly.  To find the remainder, subtract the
product of the divisor and the quotient from the dividend as in the code above.

This is an example of division for two floating point numbers:

```c
// snippets/division_floats.c

#include <stdio.h> /* printf */

int main() {
    float dividend = 77777.0;
    float divisor = 7.0;
    float quotient_a = dividend / divisor;
    float inverse = 1.0 / divisor;
    float quotient_b = dividend * inverse;
    printf("%.10f vs. \n%.10f\n", quotient_a, quotient_b);
}

```

```
11111.0000000000 vs. 
11111.0009765625
```

Huh...  That's weird.

### Floating Point Precision

You can see a strange result.  Even though the two quotients we produce here
should be mathematically they same, they differ.  The reason for this is that
in the second case, we try to store the value `1.0/77777.0`, but this number
is not representable in our format, similar to how `1/7` is not representable
in the decimal format without an infinite number of digits.

This shows an an important lesson: you should generally not check to see if
two floating point numbers are equal, but just that they are close enough, or
if their difference is small.

**Challenge: What kinds of fractions can be represented in finitely many
bits?**

### Remainder or Modulo (`%`)

If you want to get the remainder of a division without actually dividng the
numbers you can use the `%` (modulo) operator.  `a % b` finds the remainder of
`a` divided by `b`.  In most cases this is used to cap at some value create a
repeating sequence as demonstrated below:

```c
// snippets/modulo.c

#include <stdio.h> /* printf */

int main() {
    int a = 0 % 3;
    int b = 1 % 3;
    int c = 2 % 3;
    int d = 3 % 3;
    int e = 4 % 3;
    int f = 5 % 3;
    int g = 6 % 3;
    printf("%d, %d, %d, %d, %d, %d, %d\n", a, b, c, d, e, f, g);
}

```

```
0, 1, 2, 0, 1, 2, 0
```

### Assignemnt Operators

Sometimes you don't want to create a whole new value from an operator, you
only want to update an existing value, this is where assignment operators
come in.  Most binary operators have a corresponding assignment operator as
see in this code snippet.

```c
// snippets/assignment_operators.c

#include <stdio.h>

int main() {
    int x = 0;
    printf("x = %d\n", x);
    x = x + 2;
    printf("x = %d\n", x);
    x += 2;
    printf("x = %d\n", x);
    x *= 2;
    printf("x = %d\n", x);
    x /= 2;
    printf("x = %d\n", x);
}

```

```
x = 0
x = 2
x = 4
x = 8
x = 4
```

Note that an assignment operator is never necessary, and you can just about
always replace something like `x += 2` with something like `x = x + 2`.  It
is just a bit more concise and easy to follow.

### Relational Operators

Relational operators are used to compare two values.  They are similar to 
operators you are already familiar with from math, so we won't go into too much
depth on each one.

### Less Than (`<`)

```c
// snippets/less_than.c

#include <stdio.h> /* printf */

int main() {
    int x = 312;
    int y = 256;
    int xlty = x < y;
    int yltx = y < x;
    printf("xlty = %d\n", xlty);
    printf("yltx = %d\n", yltx);
}

```

```
xlty = 0
yltx = 1
```

From the example, we can see that the operator gives us a 1 if the condition
is true, and a 0 otherwise.  You can also check out the operators `> >= <=`

### Equality (`==`)

```c
// snippets/equality.c

#include <stdio.h> /* printf */

int main() {
    int x = 256;
    int y = 256;
    int z = 123;
    int xeqy = x == y;
    int xeqz = x == z;
    printf("xeqy = %d\n", xeqy);
    printf("xeqz = %d\n", xeqz);
}

```

```
xeqy = 1
xeqz = 0
```

We can also test for exact equality using the `==` operator as shown above.
Note it is a common mistake to use `=` when checking if two values are equal.
This is especially dangerous because it is not illegal to do so, as we will
speak about in the expressions section.  You can also try out the not equal
operator `!=`.

### Logical Operators (`||`, `&&`, `!`)

Logical operators allow us to combine multiple relations into a single truth
value.  For example we can check if a number is in a certain range like the
example below

```c
// snippets/logical.c

#include <stdio.h> /* printf */

int main() {
    int x = 256;
    int inRange = (x > 128) && (x < 512);
    int notInRange = !((x > 128) && (x < 512));
    printf("inRange = %d\n", inRange);
    printf("notInRange = %d\n", notInRange);
}

```

```
inRange = 1
notInRange = 0
```

- The `||` (called logical or) operator is true if either side is true.
- The `&&` (called logical and) operator is true if either both sides are true.
- The `!` (called not) operator is true if the following expression is false.

Note that the precedence (meaning the order in which the operators are applied)
is not usually very obvious, so you should generally add extra parentheses if 
you are unsure, as we did above.  We will give a brief overview of precedence
at the end of this section.

### Bitwise Operators (`|`, `&`, `^`, `<<`, `>>`, `~`)

Bitwise operators may be useful if you are trying to make code really fast.
However, I will warn you here that you are usually better off trying to avoid
them, as they often obscure the coder's intention.  A binary operator only 
looks at the raw binary of a value with no regard toward its type.

- The `|` (called bitwise or) operator returns the OR of each bit of both
  values
- The `&` (called bitwise and) operator returns the AND of each bit of both
  values
- The `^` (called bitwise xor) operator returns the XOR of each bit of both
  values
- The `<<` (called shift left) operator returns the same number, but with all
  bits shifted to the left
- The `>>` (called shift right) operator returns the same number, but with all
  bits shifted to the right
- The `~` (called complement) operator returns the same number, but with all
  bits flipped (0 becomes 1, 1 becomes 0)

A common mistake is to use these operators instead of the logical operators
when crafting an expression.  As a general rule unless you're trying to be
really (overly) clever or really need to optimize performance, use the logical operators, not bitwise!

Below shows a quick example of using the shift operators to multiply or divide
by 2.  Note that with modern optimization techniques, this would probably
not be much faster than explicitly multiplying or dividing by 2.

## Unary Operators

Unary operators take a single value and produce a single value.

### Negate

One very common unary operator is negation.  It is very intuitive, and you
would probably understand it without even seeing an example but I will give you
one anyway.

```c
// snippets/negate.c

#include <stdio.h> /* printf */

int main() {
    int x = 512;
    int y = -x;
    printf("x = %d\n", x);
    printf("y = %d\n", y);
}

```

```
x = 512
y = -512
```

As is expected, the value given is negated.  Just be careful not to use it with
unsigned values, or you may get strange results.

```c
// snippets/negate_unsigned.c

#include <stdio.h> /* printf */

int main() {
    unsigned int x = 512;
    unsigned int y = -x;
    printf("x = %u\n", x);
    printf("y = %u\n", y);
}

```

```
x = 512
y = 4294966784
```

### Increment and Decrement Operators

Another pair of common unary operators are the increment and decrement operators as
shown below:



```c
// snippets/increment_decrement.c

#include <stdio.h> /* printf */

int main() {
    int x = 0;
    printf("x = %d\n", x);
    x++;
    printf("x = %d\n", x);
    x--;
    printf("x = %d\n", x);
}

```

```
x = 0
x = 1
x = 0
```

As you can see, these increment or decrement a value by 1, in place.  Note this
operator can be applied to the front or end of a value as shown below, with
one minor distinction.

```c
// snippets/prefix_postfix.c

#include <stdio.h> /* printf */

int main() {
    int x = 0;
    int y = 0;
    printf("x++ = %d\n", x++);
    printf("++y = %d\n", ++y);
    printf("x = %d\n", x);
    printf("y = %d\n", y);
}

```

```
x++ = 0
++y = 1
x = 1
y = 1
```

If you use `x++` the effect will only be applied after the expression has been
evaluated (meaning it will hold the old value just before the next line of
code).  Otherwise if you use `++x` the update will be immediately applied

## Ternary Operator

The ternary operator is not very often used, and you never really need it.
However you still might see it in the wild so it's worth learning about.  The
ternary operator in C takes three values and produces one.
The basic template for the operator is 

```
(expression) ? (expression if true) : (expression if false)
```

This can be read as follows: Is `expression` true? If so, give `expression if
true`, otherwise: give `expression if false`

The syntax is demonstrated below

```c
// snippets/ternary.c

#include <stdio.h> /* printf */

int main() {
    int x = 256;
    int y = 312;
    // Get the larger value
    int z = x > y ? x : y;
    printf("max = %d\n", z);
}

```

```
max = 312
```

### Type Conversions

All of the previous examples we looked at were operators on the same types,
however it's perfectly valid to use an operator on two different types like
in this example.

```c
// snippets/operator_types.c

#include <stdio.h> // printf

int main() {
    int a = 5;
    char b = a + '0';
    printf("(char) b = %c\n", b);
    printf("(int) b = %d\n", b);
}

```

```
(char) b = 5
(int) b = 53
```

Here we combine the integer `5` with the character `'0'` viw the `+` operator.
Conversions will automatically take place if a more "narrow" type is being
automatically converted to a less "narrow" type.  There are two automatic
conversions taking place in the above code.  First is the conversion of `'0'`
from `char` to `int` which happens when we add it to the `int` `a`.  Then,
Because we are assigning the expression `a + '0'` to a `char`, we are
converting from `int` to `char`.

Note that when we print the value stored in `b` we either interpret it as a
character (`%c`) or an integer (`%d`) which changes how the value is displayed.

The general rules (from "The C Programming Language") are shown here:

1. If either operand is long double, convert the other to long double.
2. Otherwise, if either operand is double, convert the other to double.
3. Otherwise, if either operand is float, convert the other to float.
4. Otherwise, convert char and short to int.
5. Then, if either operand is long, convert the other to long.

### Casting

Rather than creating a new variable to perform a conversion, you can also
`cast` a value on the fly.  For example, if you want to perform a floating
point division rather than an integer division.

```c
// snippets/operator_types_cast.c

#include <stdio.h> // printf

int main() {
    int a = 5;
    int b = 3;
    printf("(int) %d / %d = %d\n", a, b, a / b);
    printf("(float) %d / %d = %f\n", a, b, (float) a / b);
}

```
```
(int) 5 / 3 = 1
(float) 5 / 3 = 1.666667
```

The above code casts `a` to a `float` before performing the division and so
`b` is automatically converted as per the previous rules, and the result
is a `float`.

## Expressions

Most lines of code we have seen so far are expressions.  An expression is
simply any combination of variables, constants, and operators, which we
have mostly finished explaining by now.  Here are some examples of expressions:

```
123 + 25
123 * 25 - 13
a * b + c
a * (-c)
a * b == c * d
(a == b) && (c == d)
```

When you try to interpet these, you should check how each part of the
expression "resolves" to a value to understand it.  For example in the last
expression, first check if `(a == b)` is true, then check if `(c == d)` is true
and then check if they are both true to check if the expression is true.  You
can replace each part of the expression one piece at a time to break it down
and understand it.  In order to know which part the computer will evaluate
first, you have to look at precedence.

```
() [] -> .
! ~ ++ -- + - * (type)
* / %
+ -
<< >>
< <= > >=
== !=
&
^
|
&&
||
?:
= += -= *= /= %= &= ^= |= <<= >>=
,
```

Note that it is similar to the PEMDAS system we all know and love, but with a
lot more rules.  As always, use extra parentheses to make your intention clear,
don't cram too many operators into one expression, and experiment with your
code to help get it right.
