/* 	Łukasz Strzelec				*
*	suma(od 1 do n) sin(ka) = 
*	(sin(n+1)/2*a)sin(n/2*a))/(sin(a/2))
*	
*								*/

#include <stdio.h>
#include <math.h>

double lewastrona(double a, double n)
{
	int i;
	double wynik_lewejstrony=0.0;
	for (i=1; i<=n; i++)
	{
		wynik_lewejstrony=wynik_lewejstrony+sin(i*a);
	}
	return wynik_lewejstrony;
}

double prawastrona (double a, double n)
{
			return ((sin((n+1)/2*a) * sin(n/2*a)) / sin(a/2));
}

int main()
{	double a,n;
	printf("Podaj wsp. a = ");
	scanf("%lf", &a);
	printf("Podaj wspolczynnik n = ");
	scanf("%lf", &n);

	printf("sigma do %g z(sin(%g)) = (sin(%g*%g)*sin(%g*%g)/(sin(%g))\n",n, a, ((n+1)/2), a, n/2, a, a/2);
	printf("Lewa strona = %g\n", lewastrona(a,n));
	printf("Prawa strona = %g\n", prawastrona(a,n));
	printf("\n");

	return 0;

}
