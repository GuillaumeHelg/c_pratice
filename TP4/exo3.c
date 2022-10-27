#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#define MAXLET 26

typedef struct {
    int sommet;
    char tableau[MAXLET];
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
        printf("%c\n", a.tableau[a.sommet-1]);
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

Pile postfixe (char chaine[MAXLET]) {
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

void initTab(int *tab[MAXLET]) {
    int i = 0;
    while(i != MAXLET) {
        *tab[i] = -1;
    }
}

int valeur(int *tab[MAXLET]) {
    char c;
    int nbr;
    printf("Saisie une lettre et un nombre associé comme ça a=12");
    scanf("%c=%d", &c, &nbr);
    *tab[(int)c - 97] = nbr;
    return nbr;
}

int calcul(char op, int op1, int op2) {
    int res = 0;
    switch (op) {
        case '*' :
            res = op1 * op2;
            break;
        case '+' :
            res = op1 + op2;
            break;
        case '-' :
            res = op1 - op2;
            break;
        case '/' :
            res = op1 / op2;
            break;
        default :
            printf("opérateur mauvais");
            break;
    }
    return res;
}

int evaluation(char chaine[MAXLET]) {
    int i = 0, res, operande1, operande2;
    char op, operateur;
    Pile a = creerPile();

    while(i < strlen(chaine)) {
        if(isdigit(chaine[i])) {
            a = empiler(a, chaine[i]);
        } else {
            operateur = chaine[i];
            a = depiler(a, &op); operande1 = op - '0';
            a = depiler(a, &op); operande2 = op - '0';
            res = calcul(operateur, operande1, operande2);
            a = empiler(a, res+'0');
        }
        i++;
    }
    return res;
}

int main() {
    char c[MAXLET] =  "345+6+*";
    int a = evaluation(c);
    printf("%d", a);
    return 0;
}