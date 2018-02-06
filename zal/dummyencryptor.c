/**
    Łukasz Strzelec
    Program zaliczeniowy
    DummyEncryptor
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main (int argumenty, char* argv[]) {                   /* Początek funkcji main */
char en_de, term_file;          /* Deklaracja zmiennej do wyboru działania programu - (de)kodowanie i na pliku czy w terminalu*/
int blad_wyboru=0, wybrany_szyfr; /* Zmienna wykrywajaca błędy przy wyborze sposobu działania, oraz rodzaj szyfru */
char klucz[20];                 /* Zmienna zawierajaca klucz szyfrowania */
char *blad_konwersji;
char nazwa_pliku[128];  /* zmienna na nazwę pliku */

if( (argumenty < 4) || (strcmp(argv[1],"--help") == 0) || (strcmp(argv[1],"-h") == 0) ) { /* Wyswietla pomoc jeśli źle wywołano program */
  fprintf(stderr, ".::DummyEncryptor::.\n.* Nie używaj tego programu do zastosowań innych niż rozrywkowe *.\n.* Do tych celów użyj prawdziwego szyfrowania                   *.\n.* Przykładem niech będzie gpg (The GNU Privacy Guard):         *.\n.* https://www.gnupg.org/                                       *.\n");
  fprintf(stderr, "Program ma kilka zastosowań. Możesz za jego pomocą zaszyfrować,\n  oraz odszyfrować wiadomości przy użyciu różnych szyfrów.\n  Program może pracować w terminalu, lub na plikach.\nUżytkowanie:\n----------------------------------------------------------------\ndymmyencryptor [e/d] [f/t] [1-3]\ndummyencryptor [E/D] [F/T] [1-3]\n" );
return -1;
}

else { /* Zaczyna działanie programu */
  /* konwersja argumentów */
en_de = *(argv[1]);
term_file = *argv[2];
wybrany_szyfr = strtol(argv[3], &blad_konwersji, 10);

if (en_de == 'e' || en_de == 'E') {   /* Ropzoczyna kodowanie */
  if (wybrany_szyfr == 1) {
    fprintf(stdout, "Podaj slowo jakie chcesz uzyc jako klucza szyfrowania\n(Do 20 znakow)\n" );
    scanf("%s", klucz);
  }
  else if (wybrany_szyfr == 2) {

  }
  else {
    fprintf(stderr, "Blad. Nieprawidlowy wybor. Podano:%d\n Podaj jako 2 argument cyfre odpowiadajaca wybranej metodzie kodowanie\n Wywolaj pomoc programu (dummyencryptor -- help) po wiecej informacji", wybrany_szyfr );
  }
}
else if (en_de == 'D' || en_de == 'd') {  /* Rozpoczyna odkodowywanie */
  if (wybrany_szyfr == 1) {
    fprintf(stdout, "Podaj slowo-klucz jakiego uzyto do zaszyfrowania wiadomosci\n(Nie jest dluzsze niz 20 znakow)\n" );

  }
  else if (wybrany_szyfr == 2) {

  }
  else {
    fprintf(stderr, "Blad. Podano:%d\n Nieprawidlowy wybor\n", wybrany_szyfr );
  }
}

else {
  fprintf(stderr, "Podano: %c\tBledny wybor. Podaj jako pierwszy argument 'e' lub 'E' jesli chcesz zaszyfrowac wiadomosc\n'D' lub 'd' jesli chcesz odszyfrowac\n", en_de );
  return -1;
}
}

return 0;
}
