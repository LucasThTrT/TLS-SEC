#include <stdio.h>
#include <libc.h>

// Saisie en prenant comme paramètre le tableau
void saisie(int i, int j, int tab[][j]){
    printf("Saisie des éléments du tableau %d,%d\n", i, j);
    int compteur = 0;
    for (int ligne = 0; ligne < i; ligne++) {
        for (int colonne = 0; colonne < j; colonne++) {
            printf("Rentrer la valeur de l'élément %d\n", compteur);
            scanf("%d", &tab[ligne][colonne]);
            compteur++;
        }
    }
}

// Saisie en prenant en paramètre le tableau SOUS FORME DE POINTEUR D'ENTIER
void saisiep(int i, int j, int * tab){
    int val;
    for (int element = 0; element< i*j; element++){
        printf("Saisir l'élément %d \n", element);
        scanf("%d", &val);
        * tab = val;
        tab++;
    }
}

void affiche(int i, int j, int tab[][j]){
    printf("Affichage du tableau de taille %d,%d\n", i, j);
    for (int ligne = 0; ligne < i; ligne++) {
        for (int colonne = 0; colonne < j; colonne++) {
            printf("%d ", tab[ligne][colonne]);
        }
        printf("\n");
    }
}

int main() {
    printf("START\n");
    int n_lignes = 3;
    int n_colonnes = 3;

    // Déclaration statique
    //int tab[n_lignes][n_colonnes];

    // Déclaration du tableau avec le pointeur
    int * tab = malloc(sizeof(int[n_colonnes][n_lignes]));

    //saisie(n_lignes, n_colonnes, tab);
    saisiep(n_lignes, n_colonnes, tab);
    affiche(n_lignes, n_colonnes, tab);

    return 0;
}
