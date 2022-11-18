#include <stdio.h>
#include <stdlib.h>

int main(void) {

    int *p;
    int nb;

    printf("Saisissez une taille : ");
    scanf("%d", &nb);

    p = (int *) malloc(nb * sizeof(int));

    for(int i=0;i<nb;i++)
        scanf("%d",p+i);

    for(int i=0;i<nb;i++)
        printf("%d ", *(p+i)); // on peut ecrire avec une forme simplifiée t[i]

    return 0;
}