# Algorithms

As of this session, we have seen almost everything C has to offer!  It might
be hard to imagine, but with the tools we have been given, it is possible
to write any algorithm.  Yes, any algorithm you could possibly imagine can
be written with the tools we have learned.  Now it's just a matter of good
thinking and organization.  In this session we will go over some well known
data structures and algorithms.

## Linked List

We motivate our discussion with the problem: Given two very large numbers
as an input, print their sum.  We will assume the numbers are too large to
fit into any of the predefined integer types (including long long) and therefore we will need
a new way of storing them.  There might be better ways, but as one of the
simpler solutions, we will store a number as a linked list, each node
representing one digit.  We can re-use some of our code from the previous
session.

```c
// snippets/linkedList.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Node {
    struct Node *next;
    int digit;
} Node;

Node *makeNode(Node *np, int digit) {
    Node *newPtr = (Node *) malloc(sizeof(Node));
    if (!newPtr) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newPtr->next = np;
    newPtr->digit = digit;
    return newPtr;
}

int len(Node *np) {
    int n = 0;
    while (np) {
        n += 1;
        np = np->next;
    }
    return n;
}

Node *add(Node *a, Node *b) {
    int carry = (a->digit + b->digit) > 9;
    int value = (a->digit + b->digit) % 10;
    Node *rs = makeNode(NULL, value);
    Node *r = rs;
    Node z = {NULL, 0};
    Node *zp = &z;
    while (a->next || b->next || carry) {
        a = (a->next) ? a->next : zp;
        b = (b->next) ? b->next : zp;
        r->next = makeNode(NULL, (a->digit + b->digit + carry) % 10);
        carry = (a->digit + b->digit + carry) > 9;
        r = r->next;
    }
    return rs;
}

void printList(Node *np) {
    int index = len(np);
    char c[index+1];
    for (int n = 0; n < index+1; n++) {
        c[n] = '\0';
    }
    while (np) {
        c[--index] = np->digit + '0';
        np = np->next;
    }
    printf("%s\n", c);
}

void freeList(Node *np) {
    while (np) {
        Node *temp = np;
        np = np->next;
        free(temp);
    }
}

Node *fromString(char *string) {
    int len = strlen(string);
    Node *sp = makeNode(NULL, string[len-1] - '0');
    Node *np = sp;
    for (int i = len - 2; i >= 0; i--) {
        np->next = makeNode(NULL, string[i] - '0');
        np = np->next;
    }
    return sp;
}

int main(int argc, char *argv[]) {
    assert(argc == 3);
    Node *ap = fromString(argv[1]);
    Node *bp = fromString(argv[2]);
    printList(ap);
    printList(bp);
    Node *sum = add(ap, bp);
    printList(sum);

    freeList(ap);
    freeList(bp);
    freeList(sum);
}

```

Some questions:
* What are some flaws, or things missing in this code?

1. We didn't error check the malloc :)
2. We didn't free our memory!
3. We control the input, but we didn't actually verify a or b isn't null (it could be!)

* What other functions could we add?
1. A free function
2. Handling negative numbers
3. Copying or reversing the linked list

## Stack

We motivate our discussion with the problem: Given a string of mixed
parentheses, determine if it's balanced.  For example, `(){[]}` is balanced,
while `[(])` is not.

```c
// snippets/stack.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    struct Node *next;
    char symbol;
} Node;

typedef struct Stack {
    Node *sentinel;
    Node *top;
} Stack;

Stack *makeStack() {
    Stack *sp = (Stack *) malloc(sizeof(Stack));
    if (!sp) {
        fprintf(stderr, "Memory allocation failed for Stack\n");
        exit(EXIT_FAILURE);
    }
    Node *np = (Node *) malloc(sizeof(Node));
    if (!np) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    np->next = NULL;
    np->symbol = '!';
    sp->sentinel = np;
    sp->top = np;
    return sp;
}

void push(Stack *sp, char c) {
    // Initialize new Node
    Node *np = (Node *) malloc(sizeof(Node));
    if (!np) {
        fprintf(stderr, "Memory allocation failed for Node\n");
        exit(EXIT_FAILURE);
    }
    np->next = sp->top;
    np->symbol = c;
    // Add it to the Stack
    sp->top = np;
}

char pop(Stack *sp) {
    if (sp->top == sp->sentinel) {
        fprintf(stderr, "Attempted to pop from an empty stack\n");
        exit(EXIT_FAILURE);
    }
    char c = sp->top->symbol;
    Node *temp = sp->top;
    sp->top = sp->top->next;
    free(temp);
    return c;
}

void printNode(Node *n) {
    printf("(%p, '%c')\n", n->next, n->symbol);
}

void printStack(const Stack *sp) {
    printf("---Stack Start---\n");
    Node *np = sp->top;
    while (np->next) {
        printNode(np);
        np = np->next;
    }
    printf("---Stack End---\n");
}

int empty(const Stack *sp) {
    return (sp->top == sp->sentinel);
}

void freeStack(Stack *sp) {
    Node *np = sp->top;
    Node *tnp;
    while (np) {
        tnp = np->next;
        free(np);
        np = tnp;
    }
    free(sp);
}

int balanced(const char *str) {
    Stack *sp = makeStack();
    char c;
    for (; (c = *str); str++) {
        if (c == '(' || c == '[' || c == '{') {
            push(sp, c);
        } else if (c == ')' && !empty(sp) && sp->top->symbol == '(') {
            pop(sp);
        } else if (c == ']' && !empty(sp) && sp->top->symbol == '[') {
            pop(sp);
        } else if (c == '}' && !empty(sp) && sp->top->symbol == '{') {
            pop(sp);
        } else if (c == ')' || c == ']' || c == '}') {
            // Unmatched closing bracket
            freeStack(sp);
            return 0;
        }
    }
    int retval = empty(sp);
    freeStack(sp);
    return retval;
}

int main() {
    assert(balanced("()())") == 0);
    assert(balanced("(a)b") == 1);
    assert(balanced("(ab") == 0);
    assert(balanced("[(])") == 0);
    assert(balanced("[]()") == 1);
    assert(balanced("[a(cd)b]-(f{h}g)") == 1);
    assert(balanced("[a(cd)b]-[(f{h}g)") == 0);
    printf("All tests passed!\n");
    return 0;
}
```

Some questions:
* What are some flaws, or things missing in this code?

1. If we fail to allocate memory, we don't free all used memory up
2. The input function isn't resilient to all characters inputted
3. The sentinel is created with a random character

* What other functions could we add?
1. Stack size
2. Is full with a maximum size
3. A peek at the top that doesn't remove it
