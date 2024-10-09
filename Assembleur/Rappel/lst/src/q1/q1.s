// Export du symbole fac_asm pour utilisation possible dans d'autres
// fichiers i.e src/q1/bs.c
.global fac_asm

fac_asm:

  // Sauvergarde et définition du contexte
  push %rbp
  mov %rsp, %rbp

  // Calcul de facturielle
  // paramètre : x dans %rax
  // retour : placé dans %rax
    
  // Copie de x
  mov %rax, %rbx

  // Création de la variable factorielle qu'on va multiplier
  mov $1, %rax
  
  // Création du multiplicateur
  mov $2, %rcx

  // boucle for -> rcx ++ <rbx
for:
  cmp %rbx, %rcx
  je stop
  mul %rcx
  inc %cx
  jmp for

stop:
  // Opération finale (x-1)*x
  mul %rbx
   
  // Restauration du contexte
  leave
  // retour de la fonction
  ret
