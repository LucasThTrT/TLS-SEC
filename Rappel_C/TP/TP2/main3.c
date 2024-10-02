// 3. Structures chaînées

// Librairie
#include <stdio.h>
#include <libc.h>

typedef struct livre
{
    char titre[16];
    int annee;
}livre;

typedef struct cell
{
    livre info;
    cell *n_cell;
    cell *n_cell_meme_auteur;
    cell *n_cell_meme_anne;
}cell;

typedef struct file
{
    cell *first;
    cell *last;
};

file init_file(){
    // initialisation de la cell
    cell premier = NULL;
    file f = malloc(2*sizeof(cell));
    f.first = premier;
    f.last = last;
}

int main(){
    
    return 0;
}