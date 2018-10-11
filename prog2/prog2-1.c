/* Łukasz Strzelec */
#include <stdio.h>

double f(double x) 
{
	return 2*x*x+3*x-10;
}

int main()
{
	double x;
	printf("Podaj x: ");
	scanf("%lf", &x);
	printf("F(%g)=%8.4f \n",x, f(x));
	return 0;
}