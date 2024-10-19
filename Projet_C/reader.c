#include "structs.h"
#include <dirent.h>

char** read_folder(char* folder){
    // Allocation de la mémoire pour le contenu
    char** contenu = malloc(MAXSIZE_SECTION * sizeof(char*));

    // Ouverture du répertoire
    DIR *dir = opendir(folder);
    if (dir == NULL){
        perror("Erreur lors de l'ouverture du répertoire");
        free(contenu);
        return NULL;
    }

    // Lire le contenu du folder
    struct dirent *entry;
    int i = 0;
    while ((entry = readdir(dir)) != NULL && i< MAXSIZE_SECTION) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0){
            // On ne copie pas le répertoire courant et parent
            contenu[i] = malloc(strlen(entry->d_name) * sizeof(char));
            strcpy(contenu[i], entry->d_name); //! pas faire le strcpy risque de segfault
            i++;
        }
    }
    return contenu;
}