/* Łukasz Strzelec */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int rwk (double a, double b, double c, double *x1, double *x2)
{
	double delta = b*b-4*a*c;
	printf("\tDelta=%g\n", delta);
	if(delta<0)
	{
		return -1;
	}
	if(delta==0)
	{
		*x1=-b/(2*a);
		return 1;
	}
	delta=sqrt(delta);
	*x1=(-b-delta)/(2*a);
	*x2=(-b+delta)/(2*a);
	return 2;
}

int main (int argc, char *argv[])
{
	double wsp_a, wsp_b, wsp_c, x1, x2;
	int status;
	char *napis = argv[1];
	sscanf(napis, "%lfx^2%lfx%lf=0", &wsp_a,&wsp_b,&wsp_c);


printf("Wprowadzono rownanie:\n\t%+gx^2%+gx%+g=0\n",wsp_a,wsp_b,wsp_c);

if (wsp_a==0)
	{
		printf("\tTo nie jest rownanie kwadratowe (a==0)\n");
		if (wsp_b==0)
		{
		printf("\tAni liniowe, podaj inne wspolczynniki a,b,c\n");
		return -1;
		}

		printf("\tJest to rownanie liniowe!\nRozwianie: x==%g\n",-wsp_c/wsp_b);
		return 3;
	}
	status = rwk(wsp_a,wsp_b,wsp_c,&x1,&x2);
	if (status == -1)
	{
		printf("\tNie ma rozwiazan rzeczywistych\n");
		return -2;
	}
	if (status == 1)
	{
		printf("\tJedno rozwiazanie podwojne\n");
		printf("\tRozwiazania rownania kwadratowego:\n\t\tx1= %g\n",x1);
		return 4;
	}
	printf("\tRozwiazania rownania kwadratowego:\n\t\tx1= %g\n\t\tx2= %g\n",x1,x2);
	return 0;

	return 0;
}