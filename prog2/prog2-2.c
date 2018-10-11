/* Łukasz Strzelec */

#include <stdio.h>
#include <math.h>




int main()
{
	double x;
	printf("Podaj liczbe x: ");
	scanf("%lf", &x);
	printf("Podano liczbe: %g\n",x);
	printf("Pierwiastek: %g\nPierwiastek 3 stopnia: %g\
		Liczba do potęgi 2: %g\n",sqrt(x),cbrt(x),pow(x,2));
	return 0;
}