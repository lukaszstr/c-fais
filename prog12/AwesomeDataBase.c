/* Author: Łukasz Strzelec */
/* Program z menu, przetwarzający proste dane */

#include "deklaracje.h"

int main(int argc, char *argv[])
{
/* Kilka deklaracji */
	int liczba_osob, databSize=30;
	char *wejscie = NULL;
	size_t len = 0;
	OSOBA osoba[databSize];
/* Sprawdza czy zostały podane jakieś argumenty wywołania programu */
	if (argc == 1)
		printf("Przechodzę do menu");
	else if ( !strcmp(argv[1],"--help") || !strcmp(argv[1],"--h") || !strcmp(argv[1],"help") )
	{
		printf("Prosty program przetwarzający dane osób.\n");
		printf("Obsługa:\nJako argument wywołania programu można podać nazwę pliku z danymi do wczytania w formacie:\nImię Nazwisko Wiek Zarobki\n\tgdzie Imię i Nazwisko może być ciągiem do %d, %d znaków, \n\tWiek liczbą całkowitą, a zarobki zmiennoprzecinkową.\n", IMIE_LEN, NAZWISKO_LEN);
		printf("\n");
		printf("Wciśnij ENTER aby wrócić do MENU\n");
		getline(&wejscie,&len,stdin);
	}
	else if ( strcmp(argv[1],"-d") || strcmp(argv[1],"--database_size"))
		{
		if (atoi(argv[2]) != 0)
			{
			databSize=atoi(argv[2]);
			printf("Zmieniono początkowy rozmiar bazy danych do %d",databSize);
			OSOBA osoba[databSize];
			printf("\n");
			sleep(2);
			}
		else
			{
			printf("Konwersja nie powiodła się, sprawdź wywołując program z flagą --help");
			printf("\n");
			sleep(3);	
			}
		}
	else
	{
		liczba_osob = wczytaj_osoby(argv[1], osoba);
		if (liczba_osob == 0)
			printf("Nie znaleziono pliku %s",argv[1]);
		else
			printf("Wczytano dane %d osób", liczba_osob);
		printf("\n");
		sleep(2);
	}
/* Wyświetla menu główne */
	while (1)
	{
		int wybor;
		printf("\e[1;1H\e[2J"); /* clears the screen */
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
/* Wczytywanie pliku */
			case 1:
				printf("Podaj nazwę pliku z którego dane wczytać:  ");
				getline(&wejscie,&len,stdin);
				#if DEBUG
				printf("\n\t%s\n", wejscie);
				#endif
				wejscie[strlen(wejscie)-1] = '\0';
				liczba_osob = wczytaj_osoby(wejscie, osoba);
				if (liczba_osob == 0)
					printf("Nie znaleziono pliku %s\n", wejscie);
				else
					printf("Pomyślnie wczytano dane %d osób\n", liczba_osob);
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
				break;
/* Wypisywanie danych */
			case 2:
				wypisz_dane(osoba, liczba_osob);
				printf("Wciśnij ENTER aby wrócić do MENU\n");
				getline(&wejscie,&len,stdin);
				break;
/*Sortowania */
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
/* Dodawanie do bazy  */	
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
				printf("Podaj nazwę pliku w którym zapisać dane:  ");
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
