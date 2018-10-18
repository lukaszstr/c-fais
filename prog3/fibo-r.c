/* Łukasz Strzelec */

#include <stdio.h>

double fibonnaci(unsigned n)
{
	if (n==0) return 0;
	else if (n==1) return 1;
	else
	{
		return fibonnaci(n-1)+fibonnaci(n-2);
	}
}

int main() 
{
	unsigned liczba;
	printf("Podaj ktory wyraz ciagu fibonnaciego chcesz obliczyc\n");
	scanf("%d",&liczba);
	printf("F(%d) = %g\n",liczba, fibonnaci(liczba));
	return 0;
}