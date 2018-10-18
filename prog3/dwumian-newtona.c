/* Łukasz Strzelec */

#include <stdio.h>
#include <math.h>

double silnia (unsigned n)
{
	if (n==0) return 1.0;
	else
	{
		return silnia(n-1)*n; 
	}
	
}

double lewastrona(double a, double b, unsigned n)
{
	return pow(a+b,n);
}

double sn (unsigned n,unsigned k)
{
	return (silnia(n)/(silnia(k)*silnia(n-k)));
}

double dn (double a, double b, unsigned n)
{
			int i;
			double wynik=0.0;
			for (int i = 0; i <= n; i++)
			{
				printf(" %g +",(sn(n,i) * pow(a,i) * pow(b, n-i)) );
				wynik += sn(n,i) * pow(a,i) * pow(b, n-i);
			}
               printf(" = %g", wynik);
			return (sn(n,n)*pow(a,n)*pow(b,n-n));
}

int main()

{	unsigned n;
	double a,b;
	printf("a = ");
	scanf("%lf", &a);
	printf("b = ");
	scanf("%lf", &b);
	printf("n = ");
	scanf("%d", &n);
/*	if (n<k) 
	{
		printf("n musi byc wieksze od k\n");
		return -1;
	}
*/
	printf("DN(%d,%d)^%d = ",a,b,n);
	dn(a,b,n);
	printf(" \n ");
	printf("(%d+%d)^%d = %g\n",a,b,n, lewastrona(a,b,n));

	return 0;

}