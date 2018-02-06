/**
    Łukasz Strzelec
    Program zaliczeniowy
    DummyEncryptor
**/

#include <stdio.h>
#include <stdlib.h>



int main (int argumenty char ** argv) {                   /* Początek funkcji main */
char en_de, term_file;          /* Deklaracja zmiennej do wyboru działania programu - (de)kodowanie i na pliku czy w terminalu*/
int blad_wyboru, wybrany_szyfr; /* Zmienna wykrywajaca błędy przy wyborze sposobu działania, oraz rodzaj szyfru */
char[20] klucz;                 /* Zmienna zawierajaca klucz szyfrowania */


fprintf(stdout, "Chcesz zaszyforwać wiadomość, czy odszyfrować?\nWybierz sposób działania:\n(wpisz swoj wybor)\n [E] - Zaszyfruj \t [D] - Odszyfruj\n" );
blad_wyboru = scanf("%c", &en_de);
fprintf(stdout, "Podaj w jaki sposób chcesz zaszyfrować / zaszyfrowano wiadomość\n[1] -- Kod przesuwny o zadane hasło\n[2] --  \nWybierz cyfre: 1-2\n");
blad_wyboru = scanf("%d", &wybrany_szyfr);
fprintf(stdout, "Posiadasz plik z zaszyfrowana wiadomoscia/zapisac do pliku czy wybierasz dzialanie w terminalu\n" );

if (blad_wyboru == 0) {         /* Jeśli błąd */
  fprintf(stderr, "Bledny wybor\n");
  return -1;
}
if (en_de == 'e' || en_de == 'E') {   /* Ropzoczyna kodowanie */
  if (wybrany_szyfr == 1) {
    fprintf(stdout, "Podaj slowo jakie chcesz uzyc jako klucza szyfrowania\n(Do 20 znakow)\n" );
    scanf("%s", klucz)
  }
  else if (wybrany_szyfr == 2) {

  }
  else {
    fprintf(stderr, "Blad. Podano:%d\n Nieprawidlowy wybor\n", wybrany_szyfr );
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
  fprintf(stderr, "Podano: %c\tBledny wybor. Podaj e lub E jesli chcesz zaszyfrowac wiadomosc\n D lub d jesli chcesz odszyfrowac\n", en_de );
  return -1;
}

return 0;
}
