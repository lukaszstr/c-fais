/* Łukasz Strzelec - funckja alokator zajmuje się dynamiczną alokacją pamięci i czytanie z pliku/stdin*/
#include <stdio.h>
#include <stdlib.h>

char *alokator(FILE* fp, size_t size) {
  char *ciag;
  int wskazywacz;
  size_t dlugosc = 0;
  ciag = realloc(NULL, sizeof(char)*size);
  if (!ciag ) {
    return ciag;
  }
  /* Teraz pętla while do nowej linii lub EOF*/
  while (EOF != (wskazywacz = fgetc(fp) ) && wskazywacz != '\n') {
    ciag[dlugosc++] = wskazywacz;
    if (dlugosc == size) {
      ciag = realloc( ciag, sizeof(char)*(size += 16) );
      if (!ciag) {
        return ciag;
      }
    }
  }
  ciag[dlugosc++]='\0';
  return realloc(ciag, sizeof(char)*dlugosc);
}
