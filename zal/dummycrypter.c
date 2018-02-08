/**
    Łukasz Strzelec
    Program zaliczeniowy
    DummyCrypter            **/

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
fprintf(stdout, "Wybrano szyfrowanie wiadomosci w terminalu. \nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\n nie dluzszy niz 25 znakow. TYLKO STANDARDOWE ZNAKI ASCII): \n" );
fgets(Crypter.klucz, rozmiar_klucz, stdin);
fprintf(stdout, "\n");
/* fprintf(stdout, "Podano: %s\n", Crypter.klucz ); */
fprintf(stdout, "\nPodaj wiadomosc do zaszyfrowania: (Nie przekraczaj 1000 znakow. Uzywaj tylko drukowalnych znakow ASCII)\n" );
fgets(Crypter.plaintext, rozmiar_plaintext, stdin);
/* fprintf(stdout, "%s\n", Crypter.plaintext ); */

  /* Szyfrowanie */
  while (i < (strlen(Crypter.plaintext) - 1) ) {
    printf("Pętla while i=%d\tj=%d\n", i,j);
    for (j=0; (j < (strlen(Crypter.klucz) - 1) && i < (strlen(Crypter.plaintext) - 1)); j++) {
      Crypter.encrypted[i] = cipher(Crypter.plaintext[i],Crypter.klucz[j]);
      i++;
      printf("Pętla for i=%d \t j=%d\n", i,j);
      }
    }
    /* Wyświetlanie */
    fprintf(stdout, "Plaintext: \n%s\nEncrypted: \n%s\n", Crypter.plaintext, Crypter.encrypted );
    }

/* Szyfrowanie do pliku */
else if ( ( (*argv[1] == 'E') || (*argv[1] == 'e') ) && ( (*argv[2] == 'f') || (*argv[2] == 'F') ) ) {
  fprintf(stdout, "Wybrano szyfrowanie do pliku\n" );
}

/*Odszyfrowywanie w terminalu */}

else if ( ( (*argv[1] == 'D') || (*argv[1] == 'd') ) && ( (*argv[2] == 'T') || (*argv[2] == 't') ) ) {
  fprintf(stdout, "Wybrano odszyfrowywanie w terminalu\nPodaj klucz do szyfrowania\n(zbiór znaków służący do zaszyfrowania wiadomości,\n nie dluzszy niz 25 znakow. TYLKO STANDARDOWE ZNAKI ASCII): \n" );
  fgets(Crypter.klucz, rozmiar_klucz, stdin);
  /* fprintf(stdout, "Podano: %s\n", Crypter.klucz ); */
  fprintf(stdout, "\nPodaj zaszyfrowaną wiadomość: (Nie przekraczaj 1000 znakow. Uzywaj tylko drukowalnych znakow ASCII)\n" );
  fgets(Crypter.encrypted, rozmiar_plaintext, stdin);
  /* fprintf(stdout, "%s\n", Crypter.plaintext ); */

    /* OdSzyfrowywanie */
    while (i < (strlen(Crypter.encrypted) - 1) ) {
      for (j=0; (j < (strlen(Crypter.klucz) - 1) && i < (strlen(Crypter.encrypted) - 1)); j++) {
        Crypter.plaintext[i] = decipher(Crypter.encrypted[i],Crypter.klucz[j]);
        i++;
        }
      }
      /* Wyświetlanie */
  fprintf(stdout, "Plaintext: \n%s\nEncrypted: \n%s\n", Crypter.plaintext, Crypter.encrypted );
}


/* Odszyfrowywanie z plik */
else if ( ( (*argv[1] == 'D') || (*argv[1] == 'd') ) && ( (*argv[2] == 'F') || (*argv[2] == 'f') ) ) {
  fprintf(stdout, "Wybrano odszyfrowywanie wiadomości z pliku\n" );
}

else {
    fprintf(stderr, "Podałeś jako argumenty: %s  i %s\t Nieprawidlowy wybor. Sprawdz:\ndummycrypter --help\n", argv[1], argv[2] );
}

return 0;
}
