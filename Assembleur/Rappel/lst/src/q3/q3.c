#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void memcpy_asm(char *dst, const char *src, unsigned int size) {
  printf("dst(%p), src(%p), size(0x%08x)\n", dst, src, size);
  // Complétez ici
}

int main(int argc, char *argv[]) {
  printf("argc = %d, argv = %p\n", argc, argv);
  char str1[] = "I love tls-secte";
  char str2[sizeof(str1)];
  // Copie à remplacer par memcpy_asm()
  memcpy(&str2[0], &str1[0], sizeof(str1));
  printf("How do I do (%p) ? %s\n", &str2[0], &str2[0]);
  return 0;
}
