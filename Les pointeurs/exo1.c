#include <stdio.h>

int main (void) {
    // il faut d'abord déclarer des variables
    int i = 4;
    int j = 6;
    int *a;
    int *b;

    // assigner leurs adresses aux pointeurs
    a = &i;
    b = &j;

    // faire l'addition
    printf("%d", *a + *b);
    return 0;
}