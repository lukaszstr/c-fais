/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
int main (int argc, char **argv)
{
int n, i, f1=1, f2=1;
double fib=2;
if (argc<2)
 	{printf("Podaj n! \n");
	 return 1;
	}
n = atoi(argv[1]);
if (n<0)
	{ printf("n ma być liczbą dodatnią!");
	 return 2;
	}
if (n<2)
	{
	printf("1\n");
  }
for (i=1; i<n; i++)
{
	fib = f1+f2;
	f1=f2;
}
printf("n=%i \n F(n)=%lf \n", n, fib);
return 0;
}

