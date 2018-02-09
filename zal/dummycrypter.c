/**         Łukasz Strzelec             **
**          Program zaliczeniowy        **
**          DummyCrypter                **
**                                      **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deklaracje.h"

int main (int argumenty, char* argv[] ) {     /*Początek funkcji main*/
/* Przerwij działanie programu jeśli podano za mało argumentów */
if (argumenty < 2) {
  fprintf(stderr, "Za mało argumentów. Sposób wywołania programu:\n dymmycrypter [e/d] [f/t]\ne - szyfruj, \t d - odszyfruj,\t f - działanie na plikach,\t t - działanie w terminalu.\n" );
  fprintf(stderr, "Więcej informacji:\ndymmycrypter --help\n" );
  return -1;
}

/* Wybrano Szyfrowanie */
else if ( (*argv[1] == 'E') || (*argv[1] == 'e') ) {
  fprintf(stdout, "Wybrano szyfrowanie wiadomosci. \nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\nTYLKO STANDARDOWE ZNAKI ASCII): \n" );
  Crypter.klucz = alokator(stdin, 25);
/* Jeśli Nie podano argumentu wskazującego na nazwę pliku */
  if (argv[2] == NULL) {
    fprintf(stdout, "Chcesz zaszyfrowac wiadomosc w terminalu [t], czy wczytac wiadomość z pliku? [f]? (Pamiętaj, że wiadomość powinna składać się z 1 akapitu -- 1 wiersza)\nDokonaj wyboru [t]/[f]\n" );
    scanf(" %c", &wybor);
/* Szyfrowanie w terminalu */
    if ((wybor == 't') || (wybor == 'T'))  {
      fprintf(stdout, "Wybrano szyfrowanie wiadomosci w terminalu.\n");
      fprintf(stdout, "\nPodaj wiadomosc do zaszyfrowania: (Uzywaj tylko drukowalnych znakow ASCII)\n" );
      getchar();
      Crypter.plaintext = alokator(stdin, 250); /* Wczytaj wiadomość z stdin */
    }
/* Szyfrowanie z pliku - podaj nazwę pliku */
    else if ( (wybor == 'f') || (wybor == 'F') ) {
        fprintf(stdout, "Wybrano szyfrowanie z pliku\nPodaj nazwe pliku, z którego odczytać wiadomość\n" );
        getchar();
        filename = alokator(stdin, 20);
        FILE *odczyt = fopen(filename, "r");
        /* nie można otworzyć pliku */
        if (odczyt == NULL) {
          fprintf(stderr, "Nie można otworzyć wskazanego pliku!\nPlik o zadanej nazwie: %s, nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", filename);
          return -1;
        }
        else {      /* wczytaj wiadomość z pliku */
          getchar();
        Crypter.plaintext = alokator(odczyt, 250);
        fclose(odczyt);
      }
    }
    else {  /* Jeśli user nie poda prawidłowego znaku */
      fprintf(stderr, "Niepoprawny wybór\n");
    }
  }
  else {  /* Jeśli argument 2 istnieje, spróbuj wczytać z niego zawartość pliku */
    FILE *odczyt = fopen(argv[2], "r");
    if (odczyt == NULL) {
      fprintf(stderr, "Podałeś jako argument wywołania: %s\t Nie można otworzyć takiego pliku!. Plik nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", argv[2]);
      return -1;
    }
    else {
      getchar();
    Crypter.plaintext = alokator(odczyt, 250);
      }
    }
  Crypter.encrypted = (char*)malloc(sizeof(char) * strlen(Crypter.plaintext));  /*Zalokuj tyle pamięci ile ma wiadomość */
  /* Zaszyfruj wiadomość*/
  while (i < (strlen(Crypter.plaintext) ) ) {
    for (j=0; (j < (strlen(Crypter.klucz) ) && i < (strlen(Crypter.plaintext) ) ); j++) {
      Crypter.encrypted[i] = cipher(Crypter.plaintext[i],Crypter.klucz[j]);
      i++;
      }
    }
    /* Wyświetlanie wiadomośći i ewentualnie zapis do pliku*/
    fprintf(stdout, "\n\nZaszyfrowana wiadomosc: \n%s\n\t Chcesz ją zapisać do pliku? (Utworzy plik tekstowy 'zaszyfrowana_wiadomość.txt' w pwd) \n[t]ak/[n]ie?\n", Crypter.encrypted );
    wybor = 'a'; /* Wyzeruj wartość zmiennej na wszelki wypadek */
    scanf(" %c", &wybor);
    if (wybor == 't' || wybor == 'T') {
      FILE *zapis = fopen("zaszyfrowana_wiadomosc.txt", "w");
      if (zapis == NULL) {
        fprintf(stderr, "Nie można utworzyć pliku!\n");
        return -1;
       }
       else {
         fprintf(zapis, "Treść zaszyfrowanej wiadomości:\n%s", Crypter.encrypted);
         fprintf(stdout, "Pomyślnie utworzono plik z treścią zapisanej wiadomości.\n" );
         fclose(zapis);
       }
     }
   } /* Koniec wyboru - szyfrowanie */

