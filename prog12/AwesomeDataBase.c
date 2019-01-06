/* Author: Łukasz Strzelec */
/* Program z menu, przetwarzający proste dane */

#include "deklaracje.h"

int main(int argc, char *argv[])
{
	OSOBA osoba[30];
	int liczba_osob;
	if (argc == 1)
		printf("Przechodzę do menu");
	else if ( !strcmp(argv[1],"--help") || !strcmp(argv[1],"--h") || !strcmp(argv[1],"help") )
	{
		printf("Prosty program przetwarzający dane osób.");
		printf("\n");
		sleep(1);
	}
	else
	{
/* program tu się wykrzacza jeśli nie znajdzie takiego pliku */		
		liczba_osob = wczytaj_osoby(argv[1], osoba);
		printf("Wczytano dane %d osób", liczba_osob);
		printf("\n");
		sleep(1);
	} 

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
				printf("Podaj nazwę pliku z którego dane wczytać:  ");
				scanf("%s", nazwa_pliku);
				#if DEBUG
				printf("\n\t%s\n", nazwa_pliku);
				#endif
				liczba_osob = wczytaj_osoby(nazwa_pliku, osoba);
				printf("Pomyślnie wczytano dane %d osób\n", liczba_osob);
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
				getline(&wejscie,&len,stdin);
				break;
/* Wypisywanie danych. Zmienić na enter żeby wrócić do menu? */
			case 2:
				wypisz_dane(osoba, liczba_osob);
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
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
						qsort(osoba, liczba_osob, sizeof(osoba[0]), compareNIWZ);
						printf("Posortowano dane\nWciśnij ENTER aby wrócić do MENU\n");
						getline(&wejscie,&len,stdin);
						break;
					case 2:
						qsort(osoba, liczba_osob, sizeof(osoba[0]), compareINWZ);
						printf("Posortowano dane\nWciśnij ENTER aby wrócić do MENU\n");
						getline(&wejscie,&len,stdin);
						break;
					case 3:
						qsort(osoba, liczba_osob, sizeof(osoba[0]), compareWNIZ);
						printf("Posortowano dane\nWciśnij ENTER aby wrócić do MENU\n");
						getline(&wejscie,&len,stdin);
						break;
					case 4:
						qsort(osoba, liczba_osob, sizeof(osoba[0]), compareZNIW);
						printf("Posortowano dane\nWciśnij ENTER aby wrócić do MENU\n");
						getline(&wejscie,&len,stdin);
						break;
					default:
						break;
				}
				break;
			case 4:
/* Dodawanie do bazy - nie działa zbyt ładnie -- doda wszystko co wpiszesz -- WON'TFIX? */				
				printf("Dodaje osobę na końcu tabeli");
				printf("Podaj dane w formacie:\nImie\tNazwisko\tWiek\tZarobki\n");
				printf("char[]\tchar[]\t\tint\tdouble\n");
				getline(&wejscie,&len,stdin);
				if (sscanf(wejscie, "%s %s %d %lf", osoba[liczba_osob].imie, osoba[liczba_osob].nazwisko, &osoba[liczba_osob].wiek, &osoba[liczba_osob].zarobki) == 4)
				{
					liczba_osob++;
					printf("Dodano jako osobę nr. %d: %s %s %d %f", liczba_osob, osoba[liczba_osob-1].imie, osoba[liczba_osob-1].nazwisko, osoba[liczba_osob-1].wiek, osoba[liczba_osob-1].zarobki);
					printf("\n");
				}
				else 
				{
					printf("Błąd! Nie podano odpowiedniej liczby danych!");
					printf("/n");
				}
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
				break;
/* Usuwanie z bazy */			
			case 5:
				printf("Podaj numer identyfikacyjny Osoby której rekord usunąć z bazy: ");
				getline(&wejscie,&len,stdin);
				usun_osobe(osoba, atoi(wejscie), liczba_osob);
				liczba_osob = liczba_osob-1;
				printf("Pomyślnie usunięto rekod z bazy\n");
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
				break;
/* Zapis danych do pliku */			
			case 6:
				printf("Podaj nazwę pliku w którym zapisać dane:");
				getline(&wejscie,&len,stdin); 
				wejscie[strlen(wejscie)-1] = '\0'; /*This dirty hacks removes the new lin char */
				zapisz_osoby(wejscie, osoba, liczba_osob);
				printf("Pomyślnie zapisano do pliku: %s\n", wejscie);
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
				break;
/* Zakończenie programu */				
			case 7:
				return 0;
			default:
				printf("Nie zrozumiano Twojego wyboru :(\nPodaj cyfre z zakresu MENU:\n");
					printf("\n");
					sleep(2);
				break;
		}
	}

	
	return 0;
}