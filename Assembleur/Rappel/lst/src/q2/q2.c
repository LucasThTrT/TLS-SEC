#include <stdlib.h>
#include <stdio.h>

struct cpuid {
  int s1;
  int s2;
  int s3;
  int s4;
};

void cpuid_display(struct cpuid *in) {
  printf("s1(0x%08x), s2(0x%08x), s3(0x%08x), s4(0x%08x)\n",
      in->s1,
      in->s2,
      in->s3,
      in->s4
  );
}

void cpuid(int func, struct cpuid *out) {
  // Exécution de l'instruction cpuid
  printf("Fonction demandée(0x%08x)\n", func);
  cpuid_display(out);
}

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);

  // Déclaration de la variable de sortie
  struct cpuid out;

  // Appel de la fonction cpuid pour le constructeur
  // cpuid(...)

  // Traitement du résultat et affichages
  cpuid_display(&out);

  // Appel de la fonction cpuid pour les fréquences
  // cpuid(...)

  // Traitement du résultat et affichages
  cpuid_display(&out);

  return 0;
}
