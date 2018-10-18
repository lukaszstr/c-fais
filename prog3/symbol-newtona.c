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

double sn (unsigned n,unsigned k)
{
	return (silnia(n)/(silnia(k)*silnia(n-k)));
}

double dn (unsigned n, unsigned )

int main()

{	unsigned n,k;
	printf("n = ");
	scanf("%d", &n);
	printf("k = ");
	scanf("%d", &k);
	if (n<k) 
	{
		printf("n musi byc wieksze od k\n");
		return -1;
	}
	printf("SN(%d,%d) = %g \n",n,k,sn(n,k));

	return 0;

}