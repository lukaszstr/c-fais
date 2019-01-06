/* Author: Łukasz Strzelec */
#include "deklaracje.h"

int compareNazwisko(const void *a, const void *b)
{
	const OSOBA *ptra = a;
	const OSOBA *ptrb = b;
	if ( strcmp(ptra->nazwisko,ptrb->nazwisko) > 0)
		return 1;
	else if ( strcmp(ptra->nazwisko, ptrb->nazwisko) < 0)
		return -1;
	else
		return 0;
}

int compareImie(const void *a, const void *b)
{
	const OSOBA *ptra = a;
	const OSOBA *ptrb = b;
	if ( strcmp(ptra->imie,ptrb->imie) > 0)
		return 1;
	else if ( strcmp(ptra->imie, ptrb->imie) < 0)
		return -1;
	else
		return 0;
}
int compareWiek(const void *a, const void *b)
{
	const OSOBA *ptra = a;
	const OSOBA *ptrb = b;
	if ( ptra->wiek > ptrb->wiek)
		return 1;
	else if ( ptra->wiek < ptrb->wiek)
		return -1;
	else
		return 0;
}
int compareZarobki(const void *a, const void *b)
{
	#if DEBUG
	printf("Porównuję zarobki!\n");
	#endif
	const OSOBA *ptra = a;
	const OSOBA *ptrb = b;
	if ( ptra->zarobki > ptrb->zarobki)
		{
		#if DEBUG
		printf("%s i %s\n",a,b);
		printf("%g>%g\n",ptra->zarobki, ptrb->zarobki);
		#endif
		return 1;
		}
		
	else if ( ptra->zarobki < ptrb->zarobki )
		{
			#if DEBUG
			printf("%s i %s\n",a,b);
			printf("%g<%g\n",ptra->zarobki, ptrb->zarobki);
			#endif
			return -1;
		}
		
	else
		return 0;
}

int compareNIWZ(const void *a, const void *b)
{
	if (compareNazwisko(a,b) == 0)
		if (compareImie(a,b) == 0)
			if (compareWiek(a,b) == 0)
				compareZarobki(a,b);
			else
				return compareWiek(a,b);
		else 
			return compareImie(a,b);
	else
		return compareNazwisko(a,b);
	return 100;
}
int compareINWZ(const void *a, const void *b)
{
	if (compareImie(a,b) == 0)
		if (compareNazwisko(a,b) == 0)
			if (compareWiek(a,b) == 0)
				compareZarobki(a,b);
			else
				return compareWiek(a,b);
		else 
			return compareNazwisko(a,b);
	else
		return compareImie(a,b);
	return 100;
}

int compareWNIZ(const void *a, const void *b)
{
	if (compareWiek(a,b) == 0)
		if (compareNazwisko(a,b) == 0)
			if (compareImie(a,b) == 0)
				compareZarobki(a,b);
			else
				return compareImie(a,b);
		else 
			return compareNazwisko(a,b);
	else
		return compareWiek(a,b);
	return 100;
}

int compareZNIW(const void *a, const void *b)
{
	if (compareZarobki(a,b) == 0)
		if (compareNazwisko(a,b) == 0)
			if (compareImie(a,b) == 0)
				compareWiek(a,b);
			else
				return compareImie(a,b);
		else 
			return compareNazwisko(a,b);
	else
		return compareZarobki(a,b);
	return 100;
}

int wczytaj_osoby(char *plik, OSOBA osoba[])
{
	FILE *fin;
	fin = fopen(plik, "r");
	int i=0;
	if (fin != NULL) 
	{
		while(fscanf(fin, "%s %s %d %lf", osoba[i].imie, osoba[i].nazwisko, &osoba[i].wiek, &osoba[i].zarobki)==4)i++;
		fclose(fin);
	}
	return i;
}

int zapisz_osoby(char *plik, OSOBA osoba[], int liczba_imion)
{
	FILE *fout = fopen(plik, "w");
	int i;
	if (fout != NULL)
	{
		for(i=0;i<liczba_imion;i++)
		{
			fprintf(fout, "%s %s %d %lf\n", osoba[i].imie, osoba[i].nazwisko, osoba[i].wiek, osoba[i].zarobki);
		}
	}
	else
		return -1;
	fclose(fout);
	return 0;
}
void horizontal()
{
	int i;
	for (i=0; i<80; i++)
	{
		printf("=");
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
int usun_osobe(OSOBA osoba[], int id, int liczba_osob )
{
	int i=0;
	for (i=id; i<(liczba_osob); i++)
	{
		strcpy(osoba[i-1].imie, osoba[i].imie);
		strcpy(osoba[i-1].nazwisko, osoba[i].nazwisko);
		osoba[i-1].wiek = osoba[i].wiek;
		osoba[i-1].zarobki = osoba[i].zarobki;
	}
	return 0;
}