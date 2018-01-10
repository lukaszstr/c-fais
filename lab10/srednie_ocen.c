/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

/* Struktura studenta i bufor do normalizacji*/
struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} student;
struct student grupa[30];
char bufor[32];
double oceny_grupy[];

/*Funkcja normalizująca nazwisko i imię na polski: 1 litera - duża */
char normalizuj (char bufor [30])	{
	int i;
if (bufor[0] > 90) {
	bufor[0] -= 32;
}
else {}
/* Zamień kolejne litery imienia i nazwiska na małe znaki */
for (i=1; i<strlen(bufor); i++) {
	if (bufor[i] < 97) {
		bufor[i] += 32;
	}
}
return 0;
} /* Koniec funkcji normalizuj */

/* funkcja porównująca */
int compare (const void *s1, const void *s2 ) {
int i;
const struct student *student_s1 = s1;
const struct student *student_s2 = s2;
i = strcmp(student_s1->nazwisko, student_s2->nazwisko);
if (!i) return 1;
return strcmp(student_s1->imie, student_s2->imie);
}



/* Początek funkcji main 	*/
int main (int argc, char** argv) {

/* sprawdzenie czy program zostal prawidlowo wywolany */

if (argc<2) {
  fprintf (stderr, "Niepoprawny sposob wywolania programu.\nJako argumenty wywolania podaj nazwy plikow z ocenami.\n");
  exit(-1);
}

/* deklaracja iteratów pomocniczych i,j, liczby ocen, zmiennej ino - sprawdzającej czy w danej linii pliku znajdują się 3 byty, liczników itp, plus_minus - do konwersji oceny */
int i=0; int j=0; int liczba_ocen=0; int ino = 1; int licznik_student=0; int liczba_studentow=0; int licznik_powtarzajacych=0; int iterator_plikow; double plus_minus;
/* Pętla po plikach: */
for (iterator_plikow=1; iterator_plikow<argc; iterator_plikow++)
{
	printf("argc = %d \t argv[i]=%s\n", argc, argv[iterator_plikow]);
FILE *plik;
plik = fopen(argv[iterator_plikow], "r");
			printf("Sprawdzam plik %s\n", argv[iterator_plikow]);
/* sprawdz czy mozesz otworzyc plik */
	if (!plik)
   {
       fprintf (stderr, "Nie moge otworzyc pliku %s kod bledu: %d\n", argv[iterator_plikow], errno);
       exit(-2);
   }
/* otwarto plik, pętla po linijkach */
	else {
  	while (ino != EOF)
    {
			printf("Wczytuje dane z pliku %s\n", argv[iterator_plikow]);
      ino = fscanf(plik, "%s %s %s\n", student.imie, student.nazwisko, student.ocena[1]);
/*sprawdz czy dana linia zawiera komplet danych */
      if (ino < 3) {
        fprintf(stderr, "\nBlad.Ta linia nie zawiera kompletnych danych. Pomijam\n");
      }
      else
			{
/* Normalizacja imienia nazwiska i pętla porównująca imiona i nazwiska obecnego studenta z tymi znajdującymi się w grupie */
        normalizuj(student.imie);
        normalizuj(student.nazwisko);
				int szukacz_studenta = 0;
				while (szukacz_studenta < liczba_studentow ) {
					if (strcmp(grupa[szukacz_studenta].imie, student.imie)) {
						fprintf(stdout, "To nie ten student\n");
						szukacz_studenta += 1;
					}
					else {
/* jeśli student znajduje się w grupie */
						if (!(strcmp(grupa[szukacz_studenta].nazwisko, student.nazwisko))) {
							fprintf(stdout, "Student o imieniu: %s i nazwisku %s znajduje się w grupie\n", student.imie, student.nazwisko);
							licznik_powtarzajacych += 1;
							licznik_student = szukacz_studenta;
							break;
						}
/* Student ma to samo imię ale inne nazwisko */
						else {
							fprintf(stdout, "Student ma to samo imie, ale inne nazwisko\n");
							szukacz_studenta += 1;
						}
					}
				} /* Koniec przeszukiwania struktury szukając studenta */

/* Skopiowanie danych z tymczasowych do struktury grupy zajęciowej */
					strcpy(grupa[licznik_student].imie, student.imie);
					strcpy(grupa[licznik_student].nazwisko, student.nazwisko);
					strcpy(grupa[licznik_student].ocena[(grupa[licznik_student].liczba_ocen)], student.ocena[1]);

/* Konwersja oceny na typ double. Sprawdź czy jest znak + albo minus */
					char *reszta_z_konwersji;
					if(strchr(student.ocena[1], '+')) {
						plus_minus=0.25;
					}
					if (strchr(student.ocena[1], '-')) {
						plus_minus=-0.25;
					}
					/* Dodaj plus_minus do oceny skonwertowanej do double */
					oceny_grupy[liczba_studentow] = ( strtod(student.ocena[1], &reszta_z_konwersji) + plus_minus);
					plus_minus = 0; /* wyzerować licznik */

/* Koniec przebiegu pętli, zinkrementuj liczniki */
					grupa[licznik_student].liczba_ocen += 1;
					liczba_studentow += 1;
					licznik_student = (liczba_studentow - licznik_powtarzajacych);
					liczba_ocen += 1;
			}
      } /* Koniec działań na danym pliku z danymi */
			ino = 0; /* ustawia ino na coś innego niż EOF, żeby wejść w pętlę */
		}
/* Wyświetlanie tabeli */
for (i=0; i< liczba_studentow; i++) {
	fprintf(stdout, "%s\t\t%s\t\t%s\t%f\n",grupa[i].nazwisko, grupa[i].imie, grupa[i].ocena,i);
}
qsort(grupa, sizeof(student), liczba_studentow, compare);
fprintf(stdout, "Tabelka dla pliku: %s\n", argv[iterator_plikow] );
fprintf(stdout, "Nazwisko:\t\tImię:\t\tLista ocen:\tŚrednia ocen:\n");
for (i=0; i< liczba_studentow; i++) {
	fprintf(stdout, "%s\t\t%s\t\t%s\t%f\n",grupa[i].nazwisko, grupa[i].imie, grupa[i].ocena,i);
}
  fclose(plik);
}
/* ustawia licznik studentów na zgodny z liczbą osób */
liczba_studentow = liczba_studentow - licznik_powtarzajacych;
 /*for (i=0; i < liczba_studentow; i++) {
	for (j=0; j < grupa[i].liczba_ocen;j++){
fprintf(stdout, "\t Imię: %s\tNazwisko: %s\n\t Liczba ocen: %d",grupa[i].imie, grupa[i].nazwisko, grupa[i].liczba_ocen);
fprintf(stdout, "\tOceny: %s\n", grupa[i].ocena[j]);
			}
		}
		for (i=0; i<liczba_ocen ; i++) {
			fprintf(stdout, "oceny_grupy:%f\n",oceny_grupy[i]);
		}
		*/
return 0;
}
