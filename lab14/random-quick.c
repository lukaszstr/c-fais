#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort( int[], int, int);
int podziel( int[], int, int);

/* funkcja porównująca dla quicksorta */
int porownaj (const void *a, const void *b) {
	int which;
	which = (*(int*)a - *(int*)b);
	if (which>0) return 1;
	else if (which == 0) return 0;
	else return -1;
	}

  /* Początek funkcji main */
  int main (int argc, char** argv) {
  /* Wyświetl komunikat o błędzie, jeśli nie podano 3 zmiennych */
  if (argc<3) {
    printf("Niepoprawny sposob wywolania programu. Jako argumenty wywolania podaj: 1) liczbe liczb losowych 2) liczbe przedzialow 3) sposob dzialania programu: 0/1 (0-quicksort z biblioteki, 1-quicksort z własnej implementacji)");
  }
  else {
  int liczba_losowych, przedzialy, mode, i; /* mode - sposób działania programu */

  /* Konwersja argumentów wywołania programu */
  char *error_argv1, *error_argv2, *error_argv3;
  liczba_losowych = strtol(argv[1], &error_argv1, 10 );
  przedzialy =  strtod(argv[2], &error_argv2);
  mode = strtol(argv[3], &error_argv3, 10 );
  	if ((error_argv1 || error_argv2 || error_argv3) == 0) {
  		printf("Error. Konwersja nie powiodla sie, podaj jako argumenty wywolania programu liczby calkowite\n");
  		printf("argv[1]=%s argv[2]=%s argv[3]=%s\n", error_argv1, error_argv2, error_argv3 );
  		return -1;
  	}
  	else {

  /* Deklaracja macierzy i czasów wykonania */
  int macierz[liczba_losowych], r;
  clock_t start, stop, czas_wykonania, czas_sec;
  srand(time(NULL));

  /* Generacja macierzy liczb pseudolosowych z użyciem rand */
   for (i=0; i<liczba_losowych; i++) {
     r = rand()%1000;
     macierz[i] = r;
     }

  /* Sortowanie z użyciem qsort systemowy */
  if (mode == 0) {
    /* sortowanie i pomiar czasu */
    start = clock();
    qsort(macierz, liczba_losowych, sizeof(int), porownaj);
    stop = clock();
    czas_wykonania = (stop - start);
    czas_sec = (long double)(czas_wykonania * 1000000 / (CLOCKS_PER_SEC));
    printf("Czas wykonania sortowania %d-liczb: %ld [microsec]\n", liczba_losowych, czas_sec);
    }
  else if (mode == 1) {
    start = clock();
    quickSort(macierz, 0, liczba_losowych);
    stop = clock();
    czas_wykonania = (stop - start);
    czas_sec = (long double)(czas_wykonania * 1000000 / (CLOCKS_PER_SEC));
    printf("Czas wykonania sortowania %d-liczb: %ld [microsec]\n", liczba_losowych, czas_sec);
    }
  else return -1;
  printf("\n");

  /* Próbne wyświetlenia */
  /* for (i=0; i<liczba_losowych; i++) {
    printf(" %f ", macierz[i]);
  }										*/

  /* Zliczenia */
  /* Wyzeruj tablicę liczby zliczeń */
  int liczba_zliczen[przedzialy];
  for (i=0; i<=(przedzialy +1); i++) {
    liczba_zliczen[i] = 0;
    }

    int j;
    i = 0;
    for (j=1; j<=przedzialy; j++) {
      while ((macierz[i] <= (1000/przedzialy) * j) && i<liczba_losowych) {
  /*    printf("i= %d\tmacierz[i]= %f\tprzedzial= %f\n", i, macierz[i], (double) 1/przedzialy*j ); */
        liczba_zliczen[j] = liczba_zliczen[j] + 1 ;
        i++;
      }
    }

  /* Wyświetlanie liczby zliczeń w danych przedziałach */
  /* printf("\nLiczba zliczen w przedziale:\n");
  for (i=1; i<=przedzialy; i++) {
    printf(" %d = %d\n", i, liczba_zliczen[i]);
  }			*/

  /* Histogram */
  /* Znajdż max_zliczen */
  int max_zliczen = 0;
  for (i=0; i<przedzialy; i++) {
  	if (max_zliczen < liczba_zliczen[i]) {
  		max_zliczen = liczba_zliczen[i];
  	}
  }
  /* printf("max_zliczen=%d\nPrzedzial: \n",max_zliczen ); */
  /* Wyświetl histogram */
  for (i=1; i<=przedzialy; i++) {
  	printf("%d:\t", i);
  	int histo_dl = (78*liczba_zliczen[i])/max_zliczen;

  	  for (j=0; j<=histo_dl; j++) {
  		  printf("#");
  	  }
  	printf("\n" );
  }
   } /* koniec else po konwersji */

  printf("\n");
  } /* Koniec else po wywolaniu */
  return 0;
  }

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r )
   {
        j = podziel( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
}

int podziel( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;

   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}
