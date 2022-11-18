#include <stdio.h>
#include <string.h>
#define MAX 50

int main(void) {

    char text[MAX];
    char c;
    char *p;

    printf("Saisis une chaine : ");
    scanf("%s", text);

    getchar(); // pour vider le buffer

    printf("Saisis le caractere a partir duquel on affiche la chaine : ");
    scanf("%c", &c);

    p = strchr(text, c); // pour aller à la première occurence de ce caratere

    while(p < text+strlen(text)) { //tant qu'on ne depasse pas la taille du string
        p++; // on incrémente l'adresse de p
        printf("%c", *p); // on affiche le contenu de p
    }
    return 0;
}