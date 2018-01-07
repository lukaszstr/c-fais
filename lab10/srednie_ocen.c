/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

/* Struktura studenta i bufor do normalizacji*/
struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} Student;
struct student grupa[30];
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

/* deklaracja iteratora i, liczby ocen, zmiennej ino - sprawdzającej czy w danej linii pliku znajdują się 3 byty */
int i=0; int j=0; int liczba_ocen=0; int ino = 1; int licznik_student=0; int liczba_studentow=0; int licznik_powtarzajacych=0; int iterator_plikow;
for (iterator_plikow=1; iterator_plikow<=argc; iterator_plikow++)
{
	printf("argc = %d \t argv[i]=%s\n", argc, argv[iterator_plikow]);
FILE *plik;
plik = fopen(argv[iterator_plikow], "r");

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
      else
			{
/* Normalizacja imienia nazwiska i pętla porównująca imiona i nazwiska obecnego studenta z tymi znajdującymi się w grupie */
        normalizuj(Student.imie);
        normalizuj(Student.nazwisko);
				int szukacz_studenta = 0;
				while (szukacz_studenta < liczba_studentow ) {
					if (strcmp(grupa[szukacz_studenta].imie, Student.imie)) {
						fprintf(stdout, "To nie ten student\n");
						szukacz_studenta += 1;
					}
					else {
/* jeśli student znajduje się w grupie */
						if (!(strcmp(grupa[szukacz_studenta].nazwisko, Student.nazwisko))) {
							fprintf(stdout, "Student o imieniu: %s i nazwisku %s znajduje się w grupie\n", Student.imie, Student.nazwisko);
							licznik_powtarzajacych += 1;
							licznik_student = szukacz_studenta;
							break;
						}
						else {
							fprintf(stdout, "Student ma to samo imie, ale inne nazwisko\n");
							szukacz_studenta += 1;
						}
					}
				}
					strcpy(grupa[licznik_student].imie, Student.imie);
					strcpy(grupa[licznik_student].nazwisko, Student.nazwisko);
					strcpy(grupa[licznik_student].ocena[(grupa[licznik_student].liczba_ocen)], Student.ocena[1]);
/* Konwersja oceny na typ double */
					char *reszta_z_konwersji;
					if(strchr(Student.ocena[1], '+')) {
						j=1;
					}
					if (strchr(Student.ocena[1], '-')) {
						j=-1;
					}
					printf("znalazłem:%d\n", j );
					oceny_grupy[liczba_studentow] = ((strtod(Student.ocena[1], &reszta_z_konwersji)) + (j/4));
					j = 0; /* wyzerować licznik */

					grupa[licznik_student].liczba_ocen += 1;
					liczba_studentow += 1;
					licznik_student = (liczba_studentow - licznik_powtarzajacych);
					liczba_ocen += 1;
			}
      }
	/* Koniec działań na danym pliku z danymi */
  fclose(plik);

}
liczba_studentow = liczba_studentow - licznik_powtarzajacych;
for (i=0; i < 5 /*liczba_studentow*/; i++) {
	for (j=0; j < grupa[i].liczba_ocen;j++){
fprintf(stdout, "\t Imię: %s\tNazwisko: %s\n\t Liczba ocen: %d",grupa[i].imie, grupa[i].nazwisko, grupa[i].liczba_ocen);
fprintf(stdout, "\tOceny: %s\n", grupa[i].ocena[j]);
			}
		}
		for (i=0; i<5; i++) {
			fprintf(stdout, "oceny_grupy:%f\n",oceny_grupy[i]);
		}
}
return 0;
}
