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
if (argumenty < 3) {
  fprintf(stderr, "Za mało argumentów. Sposób wywołania programu:\n dymmycrypter [e/d] [f/t]\ne - szyfruj, \t d - odszyfruj,\t f - działanie na plikach,\t t - działanie w terminalu.\n" );
  fprintf(stderr, "Więcej informacji:\ndymmycrypter --help\n" );
  return -1;
}

/* Szyfrowanie w terminalu */
else if ( ( (*argv[1] == 'E') || (*argv[1] == 'e') ) && ( (*argv[2] == 't') || (*argv[2] == 'T') ) ) {
fprintf(stdout, "Wybrano szyfrowanie wiadomosci w terminalu. \nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\nTYLKO STANDARDOWE ZNAKI ASCII): \n" );
Crypter.klucz = alokator(stdin, 25);
fprintf(stdout, "\nPodaj wiadomosc do zaszyfrowania: (Uzywaj tylko drukowalnych znakow ASCII)\n" );
Crypter.plaintext = alokator(stdin, 250);
Crypter.encrypted = (char*)malloc(sizeof(char) * strlen(Crypter.plaintext));  /*Zalokuj tyle pamięci ile ma wiadomość */

  /* Szyfrowanie */
  while (i < (strlen(Crypter.plaintext) ) ) {
    for (j=0; (j < (strlen(Crypter.klucz) ) && i < (strlen(Crypter.plaintext) ) ); j++) {
      Crypter.encrypted[i] = cipher(Crypter.plaintext[i],Crypter.klucz[j]);
      i++;
      }
    }
    /* Wyświetlanie */
    fprintf(stdout, "\n\nZaszyfrowana wiadomosc: \n%s\n", Crypter.encrypted );
    }

/* Szyfrowanie do pliku */
else if ( ( (*argv[1] == 'E') || (*argv[1] == 'e') ) && ( (*argv[2] == 'f') || (*argv[2] == 'F') ) ) {
  fprintf(stdout, "Wybrano szyfrowanie do pliku\n" );
}

/*Odszyfrowywanie w terminalu */
else if ( ( (*argv[1] == 'D') || (*argv[1] == 'd') ) && ( (*argv[2] == 'T') || (*argv[2] == 't') ) ) {
  fprintf(stdout, "Wybrano odszyfrowywanie w terminalu\nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\n TYLKO STANDARDOWE ZNAKI ASCII): \n" );
  Crypter.klucz = alokator(stdin, 25);
  fprintf(stdout, "\nPodaj zaszyfrowaną wiadomość: (Uzywaj tylko drukowalnych znakow ASCII)\n" );
  Crypter.encrypted = alokator(stdin, 250);
  Crypter.plaintext = (char*)malloc(sizeof(char) * strlen(Crypter.encrypted));  /* Alokuje odpowiednią ilość pamięci */

    /* OdSzyfrowywanie */
    while (i < (strlen(Crypter.encrypted) ) ) {
      for (j=0; (j < (strlen(Crypter.klucz) ) && i < (strlen(Crypter.encrypted) ) ); j++) {
        Crypter.plaintext[i] = decipher(Crypter.encrypted[i],Crypter.klucz[j]);
        i++;
        }
      }
      /* Wyświetlanie */
  fprintf(stdout, "\n\nOdszyfrowana wiadomość: \n%s\n", Crypter.plaintext);
}

/* Odszyfrowywanie z plik */
else if ( ( (*argv[1] == 'D') || (*argv[1] == 'd') ) && ( (*argv[2] == 'F') || (*argv[2] == 'f') ) ) {
  fprintf(stdout, "Wybrano odszyfrowywanie wiadomości z pliku\n" );
}

else {
    fprintf(stderr, "Podałeś jako argumenty: %s  i %s\t Nieprawidlowy wybor. Sprawdz:\ndummycrypter --help\n", argv[1], argv[2] );
}
free(Crypter.klucz);
free(Crypter.encrypted);
free(Crypter.plaintext);
return 0;
}
