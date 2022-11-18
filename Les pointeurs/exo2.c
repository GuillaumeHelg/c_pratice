#include <stdio.h>

int main(void) {
    char p = 'a';
    char z = 'k';
    char tmp;
    char *a;
    char *b;

    a = &p;
    b = &z;

    tmp = *a;
    *a = *b;
    *b = tmp;


    return 0;
}