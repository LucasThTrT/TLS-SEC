// 3. Structures chaînées

// Librairie
#include <stdio.h>
#include <libc.h>
#include <string.h>

char* auteurs[7] = {
    "Victor Hugo",
    "George Orwell",
    "J.K. Rowling",
    "Gabriel Garcia Marquez",
    "Agatha Christie",
    "Ernest Hemingway",
    "Jane Austen"
};

int annees[7] = {1862, 1949, 1997, 1967, 1920, 1952, 1811};

typedef struct livre
{
    char auteur[16];
    int annee;
}livre;

typedef struct cell
{
    livre info;
    struct cell *n_cell;
    struct cell *n_cell_meme_auteur;
    struct cell *n_cell_meme_anne;
}cell;

typedef struct file
{
    cell *first;
    cell *last;
}file;

// Initialiser le livre
livre init_livre(){
    livre l;
    strcpy(l.auteur, auteurs[rand() % 7]); // Copie de l'auteur dans la structure livre
    l.annee = annees[rand() % 7];
    printf(">> %s -- %d\n", l.auteur, l.annee); // Affiche correctement l'année
    return l;
}

/*
livre init_livre(){
    livre l = {auteurs[rand() % 7], annees[rand() % 7]};
    printf(">> %s -- %d", l.auteur, l.auteur);
    return l;
}
*/

// Initialiser la file
void init_file(file *f){
    f->first = NULL;
    f->last = NULL;
}

// Insérer un livre dans la file
void inserer_livre_file(file *file, livre n_livre){
    // création de la nouvelle cellule
    cell *nouvelle_cell = malloc(sizeof(cell));

    nouvelle_cell->info = n_livre;   // ? Normalement le reste de la structure est initialisé a null
    nouvelle_cell->n_cell = NULL;
    nouvelle_cell->n_cell_meme_auteur = NULL;
    nouvelle_cell->n_cell_meme_anne = NULL;

    // Test pour voir si c'est la premiere cellule de la file
    if (file->first == NULL){
        // Ajout de la premiere cellule last + first
        file->last = nouvelle_cell;
        file->first = file->last;
    }
    else {
        // Ajout de la dernière cellule a last en la liant d'abord a l'ancienne
        file->last->n_cell = nouvelle_cell;
        file->last = nouvelle_cell;
    }
}

// Fait les liens des cellules par l'auteur
void classifie_par_auteur(file *f, char *auteur){
    // Parcour de toute la file avec une copie du pointeur pour ne pas le perdre
    cell *p = f->first; // Parcoureur de file
    cell *copie = NULL; // pointeur permettant de faire les liens
    while (p->n_cell != NULL){ // Tant qu'il y a un élément dans la file
        if (strcmp(p->info.auteur, auteur) == 0) { // Comparaison correcte des chaînes
            if (copie == NULL){ // il n'y a pas encore d'autre élémént qui possède le même auteur
                copie = p;
            }
            else {
                copie->n_cell_meme_auteur = p; // On donne le lien pour n_cell
                copie = p; // On garde en copie l'élément suivant avec le meme auteur mais qui n'a pas de lien
            }
        }
        else { // la cellule n'est pas un livre avec l'auteur correspondant 
            NULL; // On ne fait rien
        }
        p = p->n_cell;
    }
}

// Fait les liens des cellules par la date
void classifie_par_annee(file *f, int annee){
    // Parcour de toute la file avec une copie du pointeur pour ne pas le perdre
    cell *p = f->first; // Parcoureur de file
    cell *copie = NULL; // pointeur permettant de faire les liens
    while (p->n_cell != NULL){ // Tant qu'il y a un élément dans la file
        if (p->info.annee == annee){
            if (copie == NULL){ // il n'y a pas encore d'autre élémént qui possède le même annee
                copie = p;
            }
            else {
                copie->n_cell_meme_anne = p; // On donne le lien pour n_cell
                copie = p; // On garde en copie l'élément suivant avec le meme annee mais qui n'a pas de lien
            }
        }
        else { // la cellule n'est pas un livre avec l'annee correspondant 
            NULL; // On ne fait rien
        }
        p = p->n_cell;
    }
}

void affiche (file *f){
    // On crée une copie de la premiere cellule pour pouvoir parcourir la liste
    cell *p_cell = f->first;
    printf("###############################################\n");
    printf("Affichage des livres : \n");
    while (p_cell != NULL){
        // Affichage des infos du livre
        printf(">> %s -- %d \n", p_cell->info.auteur, p_cell->info.annee);
        // On passe au suivant
        p_cell = p_cell->n_cell;
    }
}

void affiche_par_auteur(file *f, char auteur){
    // On crée une copie de la premiere cellule pour pouvoir parcourir la liste
    cell *p_cell = f->first;
    while (p_cell->n_cell_meme_auteur != NULL){
        // Affichage des infos du livre
        printf(">> %s -- %d", p_cell->info.auteur, p_cell->info.annee);
        // On passe au suivant
        p_cell = p_cell->n_cell_meme_auteur;
    }
}

void affiche_par_annee(file *f, int annee){
    // On crée une copie de la premiere cellule pour pouvoir parcourir la liste
    cell *p_cell = f->first;
    while (p_cell->n_cell_meme_auteur != NULL){
        // Affichage des infos du livre
        printf(">> %s -- %d", p_cell->info.auteur, p_cell->info.annee);
        // On passe au suivant
        p_cell = p_cell->n_cell_meme_auteur;
    }
}

int main(){
    file *f = malloc(sizeof(file));
    init_file(f);

    // On va ajouter 20 livres
    for (int i = 0; i<20; i++){
        livre l = init_livre();
        inserer_livre_file(f, l);
    }

    // On va afficher les livres
    affiche(f);

    // On va classer les livres par auteur
    // boucle pour chaque auteur
    for (int i = 0; i<7; i++){
        classifie_par_auteur(f, auteurs[i]);
    }

    // On va afficher les livres par auteur
    for (int i = 0; i<7; i++){
        printf("###############################################\n");
        printf("Affichage des livres de %s : \n", auteurs[i]);
        affiche_par_auteur(f, *auteurs[i]);
        printf("###############################################\n");
    }

    // On va classer les livres par annee
    // boucle pour chaque annee
    for (int i = 0; i<7; i++){
        classifie_par_annee(f, annees[i]);
    }

    // On va afficher les livres par annee
    for (int i = 0; i<7; i++){
        printf("###############################################\n");
        printf("Affichage des livres de %d : \n", annees[i]);
        affiche_par_annee(f, annees[i]);
        printf("###############################################\n");
    }
}