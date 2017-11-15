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
	{ printf("n ma być liczbą dodatnią!\n");
	 return 2;
	}
else if (n<=2)
	{
	printf("1\n");
 	}
else 
	{
	for (i=2; i<n; i++)
	{
	fib = f1+f2;
	f1=f2;
	f2=fib;
	printf("F(%d)=%lf\n", i, fib);
    }
	}
return 0;
}

