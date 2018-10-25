/* Łukasz Strzelec */
# include <stdio.h>
# include <math.h>

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

int main () 
{
	int status = 0;
	double a, b, c, x1,x2;
	printf("Program liczacy rozwiazania dwumianu kwadratowego. \nPodaj odpowiednie wspolczynniki a,b,c zgodnie ze wzorem=\tax^2+bx+c\n\tGdzie a,b,c to zmiene w postali liczb rzeczywistych\n");
	printf("Podaj rownanie: ");
	scanf("%lfx^2%lfx%lf", &a,&b,&c);
	printf("\tTwoje rownanie ma postac: \n\t\t %g * x^2 + %g * x + %g\n",a,b,c);
	if (a==0)
	{
		printf("\tTo nie jest rownanie kwadratowe (a==0)\n");
		if (b==0)
		{
		printf("\tAni liniowe, podaj inne wspolczynniki a,b,c\n");
		return -1;
		}

		printf("\tJest to rownanie liniowe!\nRozwianie: x==%g\n",-c/b);
		return 3;
	}
	status = rwk(a,b,c,&x1,&x2);
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
	
}