#include <stdio.h>
#include <stdbool.h>
#define MAX 30
#define MAXLET 26

typedef struct {
    int sommet;
    char tableau[MAX];
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
    return a.tableau[a.sommet - 1];
}

Pile empiler(Pile a, char b) {
    a.tableau[a.sommet] = b;
    a.sommet++;
    return a;
}

Pile depiler(Pile a, char *c) {
    if(!pileVide(a)) {
        *c = sommetPile(a);
        a.sommet--;
    }
    return a;
}

void afficherPile(Pile a) {
    while(!pileVide(a)){
        printf("%c", a.tableau[a.sommet-1]);
        a.sommet--;
    }
}

Pile inverserPile(Pile a) {
    Pile b = creerPile();
    while(!(pileVide(a))){
        b.tableau[b.sommet] = a.tableau[a.sommet-1];
        a.sommet--;
        b.sommet++;
    }
    return b;
}

Pile postfixe (char chaine[MAX]) {
    Pile a, b;
    int i = 0;
    char c;
    a = b = creerPile();
    while(chaine[i] != '\0') {
        if(chaine[i] >= 'a' && chaine[i] <='z') {
            a = empiler(a, chaine[i]);
        } else if (chaine[i] == '*' || chaine[i] == '+' || chaine[i] == '-' || chaine[i] == '/'){
            b = empiler(b, chaine[i]);
        } else if (chaine[i] == ')'){
            b = depiler(b, &c);
            a = empiler(a, c);
        }
        i++;
    }
    return a;
}


int main() {
    char c[MAX] =  "((a+b)*c)\0";
    Pile a = creerPile();
    a = postfixe(c);
    a = inverserPile(a);
    afficherPile(a);
    return 0;
}

