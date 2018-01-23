/* Łukasz Strzelec */

#define _XOPEN_SOURCE  /* Dołącza funkcje z POSIX i innych? */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int porownaj (const void *a, const void *b) {
	double which;	
	which = (*(double*)a - *(double*)b);
	if (which>0) return 1;
	else if (which == 0) return 0;
	else return -1;
	}

int main (int argc, char** argv) {
if (argc<3) {
  printf("Niepoprawny sposob wywolania programu. Jako argumenty wywolania podaj: 1) liczbe liczb losowych 2) rozmiar macierzy n 3) sposob dzialania programu: 0/1 (0-srand48, 1-rand)");
}
else {
int liczba_losowych, rozmiar_macierzy, mode, i; /* mode - sposób działania programu */
char *error_argv1, *error_argv2, *error_argv3;
time_t t;
srand48(time(NULL));
liczba_losowych = strtol(argv[1], &error_argv1, 10 );
double macierz[liczba_losowych], r;

for (i=0; i<liczba_losowych; i++) {
  r = drand48();
  macierz[i] = r;
  printf(" %f ", macierz[i]);
}
printf("\n");
qsort(macierz, liczba_losowych, sizeof(double), porownaj);

for (i=0; i<liczba_losowych; i++) {
printf(" %f ", macierz[i]);
}
printf("\n");
}
return 0;
}
