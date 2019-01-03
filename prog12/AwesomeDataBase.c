/* Author: Łukasz Strzelec */
/* Program z menu, przetwarzający proste dane */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
		char imie[20];
		char nazwisko[20];
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

int compareNIWZ(const void *a, const void *b)
{
	int wyrocznia=0;
	wyrocznia = strcmp(a,b);
	if (wyrocznia)
		return 1;
	else if (wyrocznia == -1)
		return -1;
	else 
		compareINWZ(a,b);
	return -2;
}

int compareINWZ(const void *a, const void *b)
{
	return -2;
}
int compareWNIZ(const void *a, const void *b)
{
	return -2;
}
int compareZNIW(const void *a, const void *b)
{
	return -2;
}

int main()
{
	OSOBA osoba[30];
	int liczba_osob;
	while (1)
	{
		int wybor;
		char *wejscie = NULL;
		char nazwa_pliku[25];
		size_t len = 0;
		printf("\e[1;1H\e[2J"); /* clears the screen */
	/* Wyświetla menu główne */
		printf("\t PROGRAM PRZETWARZAJACY DANE \n");
		horizontal();
		printf("\t\t MENU GŁÓWNE\t\t\n");
		horizontal();
		printf("\t1. WCZYTAJ DANE Z PLIKU\n\t2. WYPISZ DANE W POSTACI TABELI\n");
		printf("\t3. SORTUJ DANE\n\t4. DODAJ OSOBĘ DO BAZY\n\t5. USUŃ OSOBĘ Z BAZY\n\t6. ZAPISZ DANE DO PLIKU\n\t7. KONIEC PROGRAMU\n");
		horizontal();
		printf("\n\nTWÓJ WYBÓR: ");
	/* Pobiera wybór i konwertuje */ 
		getline(&wejscie, &len, stdin);
		wybor = atoi(wejscie);
		#if DEBUG
		printf("Wybor= %d\n", wybor);
		#endif
	/* Menu główne */
			switch (wybor)
		{
		/* Wczytywanie pliku. Error-prone jak zły format? */
			case 1:
				printf("Podaj nazwę pliku z którego dane wczytać\t");
				scanf("%s", nazwa_pliku);
				#if DEBUG
				printf("\n\t%s\n", nazwa_pliku);
				#endif
				liczba_osob = wczytaj_osoby(nazwa_pliku, osoba);
				printf("Pomyślnie wczytano dane %d osób", liczba_osob);
				printf("\n");
				sleep(3);
				break;
		/* Wypisywanie danych. Zmienić na enter żeby wrócić do menu? */
			case 2:
				wypisz_dane(osoba, liczba_osob);
				sleep(5);
				break;
		/*Sortowanie */
			case 3:
				printf("Jak posortować dane?\n");
				printf("\t1. w/g NIWZ\n\t2. w/g INWZ\n\t3. w/g WNIZ\n\t4. w/g ZNIW\nDOKONAJ WYBORU: ");
				getline(&wejscie,&len,stdin);
				wybor = atoi(wejscie);
				switch (wybor)
				{
					case 1:
						qsort(osoba->nazwisko, liczba_osob, sizeof(osoba->nazwisko), compareNIWZ);
						break;
					case 2:
						break;
					case 3:
						break;
					case 4:
						break;
					default:
						break;
				}
				break;
			case 4:
/* nie działa zbyt ładnie -- doda wszystko co wpiszesz -- WON'TFIX? */				
				printf("Dodaje osobę na końcu tabeli");
				printf("Podaj dane w formacie:\nImie\tNazwisko\tWiek\tZarobki\n");
				printf("char[]\tchar[]\t\tint\tdouble\n");
				getline(&wejscie,&len,stdin);
				if (sscanf(wejscie, "%s %s %d %lf", osoba[liczba_osob].imie, osoba[liczba_osob].nazwisko, &osoba[liczba_osob].wiek, &osoba[liczba_osob].zarobki) == 4){
					liczba_osob++;
					printf("Dodano jako osobę nr. %d: %s %s %d %f", liczba_osob, osoba[liczba_osob-1].imie, osoba[liczba_osob-1].nazwisko, osoba[liczba_osob-1].wiek, osoba[liczba_osob-1].zarobki);
					printf("\n");
				}
				else 
					printf("Błąd! Nie podano odpowiedniej liczby danych!");
					printf("/n");
				sleep(2);
				break;
			
			case 5:
				/*sth*/
				break;
			
			case 6:
				printf("Podaj nazwę pliku w którym zapisać dane:");
				getline(&wejscie,&len-1,stdin); /* O co chodzi z tym lengthem?? !! */
				zapisz_osoby(wejscie, osoba, liczba_osob);
				printf("Pomyślnie zapisano do pliku: %s", wejscie);
				printf("\n");
				sleep(3);
				break;
			case 7:
				return 0;
			default:
				printf("Nie zrozumiano Twojego wyboru :(\nPodaj cyfre z zakresu MENU:\n");
				break;
		}
	}

	
	return 0;
}