/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
int fibonacci (int n)
{
if (n<2) 
	{
	return 1;
	}
return fibonacci(n-1)+fibonacci(n+1);
}
int main (int argc, char **argv) 
{
int n;
if (argc<2)
 	{printf("Podaj n! \n"); 
	 return 1;	
	}
n = atoi(argv[1]);
if (n<0)
	{ printf("n ma być liczbą dodatnią!");
	 return 2;
	}
printf("n=%i \n F(n)=%i \n", n, fibonnaci(n));
return 0;
}
