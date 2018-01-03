/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} student;

int main (int argc, char** argv) {
if (argc<2) {
  fprintf (stderr, "Niepoprawny sposob wywolania programu.\nJako argumenty wywolania podaj nazwy plikow z ocenami.");
}
FILE *plik;
plik = fopen(argv[1], "r");
if (!plik)
   {
       fprintf (stderr, "Nie moge otworzyc pliku %s kod bledu: %d\n", argv[1], errno);
       exit(-1);
   }
else {
  do{
      fscanf(plik, "%s, %s, %s", student.imie, student.nazwisko, student.ocena);
      printf(" %s\n %s\n %s\n", student.imie, student.nazwisko, student.ocena);
  }
  while (!feof(plik));
  fclose(plik);
  return 0;
}
}
