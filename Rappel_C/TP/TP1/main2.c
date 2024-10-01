#include <stdio.h>
#include <libc.h>

void Saisie(int l, int c, int *tab){
    int compteur = 0;
    for (int ligne = 0; ligne<l; ligne++){
        for (int colonne = 0; colonne<c; colonne++){
            compteur += 1;
            printf("saisir élement numéro : %d \n ", compteur);
            scanf("%d", &(*((tab + ligne) + colonne)));
        }
    }
}

void Affiche(int l, int c, int *tab){
    for (int ligne = 0; ligne<l; ligne++){
        for (int colonne = 0; colonne<c; colonne++){
            printf("%d", (*((tab + ligne) + colonne)));
        }
        printf(("\n"));
    }
}

void init(int * l, int * c){
    // Interrogation
    printf("nb ligne :");
    scanf("%d", l);
    printf("nb colonne :");
    scanf("%d", c);
}

int main(){
    //initialisation des variables de taille
    int * ligne = malloc(sizeof(int));
    int * colonne = malloc(sizeof(int));

    init(ligne, colonne);

    // Allocation de la mémoire pour le tableau de pointeur
    int * tab = malloc((*ligne * sizeof(int *)) * (*colonne * sizeof(int)));

    // Fonction de Saisie
    Saisie(*ligne, *colonne, tab);

    Affiche(*ligne, *colonne, tab);

    return 0;
}