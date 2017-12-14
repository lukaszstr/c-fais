/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <string.h>


struct student { char imie [30]; char nazwisko [32]; char ocena [30][4]; int liczba_ocen;};
int main (int argc, char ** argv) {
int i, liczba_ocen = 0;
for (i = 1; i <= argc; i++) {
FILE *plik = fopen("argv[i]", "r");
if (!plik) {
fprintf (stderr, "Blad przy otwieraniu pliku");
return 1;
}


}
return 0;
}


