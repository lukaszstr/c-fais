/* Autor: Łukasz Strzelec */

#include <stdio.h>

int main()
{
	double x;
	int k;
	
	printf("Podaj liczbe calkowita: ");
	scanf("%d", &k);
	printf("Podana liczba calkowita:%d\n",k);
	printf("Podaj liczbe zmiennoprzecinkowa: ");
	scanf("%lf", &x);
	printf("Podana liczbe zmiennoprzecinkowa: %8.3f \n", x);
	printf("Iloczyn 2 liczb: %f \n", x*k);
	return 0;
}