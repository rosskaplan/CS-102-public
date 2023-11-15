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

