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

int compareNazwisko(const void *a, const void *b);
int compareImie(const void *a, const void *b);
int compareWiek(const void *a, const void *b);
int compareZarobki(const void *a, const void *b);
int compareNIWZ(const void *a, const void *b);
int compareINWZ(const void *a, const void *b);
int compareWNIZ(const void *a, const void *b);
int compareZNIW(const void *a, const void *b);
int wczytaj_osoby(char *plik, OSOBA osoba[], int *liczba_osob);
int line_counter(char *filename);
int zapisz_osoby(char *plik, OSOBA osoba[], int liczba_imion);
void horizontal();
void wypisz_dane(OSOBA osoba[], int liczba_imion);
int usun_osobe(OSOBA osoba[], int id, int liczba_osob);

