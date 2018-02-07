/**
    Łukasz Strzelec
    Program zaliczeniowy
    DummyCrypter            **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deklaracje.h"


int main (int argumenty, char* argv[] ) {     /*Początek funkcji main*/

if (argumenty < 3) {        /* Przerwij działanie programu jeśli podano za mało argumentów */
  fprintf(stderr, "Za mało argumentów. Sposób wywołania programu:\n dymmycrypter [e/d] [f/t]\ne - szyfruj, \t d - odszyfruj,\t f - działanie na plikach,\t t - działanie w terminalu.\n" );
  fprintf(stderr, "Więcej informacji:\ndymmycrypter --help\n" );
  return -1;
}

/* Szyfrowanie w terminalu */
else if ( ( (*argv[1] == 'E') || (*argv[1] == 'e') ) && ( (*argv[2] == 't') || (*argv[2] == 'T') ) ) {
fprintf(stdout, "Wybrano szyfrowanie wiadomosci w terminalu. \nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\n nie dluzszy niz 25 znakow. TYLKO STANDARDOWE ZNAKI ASCII): \n" );
fgets(Crypter.klucz, rozmiar_klucz, stdin);
fprintf(stdout, "Podano: %s\n", Crypter.klucz );
fprintf(stdout, "\nPodaj wiadomosc do zaszyfrowania: (Nie przekraczaj 1000 znakow. Uzywaj tylko znakow ASCII)\n" );
fgets(Crypter.plaintext, rozmiar_plaintext, stdin);
fprintf(stdout, "%s\n", Crypter.plaintext );
/* for(i=0; i<strlen(Crypter.plaintext); i++) {
    Crypter.encrypted[i] = cipher(Crypter.plaintext[i], '!');
} */

while (i < (strlen(Crypter.plaintext) - 1) ) {
  printf("1");
    for (j=0; j < (strlen(Crypter.klucz) - 1); j++) {
      printf("2");
      Crypter.encrypted[i] = cipher(Crypter.plaintext[i],Crypter.klucz[j]);
      i++;
    }
  }

fprintf(stdout, "Plaintext: %s\nEncrypted: %s\n", Crypter.plaintext, Crypter.encrypted );
}

/* Szyfrowanie do pliku */
else if ( ( (*argv[1] == 'E') || (*argv[1] == 'e') ) && ( (*argv[2] == 'f') || (*argv[2] == 'F') ) ) {
  fprintf(stdout, "Wybrano szyfrowanie do pliku\n" );
}

/*Odszyfrowywanie w terminalu */
else if ( ( (*argv[1] == 'D') || (*argv[1] == 'd') ) && ( (*argv[2] == 'T') || (*argv[2] == 't') ) ) {
  fprintf(stdout, "Wybrano odszyfrowywanie w terminalu\n" );
}

/* Odszyfrowywanie z plik */
else if ( ( (*argv[1] == 'D') || (*argv[1] == 'd') ) && ( (*argv[2] == 'F') || (*argv[2] == 'f') ) ) {
  fprintf(stdout, "Wybrano odszyfrowywanie wiadomości z pliku\n" );
}

else {
    fprintf(stderr, "Podałeś jako argumenty: %s  i %s\t Nieprawidlowy wybor. Sprawdz:\ndummycrypter --help\n", argv[1], argv[2] );
}

printf("LOL\n");

return 0;
}
