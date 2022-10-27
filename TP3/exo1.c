#include <stdio.h>
#define MAX 5

typedef struct {
    int tableau[MAX];
    int taille;
} Tableau;

int lireEntier(int a, int b) {
    int valeur;
    do {
        printf("Entrez un entier : ");
        scanf("%d", &valeur);
    } while (valeur <= a && valeur >= b);
    return valeur;
}

Tableau saisirTableau(Tableau t) {
    for(int i = 0; i < t.taille; i++) {
        t.tableau[i] = lireEntier(1, MAX);
    }
    return t;
}

void afficherTableau(Tableau t) {
    for(int i = 0; i < t.taille ; i++) {
        printf("%d", t.tableau[i]);
    }
}

void echanger(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

Tableau triSelection(Tableau t) {
    int tmps;
    for(int i = 0; i < t.taille - 1; i++) {
        for(int j = i + 1; j < t.taille; j++) {
            if(t.tableau[i] > t.tableau[j]) {
                tmps = t.tableau[i];
                t.tableau[i] = t.tableau[j];
                t.tableau[j] = tmps;
            }
        }
    }
    return t;
}



int main(void) {
    int a = 5, b = 8;
    Tableau t;
    t.taille = MAX;
    printf("Saisir tableau\n");
    t = saisirTableau(t);
    printf("Afficher tableau\n");
    afficherTableau(t);
    printf("\nEchanger\n");
    echanger(&a, &b);
    printf("%d %d\n", a, b);
    printf("tri selection\n");
    t = triSelection(t);
    afficherTableau(t);
    return 0;
}
