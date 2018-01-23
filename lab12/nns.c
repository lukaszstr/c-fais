/* Łukasz Strzelec */

#define _XOPEN_SOURCE  /* Dołącza funkcje z POSIX i innych? */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, char** argv) {
if (argc<3) {
  printf("Niepoprawny sposob wywolania programu. Jako argumenty wywolania podaj: 1) liczbe liczb losowych 2) rozmiar macierzy n 3) sposob dzialania programu: 0/1 (0-srand48, 1-rand)");
}
else {
int liczba_losowych, rozmiar_macierzy, mode, i; /* mode - sposób działania programu */
double macierz[rozmiar_macierzy], r;
char *error_argv1, *error_argv2, *error_argv3;
time_t t;
srand48(time(NULL));
liczba_losowych = strtol(argv[1], &error_argv1, 10 );

for (i=0; i<liczba_losowych; i++) {
  r = drand48();
  macierz[i] = r;
}

}
return 0;
}
