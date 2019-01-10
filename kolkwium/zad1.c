/* Łukasz Strzelec 	*/
/* Kolowkium		*/ 
/* Zadanie 1 		*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double silnia(int n)
{
	double wynik=1;
	int i;
	for (i=1;i<=n;i++)
	{
		wynik*=i;
	}
	/*while   */
	return wynik;
}

double sinus_tay(double x, double n)
{
	int i=0;
	double suma_szeregu=0;
	for (i=0; i<n; i++)
	{
		suma_szeregu += ( pow(-1.0,i) * ( pow(x,(2*i+1))/ silnia(2*i+1)) );
	}
return suma_szeregu;	
}

double cosinus_tay(double x, double n)
{
	int i = 0;
	double suma_szeregu = 0;
	for (i=0; i<n; i++)
	{
		suma_szeregu += ( pow(-1.0,i) * ( pow(x, 2*i) / silnia(2*i) ));
	}
return suma_szeregu;
}

int main()
{
	double x,n;
	printf("Podaj x n:");
	scanf("%lf %lf", &x, &n);
	printf("Sinus liczony szeregiem: %g\n", sinus_tay(x,n));
	printf("Sinus liczony funkcją biblioteczną: %g\n", sin(x));
	printf("======================================\n");
	printf("Cosinus liczony szeregiem: %g\n", cosinus_tay(x,n));
	printf("Cosinus liczony funkcją bibilioteczną: %g\n", cos(x));


return 0;	
}