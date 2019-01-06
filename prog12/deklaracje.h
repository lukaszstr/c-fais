/* Author: Łukasz Strzelec */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define IMIE_LEN 20
#define NAZWISKO_LEN 20

typedef struct {
		char imie[IMIE_LEN];
		char nazwisko[NAZWISKO_LEN];
		int wiek;
		double zarobki;
	} OSOBA;

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
