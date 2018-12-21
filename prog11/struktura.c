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

int zapisz_osoby(char *plik, OSOBA osoba[], int liczba_imion)
{
	FILE *fout = fopen(plik, "w");
	int i;
	for(i=0;i<liczba_imion;i++)
	{
		fprintf(fout, "%s %s %d %lf\n", osoba[i].imie, osoba[i].nazwisko, osoba[i].wiek, osoba[i].zarobki);
	}
	fclose(fout);
	return 0;
}
void horizontal()
{
	int i;
	for (i=0; i<80; i++)
	{
		printf("-");
	}
	printf("\n");
}

void wypisz_dane(OSOBA osoba[], int liczba_imion)
{
	int i;
	horizontal();
	printf("     | lp |        imie       |      nazwisko     |   wiek  |   zarobki   |     ");
	printf("\n");
	horizontal();
	for (i=1; i<=liczba_imion; i++)
	{
		printf("     | %2d | %-18s| %-18s|%9d|%13.2lf|\n",i, osoba[i-1].imie, osoba[i-1].nazwisko, osoba[i-1].wiek, osoba[i-1].zarobki);
	}
	horizontal();
}

int main(int argc, char *argv[])
{

	if (argc < 3) {	printf("Nie podano argumentow wywolania programu!\n"); return -1;}
	int liczba_osob=0;
	OSOBA osoba[20];
	
	liczba_osob = wczytaj_osoby(argv[1], osoba);
	/*zapisz_osoby(argv[2], osoba, liczba_osob);*/
	wypisz_dane(osoba, liczba_osob);
	
	return 0;
}