/***********************************************************************************************/

/*Odszyfrowywanie w terminalu */
else if  ( (*argv[1] == 'D') || (*argv[1] == 'd') ) {
  fprintf(stdout, "Wybrano odszyfrowywanie w terminalu\nPodaj klucz użyty do zaszyfrowania wiadomości\n (TYLKO STANDARDOWE ZNAKI ASCII): \n" );
  getchar();
  Crypter.klucz = alokator(stdin, 25);
  /* Jeśli Nie podano argumentu wskazującego na nazwę pliku */
    if (argv[2] == NULL) {
      fprintf(stdout, "Chcesz odszyfrowac wiadomosc w terminalu [t], czy wczytac zaszyfrowaną wiadomość z pliku? [f]? (Pamiętaj, że wiadomość powinna składać się z 1 akapitu -- 1 wiersza)\nDokonaj wyboru [t]/[f]\n" );
      scanf(" %c ", &wybor);
      /* Odszyfrowywanie w terminalu */
      if ( (wybor == 'T') || (wybor == 't') ) {
        fprintf(stdout, "\nPodaj zaszyfrowaną wiadomość: (Uzywaj tylko drukowalnych znakow ASCII)\n" );
        getchar();
        Crypter.encrypted = alokator(stdin, 250);
      }
      /* OdSzyfrowywanie z pliku - podaj nazwę */
      else if ((wybor == 'F') || (wybor == 'f')) {
        fprintf(stdout, "Wybrano odszyfrowywanie wiadomości z pliku\n" );
        fprintf(stdout, "Podaj nazwe pliku, z którego odczytać zaszyfrowaną wiadomość\n" );
        getchar();
        filename = alokator(stdin, 20);
        FILE *odczyt = fopen(filename, "r");
        /* nie można otworzyć pliku */
        if (odczyt == NULL) {
          fprintf(stderr, "Nie można otworzyć wskazanego pliku!\nPlik o zadanej nazwie: %s, nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", filename);
          return -1;
        }
          else {      /* wczytaj wiadomość z pliku */
            getchar();
            Crypter.encrypted = alokator(odczyt, 250);
            fclose(odczyt);
          }
        }
        else {  /* Jeśli user nie poda prawidłowego znaku */
        fprintf(stderr, "Niepoprawny wybór\n");
      }
    }
      else {  /* Jeśli argument 2 istnieje, spróbuj wczytać z niego zawartość pliku */
        FILE *odczyt = fopen(argv[2], "r");
        if (odczyt == NULL) {
          fprintf(stderr, "Podałeś jako argument wywołania: %s\t Nie można otworzyć takiego pliku!. Plik nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", argv[2]);
          return -1;
        }
        else {
        getchar();
        Crypter.encrypted = alokator(odczyt, 250);
          }
        }
Crypter.plaintext = (char*)malloc(sizeof(char) * strlen(Crypter.encrypted));  /* Alokuje odpowiednią ilość pamięci */
/* OdSzyfrowywanie */
while (i < (strlen(Crypter.encrypted) ) ) {
  for (j=0; (j < (strlen(Crypter.klucz) ) && i < (strlen(Crypter.encrypted) ) ); j++) {
    Crypter.plaintext[i] = decipher(Crypter.encrypted[i],Crypter.klucz[j]);
    i++;
    }
  }
  /* Wyświetlanie wiadomości i ewentualnie zapis do pliku*/
  fprintf(stdout, "\nOdszyfrowana wiadomość: \n%s\n\n\t Chcesz ją zapisać do pliku? (Utworzy plik tekstowy 'odszyfrowana_wiadomość.txt' w pwd) \n[t]ak/[n]ie?\t", Crypter.plaintext );
  wybor = 'a'; /* Wyzeruj wartość zmiennej na wszelki wypadek */
  scanf(" %c", &wybor);
  fprintf(stdout, "\n" );
  if (wybor == 't' || wybor == 'T') {
    FILE *zapis = fopen("odszyfrowana_wiadomosc.txt", "w");
    if (zapis == NULL) {
      fprintf(stderr, "Nie można utworzyć pliku!\n");
      return -1;
     }
     else {
       fprintf(zapis, "Treść odszyfrowanej wiadomości:\n%s", Crypter.plaintext);
       fprintf(stdout, "Pomyślnie utworzono plik z treścią zapisanej wiadomości.\n" );
       fclose(zapis);
     }
   }
} /* Koniec Wyboru Odszyfrowywania */

free(Crypter.klucz);
free(Crypter.encrypted);
free(Crypter.plaintext);

return 0;
}
