drand48() jako wynik daje liczbę losową w przedziale od (0,1), liczbę typu double
rand()	funkcja daje liczby całkowite <0, RAND_MAX>, działa na całkowitych.

Po wygenerowaniu próbki N, chcemy histogram wygenerować, mówiący ile jest zliczeń 
N/n

((78*liczba zliczeń w danym przedziale) / maksymalna liczba zliczeń )


Następny test: NNS (Nearest Neibhour Sorting)?

r_n wartość po posortowaniu 
r_n - r_(n-1) --z_n to na pewno nieujemna liczba, 0 =<r_n-r_(n-1) <= 1
Rozkład jest wykładniczy puasoona.

	10=<n=<100								>

pobiera 3 argumenty: liczba liczb losowych, rozmiar macierzy n i wybór metody


double *tab = (double *) malloc(N*sizeof(double))
			malloc(N*sizeof(*tab))
			malloc(N*sizeof(double))



------------------------------------------------------------

Poprzednie zajęcia:
Jak generujemy histogram?
Mnożymy liczbę losową przez liczbę przedziałów.
r*n //n liczba przedziałów
histo[r*n]++;

histo na początku trzeba wyzerować.

------------------------------------------------------------
Sensowe algorytmy sortowania liczb rzeczywistych.

Sortowanie przez zliczanie.


___Jak zamienić 2 liczby wartościami - ulubione pytanie z magisterki ____

	Bubble Sort:
void sort(int n, double *tab) {
int i,j; double t;
  for (i=0; i<n; i++) {
    for (j<(n-1); j++) {
	if(tab[i]>tab[i+1]) {
	  t = tab[i];
	  tab[i]=tab[i+1];
	  tab[i+1]=t; 
	}
    }
  }
return 0;
}
