/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

/* Struktura studenta, bufor do normalizacji, struktura do zerowania studenta pomiędzy plikami*/
struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} student;
struct student grupa[30];
struct student zeruj = {0};
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
int compare (const void *p, const void *q ) {
int i;
struct student *student_s1 = (struct student *)p;
struct student *student_s2 = (struct student *)q;
i = strncmp(student_s1->nazwisko, student_s2->nazwisko, 4);
if (!i) return 1;
return strncmp(student_s1->nazwisko, student_s2->nazwisko, 4);
}

/* Konwersja oceny na typ double. Sprawdź czy jest znak + albo minus */
double konwersja_oceny (const char *ocena_x) {
	char *reszta_z_konwersji;
	if(strchr(ocena_x, '+')) {
		/* printf("\n\n\t ocena= %f \n", (strtod(ocena_x, &reszta_z_konwersji)+0.25)); */
		return ( (strtod(ocena_x, &reszta_z_konwersji)+0.25));
		}
	if (strchr(ocena_x, '-')) {
		return ( (strtod(ocena_x, &reszta_z_konwersji)-0.25));
		/* printf("\n\n\t ocena= %f \n", (strtod(ocena_x, &reszta_z_konwersji)+0.25)); */
		}
		return  (strtod(ocena_x, &reszta_z_konwersji) );
}


/* Początek funkcji main 	*/
int main (int argc, char** argv) {

/* sprawdzenie czy program zostal prawidlowo wywolany */

if (argc<2) {
  fprintf (stderr, "Niepoprawny sposob wywolania programu.\nJako argumenty wywolania podaj nazwy plikow z ocenami.\n");
  exit(-1);
}

/* deklaracja iteratów pomocniczych i,j, liczby ocen, zmiennej ino - sprawdzającej czy w danej linii pliku znajdują się 3 byty, liczników itp,  */
int i=0; int j=0; int liczba_ocen=0; int ino = 1; int licznik_student=0; int liczba_studentow=0; int licznik_powtarzajacych=0; int iterator_plikow;
/* Pętla po plikach: */
for (iterator_plikow=1; iterator_plikow<argc; iterator_plikow++)
{
	printf("argc = %d \t argv[i]=%s\n", argc, argv[iterator_plikow]);
FILE *plik;
plik = fopen(argv[iterator_plikow], "r");
			printf("Przetwarzam plik: %s\n", argv[iterator_plikow]);
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
			/*  printf("Wczytuje dane z pliku %s\n", argv[iterator_plikow]);		*/
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
						/*  fprintf(stdout, "To nie ten student\n");  	*/
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
					/*		fprintf(stdout, "Student ma to samo imie, ale inne nazwisko\n"); */
							szukacz_studenta += 1;
						}
					}
				} /* Koniec przeszukiwania struktury szukając studenta */

/* Skopiowanie danych z tymczasowych do struktury grupy zajęciowej */
					strcpy(grupa[licznik_student].imie, student.imie);
					strcpy(grupa[licznik_student].nazwisko, student.nazwisko);
					strcpy(grupa[licznik_student].ocena[(grupa[licznik_student].liczba_ocen)], student.ocena[1]);

/* Koniec przebiegu pętli, zinkrementuj liczniki */
					grupa[licznik_student].liczba_ocen += 1;
					liczba_studentow += 1;
					licznik_student = (liczba_studentow - licznik_powtarzajacych);
					liczba_ocen += 1;
/* i wyzeruj na wszelki wypadek */
					student = zeruj;
			}
      } /* Koniec działań na danym pliku z danymi */
			ino = 0; /* ustawia ino na coś innego niż EOF, żeby wejść w pętlę */
			student = zeruj;
		}
/*Sortowanie i Wyświetlanie tabeli */
qsort(grupa, liczba_studentow, sizeof(student), compare);
fprintf(stdout, "Tabelka dla pliku: %s\n", argv[iterator_plikow] );
fprintf(stdout, "Nazwisko:      \tImię:          \tLista ocen:    \tŚrednia ocen:\n");
for (i=(0+licznik_powtarzajacych); i< liczba_studentow; i++) {
	double suma;
	fprintf(stdout, "%-15s\t%-15s\t",grupa[i].nazwisko, grupa[i].imie);
	for (j=0; j<grupa[i].liczba_ocen; j++) {
		fprintf(stdout, " %-s ", grupa[i].ocena[j]);
	/*	printf("\nkonwersja oceny: %f z oceny %s \n", konwersja_oceny(grupa[i].ocena[j]), grupa[i].ocena[j]);
		printf("\nstrtod: %d\n",strtod(grupa[i].ocena[j], &suma)); */
		if (grupa[i].liczba_ocen == 1) {
			printf("\t");
			}
	suma += konwersja_oceny(grupa[i].ocena[j]);
	}
	fprintf(stdout, "\t<%3.2f>\n", suma/grupa[i].liczba_ocen);
	fprintf(stdout, "liczba ocen: %d\t suma: %f\t\n ", grupa[i].liczba_ocen, suma);
	suma = 0;
}
  fclose(plik);
	liczba_studentow = 0; licznik_student =0; licznik_powtarzajacych = 0; liczba_ocen=0;
}

return 0;
}
