#include <stdio.h>

int main(void) {

    int tab[] = { 0, 1, 2, 3, 4};
    int somme = 0;
    int k = 0;

    for(int *i = &k; *i < 5; *i++) {
        somme += *(tab + i);
    }

    printf("%d", somme);

    return 0;
}