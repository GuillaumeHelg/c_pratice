#include <stdio.h>

int taille(char *chaine) {

    int i = 0;

    while(i[chaine])
        i++;

    return i;
}

int main(void) {

    char chaine[] = "salut";

    printf("%d", taille(chaine));
}