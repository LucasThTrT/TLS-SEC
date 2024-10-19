#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

# define MAXSIZE_SECTION 24 // Taille max d'élément dans une section

// Déclaration des structures

// froger est la liste des différents sections
// Les sections possèdent plusieurs outils

// type outils qui est la présentation d'un outil de hacking
typedef struct outils
{
    int id;
    char* name;                  // Attention : char* pour une chaîne de caractères
    //? char description;        // Descriptoins de l'outils -> nom du fichier où lire
    //? char exemples;           // Exemples d'utilisation -> nom du fichier où lire
    //? struct command* cmd;     // Commande friendly qui se lance ici ! ?? -> nom du fichier où lire ??
    struct outils* next;
} outils;

// section : ensemble des outils
// Construit en liste chaîné des outils
typedef struct section
{
    char* name;               // char* pour stocker une chaîne de caractères
    outils* first;
    outils* actuel;
    struct section* next;
} section;

// froger : structure global
// Liste chaînée des sections
typedef struct froger
{
    section* first;
} froger;

// Prototypes des fonctions

// affichage du header depuis le fichier header.txt
int print_header(void);

// retourne tout le contenu d'un dossier sous forme de liste
char** read_folder(char* folder);

#endif // STRUCTS_H
