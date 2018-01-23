#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quickSort( int[], int, int);
int partition( int[], int, int);

int main()
{
int n=500000/2;
int table[n], i, r;
clock_t start, stop, czas_wykonania, czas_sec;
srand(time(NULL));

for (i=0; i<n; i++) {
 r=rand()%101;
 table[i]=r;
}
	/* for (i=0; i<500; i++) {
 	printf("%i\n",table[i]);
	} */
	start = clock();
	quickSort( table, 0, n);
	stop = clock();
	czas_wykonania = (stop - start) ;
	czas_sec = (long double)(czas_wykonania * 1000 / (CLOCKS_PER_SEC)) ;
	printf ("Od startu zegara uplynelo %ld jednostek\n", clock ());
  printf ("na jedna sekunde sklada sie %ld jednostek\n", CLOCKS_PER_SEC);
	printf("Start T: %ld End T: %ld \t Czas Wykonania: %ld [ms]\n ",start, stop, czas_sec);
	/*  for(i = 0; i < 501; ++i) {
		printf(" %d ", table[i]);
	} */
	printf("\n");

return 0;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r )
   {
   	/* divide and conquer */
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }

}

int partition( int a[], int l, int r) {
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