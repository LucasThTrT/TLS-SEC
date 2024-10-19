#include "structs.h"


void init_outils(section* s){
    // printf("Initialisation de la structure outils\n");
    // Lecture des fichiers dans les sections
    // dossier parent = sections/section->name
    char folder[50] = "sections/";
    strcat(folder, s->name);
    // printf("Lecture des fichiers dans le dossier %s\n", folder);
    char** liste = read_folder(folder);

    // Initialisation de la liste chaîné outils
    s->first = malloc(sizeof(outils));
    s->actuel = s->first;

    int i = 0;
    while (liste[i] != NULL){
        if(i == 0){
            // printf("Initialisation de l'outil %s\n", liste[i]);
            // Initialisation
            // s->first->id = malloc(sizeof(int));                       //? utile ///
            s->first->name = malloc(strlen(liste[i]) * sizeof(char)); //? utile ///
            s->first->id = i;
            strcpy(s->first->name, liste[i]);
            s->first->next = NULL;
        }
        else{
            s->actuel->next = malloc(sizeof(outils));
            s->actuel = s->actuel->next;
            // s->actuel->id = malloc(sizeof(int));                       //? utile ///
            s->actuel->name = malloc(strlen(liste[i]) * sizeof(char)); //? utile ///
            s->actuel->id = i;
            strcpy(s->actuel->name, liste[i]);
            s->actuel->next = NULL;
        }
        i++;
    }
}

void init_frog(froger *frog){

    // printf("Initialisation de la structure froger\n");
    // Initialisation de la liste chaînée section
    // Lecture des fichiers dans le dossier sections
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
            // SECTION
            // allocation de la mémoire pour le nom de la section
            copie->name = malloc(strlen(liste[i]) * sizeof(char));
            // copie de la chaine de caractère
            strcpy(copie->name, liste[i]);

            // OUTILS
            // Initialisation de la liste chaîné outils
            init_outils(copie);
            copie->next = NULL;
        }
        else{
            // SECTION
            copie->next = malloc(sizeof(section));
            copie = copie->next;
            // allocation de la mémoire pour le nom de la section
            copie->name = malloc(strlen(liste[i]) * sizeof(char));
            // copie de la chaine de caractère
            strcpy(copie->name, liste[i]); //! pas faire le strcpy risque de segfault
            copie->next = NULL;

            // OUTILS
            // Initialisation de la liste chaîné outils
            init_outils(copie);
        }
        i++;
    }
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
    // affichage de toutes les sections et outils
    section* s = frog->first;
    while (s != NULL){
        printf("Section : %s\n", s->name);
        outils* o = s->first;
        while (o != NULL){
            printf("Outil : %s\n", o->name);
            o = o->next;
        }
        s = s->next;
    }
}


