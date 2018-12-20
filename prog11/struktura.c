/* 	Łukasz Strzelec 	*/
/* 	Struktury			*/

# include <stdio.h>
# include <stdlib.h>


typedef struct {
		char imie[15];
		char nazwisko[15];
		int wiek;
		double zarobki;
	} OSOBA;

int wczytaj_osoby(char *plik, OSOBA osoba[])
{
	FILE *fin;
	fin = fopen(plik, "r");
	int i=0;
	while(fscanf(fin, "%s %s %d %lf", osoba[i].imie, osoba[i].nazwisko, &osoba[i].wiek, &osoba[i].zarobki)==4)i++;
	fclose(fin);
	return i;
}

int main(int argc, char *argv[])
{

	if (argc < 3) {	printf("Nie podano argumentow wywolania programu!"); return -1;}
	int liczba_osob=0, i;

	OSOBA osoba[20];
	FILE *fout = fopen(argv[2], "w");
	liczba_osob = wczytaj_osoby(argv[1], osoba);

/*	while(fscanf(fin, "%s %s %d %f", OSOBA.imie, OSOBA.nazwisko, &OSOBA.wiek, &OSOBA.zarobki) == 4)
		{	
			liczba_imion++;
		} */

	printf("Liczba imion: %d\n", liczba_imion);
	for (i=0;i<liczba_imion;i++)
	{
		printf("%s", osoba.imie[i]);
	}

	fclose(fout);
	return 0;
}