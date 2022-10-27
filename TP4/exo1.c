#include <stdio.h>
#include <stdbool.h>
#define MAX 30

typedef struct {
    int sommet;
    int tableau[MAX];
} Pile;

Pile creerPile() {
    Pile p;
    p.sommet = 0;
    return p;
}

bool pileVide(Pile a) {
    return a.sommet == 0;
}

int sommetPile(Pile a) {
    return a.tableau[a.sommet];
}

Pile empiler(Pile a, int b) {
    a.tableau[a.sommet] = b;
    a.sommet++;
    return a;
}

Pile depiler(Pile a, int *c) {
    if(!pileVide(a)) {
        *c = sommetPile(a);
        a.sommet--;
    }
    return a;
}

void afficherPile(Pile a) {
    while(!pileVide(a)){
        printf("%d", a.tableau[a.sommet]);
        a.sommet--;
    }
}

Pile inverserPile(Pile a) {
    Pile b = creerPile();
    while(!(pileVide(a))){
        b.tableau[b.sommet] = a.tableau[a.sommet];
        a.sommet--;
        b.sommet++;
    }
    return b;
}

int main() {
    Pile a = creerPile();
    a = empiler(a, 4);
    a = empiler(a, 6);
    a = empiler(a, 8);
    afficherPile(a);
    return 0;
}

