/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
/* # include <math.h> */
int main (int argc, char **argv) 
{
int i, n, silnia=1;
if (argc<2)
 	{printf("Podaj n! \n"); 
	 return 1;	
	}
n = atoi(argv[1]);
if (n<0)
	{ printf("n ma być liczbą dodatnią!");
	 return 2;
	}
if (n <=1)
	{printf("%i \n", 1);
	return 0;
	}
for (i=1; i<=n; i++)
	{ 
	silnia = silnia*i;
	}
printf("n=%i \n n!=%i \n", n, silnia);
return 0;
}
