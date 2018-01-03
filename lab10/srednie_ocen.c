/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} student;

int main (int argc, char** argv) {

/* sprawdzenie czy program zostal prawidlowo wywolany */
if (argc<2) {
  fprintf (stderr, "Niepoprawny sposob wywolania programu.\nJako argumenty wywolania podaj nazwy plikow z ocenami.\n");
  exit(-1);
}

/* grupa[30]; */
/* deklaracja iteratora i, liczby ocen, zmiennej ino - sprawdzającej czy w danej linii pliku znajdują się 3 byty */
int i=0; int liczba_ocen=0; int ino = 1;
for (i=1; i<=argc; i++) {
FILE *plik;
plik = fopen(argv[1], "r");

/* sprawdz czy mozesz otworzyc plik */
if (!plik)
   {
       fprintf (stderr, "Nie moge otworzyc pliku %s kod bledu: %d\n", argv[1], errno);
       exit(-2);
   }
else {
    else{
  while (ino != EOF)
    {
      ino = fscanf(plik, "%s %s %s\n", student.imie, student.nazwisko, student.ocena[1]);
      printf("Imie: %s\nNazwisko: %s\nOcena: %s\n liczba wczt. danych=%d\n", student.imie, student.nazwisko, student.ocena[1], ino);

/*sprawdz czy dana linia zawiera komplet danych */
      if (ino < 3) {
        fprintf(stderr, " \n Blad.Ta linia nie zawiera kompletnych danych. Pomijam\n");
      }
      else{
        student s1
      }
  }
}
  fclose(plik);
}
}
return 0;
}
