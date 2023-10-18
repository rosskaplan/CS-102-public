#include <stdio.h> 

int main() {
    int x = (82 << 0) +   //  R
            (111 << 8) +  //  O
            (115 << 16) + //  S
            (115 << 24);  //  S
    void *ptr = &x;
    printf("%lu\n", sizeof(int));
    printf("%lu\n", sizeof(char));
    printf("%d\n", *(int *)ptr);

    printf("%c", *((char *)ptr+0));
    printf("%c", *((char *)ptr+1));
    printf("%c", *((char *)ptr+2));
    printf("%c\n", *((char *)ptr+3));
} 
