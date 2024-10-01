#include <libc.h>
#include <stdio.h>
#include <stdlib.h>

// Instuction qui permet de multiplier un entier par 2 sdans utiliser l'opérateur de multiplication
void DoubleBits(int a){
    // On décale tous les bits une fois à gauche
    int decal = 1;
    a = a << 1;
    printf("a = %d \n", a);
}

int main(){
    DoubleBits(6); // Multiplication par 2
    return 0;
}