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

// IN : Deux entier a et b non signés
// OUT: c = 2 octet de poids fort de a - 2 octets de poids faible de b
void OperationOctets(uint a, uint b){
    uint a_fort = a & 0xFFFF0000;   // a & 0b1111 1111-1111 1111-0000 0000-0000 0000
    uint b_faible = b & 0x0000FFFF; 
    uint c = a_fort + b_faible;
    printf("Int_c = %d & Hex_c = %x \n", c, c);
}

// Vérifie si deux entiers non signés différent seulement par le bit 10
void Verifierb10(uint a, uint b){
    // opération sur les bits 
    uint verif = a^b;    // a xor b -> 1 si différent 0 si identique

    if (verif == 0x0200)
    { 
        printf("OK >> A & B diffèrent seulement par le bits 10\n");
    }
    else
    {
        printf("NULL >> A & B ne diffèrent pas seulement par le bits 10\n");
    }
    
}

// Donne le nombre de bits à 1 de l'entier n
int bitcount(int n){
    int compteur = 0;
    // On décale une fois les bits a droite jusqu'à qu'ils soient tous sortis
    while (n != 0){
        n = n>>1;
        compteur += 1;
    }
    printf("nb bits à 1 = %d \n", compteur);
    return compteur;
}

int main(){
    // Q1
    DoubleBits(6); // Multiplication par 2
    // Q2
    OperationOctets(500,19);
    // Q3
    Verifierb10(512,0); // 512 = -0000 0000- -0000 0010- -0000 0000- -0000 0000-
    // Q4
    int nb_bits = bitcount(249);
    return 0;
}