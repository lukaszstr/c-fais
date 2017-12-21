/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>


struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;} student;

int funkcja_porownujaca (student s1, student s2) 
{ int i; i = strcmp(s1.nazwisko, s2.nazwisko);
if (!i) return 1;
return strcmp(s1.imie, s2.imie)
}

/* funkcja normalizująca nazwiska/imiona studentów */
char normalizuj (char text[30])	{
if (student.imie[1] > 90) {
	student.imie[1] -= 32;
}

/* funkcja porownujaca czy dany student to ten sam student czy nowy */
int porownaj(student s1, student s2);

/* main jest wielką pętlą */
int main (int argc, char ** argv) {
grupa[30];
int i, liczba_ocen = 0;
for (i = 1; i <= argc; i++) {
liczba_studentow = 0; srednia = 0;
FILE *plik = fopen("argv[i]", "r");
if (!plik) {
fprintf (stderr, "Blad przy otwieraniu pliku");
return 1;
}
else {
 do {
	fread(
    }
while (feof(FILE));

qsort(grupa, liczba_studentów, sizeof(student),porownaj);

suma = 0;
for (i=0; i<liczba_studentow; i++) {
	printf("%s %s:", grupa[i].nazwisko, grupa[i].imie);
for (j=0; j<=grupa[i].liczba_ocen {
	printf("%s ", grupa[i].ocena[j]);
oc = conv[grupa[i].ocena[j];
if (oc>0) {
	suma += oc;
}
else {
	bledne++
	}
	}
printf(": %f.2\n", suma/(grupa[i].liczba_ocen - bledne));
srednia += (grupa[i].liczba_ocen - bledne);
printf(" Średnia dla grupy %f.2 \n", srednia/liczba_studentow);
return 0;
}
