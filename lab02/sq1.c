/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main() 
{
 double a,b,c,delta,x1,x2;
 a=4; b=-4, c=2;
/* Nie ma potrzeby sprawdzać czy zmienne a,b,c są liczbami bo kompilator nie skompiluje programu jeśli nie będą */ 
 if (a==0)  { /* sprawdzić czy jest to równanie kwadratowe */
                printf("To nie jest rownanie kwadratowe!\n %.2f\n",a);
		if (b ==0) 	{ /* sprawdzic czy nie jest to rownanie sprzecze/tozsamosciowe */
				printf("A to nie jest nawet rownanie liniowe! \n b=%.2f \n Skompiluj program ponownie podajac jako wartosci zmiennych a,b lcizby rozne od 0",b); 
				}
		else 		{
				printf("Twoje rownanie jest liniowe \n Podaje rozwiazanie takiego rownania: \n x=%.2f \n",-c/b);
				}
             }
  else 	{
        delta=b*b-4.0*a*c;
        if    (delta > 0) 
		{
                x1=(-b-sqrt(delta))/(2*a);
                x2=(-b+sqrt(delta))/(2*a);
                printf("Delta wieksza od zera\n Delta=%.2f\n", delta);
                printf("Rozwiązania: \n x1=%.2f\n x2=%.2f\n", x1, x2);
                }
        else if (delta == 0) {
                printf("Delta=%.2f\n Rozwiazanie x=%.2f\n", delta, -b/(2*a));
                }
        else if (delta < 0) {
                printf("Delta mniejsza od 0\n Delta=%.2f \n", delta);
                printf("Pierwiastki zespolone:\n x1=%.2f-%.2f×i \n x2=%.2f+%.2f×i\n", ((-b)/(2*a)), sqrt(-delta)/(2*a), ((-b)/(2*a)), sqrt(-delta)/(2*a));
                }
             }
return 0;
}

