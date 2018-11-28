/**         Łukasz Strzelec             **
**          Program zaliczeniowy        **
**          DummyCrypter                **
**                                      **/
#include <stdio.h>
#include "deklaracje.h"

int main (int argumenty, char* argv[] ) {     /*Początek funkcji main*/

if (argumenty < 2) {      /* Przerwij działanie programu jeśli podano za mało argumentów */
  fprintf(stderr, "Za mało argumentów. Sposób wywołania programu:\n dymmycrypter [e/d] \ne - szyfruj, \t d - odszyfruj\n" );
  fprintf(stderr, "Więcej informacji:\ndymmycrypter --help\n" );
  return -1;
}
/* *********************************************************************************** */
/* Wybrano Szyfrowanie */
else if ( (*argv[1] == 'E') || (*argv[1] == 'e') ) {
  fprintf(stdout, "Wybrano szyfrowanie wiadomosci. \nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\nTYLKO STANDARDOWE ZNAKI ASCII): \n" );
  Crypter.klucz = alokator(stdin, 25);
/* Jeśli Nie podano argumentu wskazującego na nazwę pliku */
  if (argv[2] == NULL) {
    do {    /* pętla do while dopóki user nie wybierze prawidłowo */
    fprintf(stdout, "Chcesz zaszyfrowac wiadomosc w terminalu [t], czy wczytac wiadomość z pliku? [f]? (Pamiętaj, że wiadomość powinna składać się z 1 akapitu -- 1 wiersza)\nDokonaj wyboru [t]/[f]\n" );
    scanf(" %c", &wybor);
  } while  ( (wybor != 'T') && (wybor != 't')  &&  (wybor != 'f') && (wybor != 'F') )  ;
/* Szyfrowanie w terminalu */
    if ((wybor == 't') || (wybor == 'T'))  {
      fprintf(stdout, "Wybrano szyfrowanie wiadomosci w terminalu.\n");
      fprintf(stdout, "\nPodaj wiadomosc do zaszyfrowania: (Uzywaj tylko drukowalnych znakow ASCII)\n" );
      getchar();  /*Wyczyść bufor, żeby nie czekać na 2 entery*/
      Crypter.plaintext = alokator(stdin, 250); /* Wczytaj wiadomość z stdin */
    }
/* Szyfrowanie z pliku - podaj nazwę pliku */
    else if ( (wybor == 'f') || (wybor == 'F') ) {
        fprintf(stdout, "Wybrano szyfrowanie z pliku\nPodaj nazwe pliku, z którego odczytać wiadomość\n" );
        getchar();
        filename = alokator(stdin, 20);
        odczyt = fopen(filename, "r");
        /* nie można otworzyć pliku */
        if (odczyt == NULL) {
          fprintf(stderr, "Nie można otworzyć wskazanego pliku!\nPlik o zadanej nazwie: %s, nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", filename);
          return -1;
        }
        else {      /* wczytaj wiadomość z pliku */
          fprintf(stdout, "Szyfruję wiadomość z pliku: %s\n", filename );
        Crypter.plaintext = alokator(odczyt, 250);
        fclose(odczyt);
      }
    }
  }
  else {  /* Jeśli argument 2 istnieje, spróbuj wczytać z niego zawartość pliku */
    odczyt = fopen(argv[2], "r");
    if (odczyt == NULL) {
      fprintf(stderr, "Podałeś jako argument wywołania: %s\t Nie można otworzyć takiego pliku!. Plik nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", argv[2]);
      return -1;
    }
    else {
      fprintf(stdout, "Zaszyfrowywuje wiadomość z pliku:%s\n", argv[2] );
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
      zapis = fopen("zaszyfrowana_wiadomosc.txt", "w");
      if (zapis == NULL) {
        fprintf(stderr, "Nie można utworzyć pliku!\n");
        return -1;
       }
         fprintf(zapis, "%s", Crypter.encrypted);
         fprintf(stdout, "Pomyślnie utworzono plik z treścią zapisanej wiadomości.\n" );
         fclose(zapis);
     }
   } /* Koniec wyboru - szyfrowanie */

/***********************************************************************************************/

/*Wybrano Odszyfrowywanie  */
else if  ( (*argv[1] == 'D') || (*argv[1] == 'd') ) {
  fprintf(stdout, "Wybrano odszyfrowywanie \nPodaj klucz użyty do zaszyfrowania wiadomości\n (TYLKO STANDARDOWE ZNAKI ASCII): \n" );
  Crypter.klucz = alokator(stdin, 25);
  /* Jeśli Nie podano argumentu wskazującego na nazwę pliku */
    if (argv[2] == NULL) {
      do {
      fprintf(stdout, "Chcesz odszyfrowac wiadomosc w terminalu [t], czy wczytac zaszyfrowaną wiadomość z pliku? [f]? (Pamiętaj, że wiadomość powinna składać się z 1 akapitu -- 1 wiersza)\nDokonaj wyboru [t]/[f]\n" );
      scanf(" %c", &wybor);
    }while  ( (wybor != 'T') && (wybor != 't')  &&  (wybor != 'f') && (wybor != 'F') )  ;
      /* Odszyfrowywanie w terminalu */
      if ( (wybor == 'T') || (wybor == 't') ) {
        fprintf(stdout, "Wybrano odszyfrowanie wiadomosci w terminalu.\n");
        fprintf(stdout, "\nPodaj zaszyfrowaną wiadomość: (Uzywaj tylko drukowalnych znakow ASCII)\n" );
        getchar();
        Crypter.encrypted = alokator(stdin, 250); /* Wczytaj wiadomość z stdin */
      }
      /* OdSzyfrowywanie z pliku - podaj nazwę */
      else if ((wybor == 'F') || (wybor == 'f')) {
        fprintf(stdout, "Wybrano odszyfrowywanie wiadomości z pliku\nPodaj nazwe pliku, z którego odczytać zaszyfrowaną wiadomość\n" );
        getchar();
        filename = alokator(stdin, 20);
        odczyt = fopen(filename, "r");
        /* nie można otworzyć pliku */
        if (odczyt == NULL) {
          fprintf(stderr, "Nie można otworzyć wskazanego pliku!\nPlik o zadanej nazwie: %s, nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", filename);
          return -1;
        }
          else {      /* wczytaj wiadomość z pliku */
            Crypter.encrypted = alokator(odczyt, 250);
            fclose(odczyt);
          }
        }
    }
      else {  /* Jeśli argument 2 istnieje, spróbuj wczytać z niego zawartość pliku */
        odczyt = fopen(argv[2], "r");
        if (odczyt == NULL) {
          fprintf(stderr, "Podałeś jako argument wywołania: %s\t Nie można otworzyć takiego pliku!. Plik nie istnieje, nie znajduje się w pwd, albo nie posiadasz uprawnień do odczytu\n", argv[2]);
          return -1;
        }
        else {
        fprintf(stdout, "Odszyfrowywuje wiadomość z pliku:%s\n",argv[2] );
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
    zapis = fopen("odszyfrowana_wiadomosc.txt", "w");
    if (zapis == NULL) {
      fprintf(stderr, "Nie można utworzyć pliku!\n");
      return -1;
     }
     else {
       fprintf(zapis, "%s", Crypter.plaintext);
       fprintf(stdout, "Pomyślnie utworzono plik z treścią zapisanej wiadomości.\n" );
       fclose(zapis);
     }
   }
} /* Koniec Wyboru Odszyfrowywania */
/* ************************************************************* */

else if (!strcmp(argv[1], "-h" ) || !strcmp(argv[1], "--help") ) { /* call for help */
  fprintf(stdout, "POMOC:\n.::DummyCrypter::.\nAutor:\t Łukasz Strzelec\nProgram szyfruje (lub odszyfrowywuje) wiadomość, poprzez szyfr przesuwny, tzn każdy znak wiadomości jest zmieniany na inny znak, o wartości większej o wartość znaku klucza (według tabeli ASCII).\n" );
  fprintf(stdout, "Program może działać w terminalu, lub na plikach. Istnieje możliwość zapisu efektu działania programu (wiadomości zaszyfrowanej, lub odszyfrowanej) do pliku.\n" );
  fprintf(stdout, "Do działania programu potrzebny jest klucz - ciąg znaków, będący tajnym 'hasłem', program zapyta o ten klucz po uruchomieniu.\n" );
  fprintf(stdout, "Głównym ograniczeniem działania programu jest zestaw znaków, które można użyć w wiadomości. Jest to zestaw podstawowych znaków drukowalnych ASCII. \n" );
  fprintf(stdout, "Uruchamianie-------------------------------------------------------------------\n" );
  fprintf(stdout, "dymmycrypter [e] / [d] nazwa_pliku\n" );
  fprintf(stdout, "Gdzie:\te/E - oznacza operację zaszyfrowania,\n\td/D - oznacza operację odszyfrowywania\n");
  fprintf(stdout, "\tnazwa_pliku - opcjonalnie w komendzie wywołania podać można nazwę pliku na którym będzie przeprowadzana operacja.\n" );
  fprintf(stdout, "Jeśli nie podano nazwy pliku wywołując program, ten zapyta czy pracować w terminalu - czy otworzyć plik. Użytkownik może wtedy też podać nazwę pliku z wiadomością.\n" );
  fprintf(stdout, "\n" );

}
else {
    fprintf(stdout, "Nieprawidłowe wywołanie programu. Sprawdź:\ndummycrypter --help\n" );
}

free(Crypter.klucz);
free(Crypter.encrypted);
free(Crypter.plaintext);

return 0;
}
