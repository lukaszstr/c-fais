/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <complex.h>

int main() 
{
 double a,b,c,delta,x1,x2;
 a=4; b=-4, c="z";
 if (a>0) {
		printf("Zmienne musza byc liczbami! \n %.2f %.2f \n",a*b*c,c);
	     }
  else if ()
  {
/*	if (a == 0) {
	printf("To nie jest rownanie kwadratowe! \n"); 
		    {
	else {							*/

  	delta=b*b-4.0*a*c;
  	double complex uroj;
        if    (delta > 0) {
		x1=(-b-sqrt(delta))/(2*a);
		x2=(-b+sqrt(delta))/(2*a);
                printf("Delta wieksza od zera\n Delta=%.2f\n", delta);
                printf("Rozwiązania: \n x1=%.2f\n x2=%.2f\n", x1, x2);
                }
        else if (delta == 0) {
                printf("Delta=%.2f\n Rozwiazanie x=%.2f\n", delta, -b/(2*a));
                }
        else if (delta < 0) {
                uroj=csqrt(delta);
                printf("Delta mniejsza od 0\n Delta=%.2f \n", delta);
                printf("Rozwiazania:\n x1=%.2fi \n x2=%.2fi\n", cimag((-b-uroj)/(2*a)),cimag((-b+uroj)/(2*a)));
		printf("Testowa wartosc: %.2fi", sqrt(delta));
 		}
	     }
 }
 }
return 0;
}

