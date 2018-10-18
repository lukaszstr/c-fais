/* Łukasz Strzelec */
#include <stdio.h>
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

double potega(double x, int n)
{
	double wynik=1;
	int i;
	for (i=0;i<n;i++)
	{
		wynik *= x;
	}
	return wynik;
}

int main()
{
	int n,a;
	double x;
	printf("Podaj liczbe, ktorej silnie chcesz obliczyc: \n");
	scanf("%d",&n);
	printf("%d!=%g \n",n, silnia(n));
	printf("Podaj liczbe, ktorej potege chcesz obliczyc: \n");
	scanf("%lf",&x);
	printf("Podaj do ktorej potegi chcesz podniesc n: \n");
	scanf("%d",&a);
	printf("%g do potegi %d = %g\n",x,a,potega(x,a));
	printf("Biblioteczna funkcja: %g\n",pow(x,a));
	return 0;


}