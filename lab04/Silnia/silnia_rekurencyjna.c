/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
/* # include <math.h> */
double silnia (int n)
{
if (n<2) 
	{
	return 1;
	}
return n*silnia(n-1);
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
printf("n=%i \n n!=%e \n", n, silnia(n));
return 0;
}
