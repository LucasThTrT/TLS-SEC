#include "structs.h"


void init_frog(froger *frog){
    printf("Initialisation de la structure froger\n");
    // Initialisation de la liste chaînée section
    // Lecture des fichiers dans le dossier section
    char* folder = "sections";
    char** liste = read_folder(folder);
    section* s = malloc(sizeof(section));
    section* copie = s;
    
    frog->first = s;

    int i = 0;
    while (liste[i] != NULL)
    {
        // affichage de la liste des sections
        // printf("Section %d -> %s\n", i, liste[i]);
        if (i == 0){
            // allocation de la mémoire pour le nom de la section
            copie->name = malloc(strlen(liste[i]) * sizeof(char));
            // copie de la chaine de caractère
            strcpy(copie->name, liste[i]);
        }
        else{
            copie->next = malloc(sizeof(section));
            copie = copie->next;
            // allocation de la mémoire pour le nom de la section
            copie->name = malloc(strlen(liste[i]) * sizeof(char));
            // copie de la chaine de caractère
            strcpy(copie->name, liste[i]); //! pas faire le strcpy risque de segfault
            copie->next = NULL;
        }
        i++;
    }

    //TODO : Maintenant il faut dans chaque itération while faire la même opération pour les outils !!
}


int main(void){
    // Appel de la fonction pour imprimer l'en-tête
    if (print_header() == EXIT_FAILURE) {
        return EXIT_FAILURE;
    }

    // Création de froger
    froger* frog = malloc(sizeof(froger));
    init_frog(frog);

    // Test de l'initialisation de la structure froger
    // affichage de toutes les sections
    section* s = frog->first;
    int i = 0;
    while (s != NULL)
    {
        printf("Section %d -> %s\n", i, s->name);
        s = s->next;
        i++;
    }

    return 0;
}


