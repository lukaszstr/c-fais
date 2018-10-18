/* Łukasz Strzelec */

#include <stdio.h>

double silnia (unsigned n)
{
	if (n==0) return 1.0;
	else
	{
		return silnia(n-1)*n; 
	}
	
}

int main()
{
	unsigned liczba;
	printf("Podaj liczbe ktorej silnie obliczyc\n");
	scanf("%d",&liczba);
	printf("%d! = %g\n",liczba, silnia(liczba));
	return 0;
}