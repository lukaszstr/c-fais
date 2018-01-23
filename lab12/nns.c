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
int liczba_losowych, przedzialy, mode, i; /* mode - sposób działania programu */

char *error_argv1, *error_argv2, *error_argv3;
liczba_losowych = strtol(argv[1], &error_argv1, 10 );
przedzialy =  strtod(argv[2], &error_argv2);
mode = strtol(argv[3], &error_argv3, 10 );

double macierz[liczba_losowych], r;
clock_t start, stop, czas_wykonania, czas_sec;

if (mode == 0) {
srand48(time(NULL));
  for (i=0; i<liczba_losowych; i++) {
  r = drand48();
  macierz[i] = r;
  /*  printf(" %f ", macierz[i]); */
  }
}
else if (mode == 1) {
 srand(time(NULL));
  for (i=0; i<liczba_losowych; i++) {
    r = (double)rand()/(double)((unsigned)RAND_MAX + 1);
    macierz[i] = r;
    }
}
else return -1;
printf("\n");
start = clock();
qsort(macierz, liczba_losowych, sizeof(double), porownaj);
stop = clock();
czas_wykonania = (stop - start);
czas_sec = (long double)(czas_wykonania * 1000000 / (CLOCKS_PER_SEC));
printf("Czas wykonania sortowania %d-liczb: %ld [microsec]\n", liczba_losowych, czas_sec);
/* for (i=0; i<liczba_losowych; i++) {
  printf(" %f ", macierz[i]);
  }				*/

/* Zliczenia */
int liczba_zliczen[przedzialy];
for (i=0; i<=przedzialy; i++) {
  liczba_zliczen[i] = 5;
  }
int j;
i = 0;
for (j=1; j<=przedzialy; j++) {
  while (macierz[i] <= ((double) 1/przedzialy) * j) {
/*    printf("\nprzedzial= %f\n", (double) 1/przedzialy*j ); */
    liczba_zliczen[j] = liczba_zliczen[j] + 1 ;
/*    printf("petla while, przebieg %d", i);	*/
    i++; 
    }
  }
printf("\nLiczba zliczen w przedziale:\n");
for (i=1; i<przedzialy; i++) {
  printf(" %d = %d\n", i, liczba_zliczen[i]);
  }

printf("\n");
}
return 0;
}
