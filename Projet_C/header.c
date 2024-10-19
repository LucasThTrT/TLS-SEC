#include "structs.h"

int print_header(){
    // Lecture et affiche de header.txt ligne par ligne
    FILE *header = fopen("header.txt", "r");  // Ouverture du fichier

    // Contrôle lecture
    if (header == NULL){
        perror("erreur lors de l'ouverture de l'header");
        return EXIT_FAILURE;
    }

    // Tampon pour stocker la ligne lue
    char buffer[256];

    // Boucle affichage
    while (fgets(buffer, sizeof(buffer), header) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(header);  // Fermer le fichier après lecture
    return 0;
}
