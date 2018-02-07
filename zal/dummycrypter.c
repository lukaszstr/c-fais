/**
    Łukasz Strzelec
    Program zaliczeniowy
    DummyCrypter
**/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argumenty, char* argv[] ) {     /*Początek funkcji main*/

/* int mode_cipher, mode_terminal;  Deklaracja zmiennych do przechowywania wybranych opcji - zwiększa czytelność kodu, przy sprawdzaniu warunków */


if (argumenty < 3) {        /* Przerwij działanie programu jeśli podano za mało argumentów */
  fprintf(stderr, "Za mało argumentów. Sposób wywołania programu:\n dymmycrypter [e/d] [f/t]\ne - szyfruj, \t d - odszyfruj,\t f - działanie na plikach,\t t - działanie w terminalu.\n" );
  fprintf(stderr, "Więcej informacji:\ndymmycrypter --help\n" );
  return -1;
}

/* Szyfrowanie w terminalu */
else if ( ( (*argv[1] == 'E') || (*argv[1] == 'e') ) && ( (*argv[2] == 't') || (*argv[2] == 'T') ) ) {
fprintf(stdout, "Wybrano szyfrowanie wiadomosci w terminalu. \nPodaj klucz do szyfrowania (zbiór znaków służący do zaszyfrowania wiadomości): \n" );
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
