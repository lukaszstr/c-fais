/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

/* Struktura studenta i bufor do normalizacji*/
struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} Student;
char bufor[32];
double oceny_grupy[];

/*Funkcja normalizująca nazwisko i imię na polski */
char normalizuj (char bufor [30])	{
	int i;
if (bufor[0] > 90) {
	bufor[0] -= 32;
}
else {}
for (i=1; i<strlen(bufor); i++) {
	if (bufor[i] < 97) {
		bufor[i] += 32;
	}
}
return 0;
}

/* Początek funkcji main 	*/
int main (int argc, char** argv) {

/* sprawdzenie czy program zostal prawidlowo wywolany */
if (argc<2) {
  fprintf (stderr, "Niepoprawny sposob wywolania programu.\nJako argumenty wywolania podaj nazwy plikow z ocenami.\n");
  exit(-1);
}

struct student grupa[30];
/* deklaracja iteratora i, liczby ocen, zmiennej ino - sprawdzającej czy w danej linii pliku znajdują się 3 byty */
int i=0; int j=0; int liczba_ocen=0; int ino = 1; int licznik_student=0; int liczba_studentow=0; int licznik_powtarzajacych=0;
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
  while (ino != EOF)
    {
      ino = fscanf(plik, "%s %s %s\n", Student.imie, Student.nazwisko, Student.ocena[1]);
/*sprawdz czy dana linia zawiera komplet danych */
      if (ino < 3) {
        fprintf(stderr, "\nBlad.Ta linia nie zawiera kompletnych danych. Pomijam\n");
      }
      else{
/* Normalizacja imienia i nazwiska i pętla porównująca imiona i nazwiska obecnego studenta z tymi znajdującymi się w grupie */
        normalizuj(Student.imie);
        normalizuj(Student.nazwisko);
				i = 0;
				while (!(i == licznik_student)) {
					if (strcmp(grupa[i].imie, Student.imie)) {
						fprintf(stdout, "To nie ten student\n");
						i += 1;
					}
					else {
/* jeśli student znajduje się w grupie */
						if (!(strcmp(grupa[i].nazwisko, Student.nazwisko))) {
							fprintf(stdout, "Student o imieniu: %s i nazwisku %s znajduje się w grupie\n", Student.imie, Student.nazwisko);
							licznik_powtarzajacych += 1;
							licznik_student = i;
							break;
						}
						else {
							fprintf(stdout, "Student ma to samo imie, ale inne nazwisko\n");
							i += 1;
						}
					}
					}
					strcpy(grupa[licznik_student].imie, Student.imie);
					strcpy(grupa[licznik_student].nazwisko, Student.nazwisko);
/* Konwersja oceny na typ double */
char *reszta_z_konwersji;
					for (i=0; i == 4; i++) {
						if (Student.ocena[1][i] == '+') {
							j = 1;
						}
						else if (Student.ocena[1][i] == '-') {
							j = -1;
						}
					}
					oceny_grupy[liczba_studentow] = strtod(Student.ocena[1], &reszta_z_konwersji);
					strcpy(grupa[licznik_student].ocena[(grupa[licznik_student].liczba_ocen)], Student.ocena[1]);
					grupa[licznik_student].liczba_ocen += 1;
					liczba_studentow += 1;
					licznik_student += 1;
					liczba_ocen += 1;

				}
				for (i=0; i == 5; i++) {
						printf("Numer:%d\tImie: %s\n\tNazwisko: %s\n\tLiczba ocen: %d\n", i, grupa[i].imie, grupa[i].nazwisko, grupa[i].liczba_ocen);
				}
				for (i=0; i == 5; i++) {
						printf("Numer:%d\tImie: %s\n\tNazwisko: %s\n\tLiczba ocen: %d\n", i, grupa[2].imie, grupa[2].nazwisko, grupa[2].liczba_ocen);
				}

      }
  fclose(plik);

}
liczba_studentow = liczba_studentow - licznik_powtarzajacych;
for (i=0; i < liczba_studentow; i++) {
	for (j=0; j < grupa[i].liczba_ocen;j++){
fprintf(stdout, "\t Imię: %s\tNazwisko: %s\n\t Liczba ocen: %d",grupa[i].imie, grupa[i].nazwisko, grupa[i].liczba_ocen);
fprintf(stdout, "\tOceny: %s\n", grupa[i].ocena[j]);
	}}

return 0;
}
