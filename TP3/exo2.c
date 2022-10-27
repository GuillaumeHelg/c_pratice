#include <stdio.h>
#include <stdbool.h>
#define MAXLIG 3
#define MAXCOL 3
#define MAX 3
#define MIN 0

typedef struct {
    int tab[MAXLIG][MAXCOL];
} Matrice;

typedef struct {
    int indexCol;
    int indexLig;
} Coord;

int lireEntier(int a, int b) {
    int valeur;
    do {
        printf("Entrez un entier : ");
        scanf("%d", &valeur);
    } while (valeur <= a && valeur >= b);
    return valeur;
}

Matrice remplirMatrice () {
    Matrice m;
    for(int i = 0; i < MAXLIG; i++) {
        for(int j = 0; j < MAXCOL; j++) {
            m.tab[i][j] = lireEntier(0, MAX);
        }
    }
    return m;
}

void afficherMatrice(Matrice m) {
    for(int i = 0; i < MAXLIG; i++) {
        for(int j = 0; j < MAXCOL; j++) {
            printf("%d", m.tab[i][j]);
        }
        printf("\n");
    }
}

void minCol (Matrice m, int ligne, int *col, int *min) {
    *min = m.tab[ligne][0];
    for(int i = 0; i < MAXLIG; i++) {
        if(*min >= m.tab[ligne][i]) {
            *min = m.tab[ligne][i];
            *col = i;
        }
    }
}

void minimumLigne(Matrice m, int ligne, int *col, int *lig) {
    int i = 0;
    int min = m.tab[ligne][i];
    *lig = ligne;
    *col = i;
    while(i < MAX) {
        if(min < m.tab[ligne][i]) {
            min = m.tab[ligne][i];
            *lig = ligne;
            *col = i;
        }
        i++;
    }
}

void maximumColonne(Matrice m, int colonne, int *col, int *lig) {
    int i = 0;
    int max = m.tab[i][colonne];
    *lig = i;
    *col = colonne;
    while(i < MAX) {
        if(max > m.tab[i][colonne]) {
            max = m.tab[i][colonne];
            *lig = i;
            *col = colonne;
        }
        i++;
    }
}

int afficheValeur(Coord c, Matrice m) {
    return m.tab[c.indexLig][c.indexCol];
}

bool miniMax(Matrice m) {
    bool trouve = false;
    int i = 0, j = 0;
    Coord minLigne[MAX], maxCol[MAX];

    // coord de tout les minimum de lignes
    while(i < MAX) {
        minimumLigne(m, i, &minLigne[i].indexLig, &minLigne[i].indexCol);
        i++;
    }
    i = 0;
    // coord de tout les maximum de colonne
    while(i < MAX) {
        maximumColonne(m, i, &maxCol[i].indexLig, &maxCol[i].indexCol );
        i++;
    }
    i = 0;
    for(int a = 0; a < MAX; a++) {
        for(int k = 0; k < MAX; k++) {
            if(minLigne[a].indexLig == maxCol[k].indexLig) {
                if(minLigne[a].indexCol == maxCol[k].indexCol) {
                    trouve = true;
                    printf("Le minimax est %d", m.tab[minLigne[a].indexLig][minLigne[a].indexCol]);
                }
            }
        }
    }

    // on regarde si un se situe dans les deux
    return trouve;
}



int main(void) {
    Matrice n;

    n = remplirMatrice();
    afficherMatrice(n);

    if(miniMax(n)) {
        printf("yo");
    } else {
        printf("nop");
    }

    return 0;
}