/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main() 
{
double a,b,c,delta,x1,x2,z;
printf("Witaj w programie liczacym rozwiazania funkcji kwadratowej\n");
z=0;
printf("Podaj wartosc wspolczynnika a: \t");
z=scanf("%lf", &a);
if (z==0)
  {
  printf("\n Blad! Prawdopodobnie wprowadzono nieznana wartosc zmiennej. \n Uruchom program ponownie, upewnij sie ze podales liczbe, a jako seperatora czesci calkowitej uzyles znaku '.' \n");
  }
else
  {z=0;
  printf("Podaj wartosc wspolczynnika b: \t");
  z=scanf("%lf", &b);
  if (z==0)
    {printf("n Blad! Prawdopodobnie wprowadzono nieznana wartosc zmiennej. \n Uruchom program ponownie, upewnij sie ze podales liczbe, a jako seperatora czesci calkowitej uzyles znaku '.' \n"); 
    } 
  else 
    {z=0;
    printf("Podaj wartosc wspolczynnika c: \t");
    z=scanf("%lf", &c);
    if (z==0)
      {printf("\n Blad! Prawdopodobnie wprowadzono nieznana wartosc zmiennej. \n Uruchom program ponownie, upewnij sie ze podales liczbe, a jako seperatora czesci calkowitej uzyles znaku '.' \n");
      }
    else
      {
      if (a==0)	/* sprawdzić czy jest to równanie kwadratowe */
        {printf("\n To nie jest rownanie kwadratowe!\n %.2f\n",a);
			if (b==0) 	/* sprawdzic czy nie jest to rownanie sprzecze/tozsamosciowe */
				{printf("\n A to nie jest nawet rownanie liniowe! \n b=%.2f \n Skompiluj program ponownie podajac jako wartosci zmiennych a,b,c lizby rozne od 0\n",b); 
				}
		else 		{
				printf("Twoje rownanie jest liniowe \n ma postac: (bx+c=0) \n Podaje rozwiazanie takiego rownania: \n x=%.2f \n",-c/b);
				}
	}
	else 
		{
		delta=b*b-4.0*a*c;
    		if (delta > 0) 
		{
                x1=(-b-sqrt(delta))/(2*a);
                x2=(-b+sqrt(delta))/(2*a);
                printf("Delta wieksza od zera\n Delta=%.2f\n", delta);
                printf("Pierwiastki rzeczywiste: \n \tx1=%.2f\n \tx2=%.2f\n", x1, x2);
                }
       		else if (delta == 0) {
                printf("Delta=%.2f\n Podwojny pierwiastek rzeczywisty:\n \tx=%.2f\n", delta, -b/(2*a));
                		     }
        	else if (delta < 0)  {
                printf("Delta mniejsza od 0\n Delta=%.2f \n", delta);
                printf("Pierwiastki zespolone:\n x1=%.2f-%.2f×i \n x2=%.2f+%.2f×i\n", ((-b)/(2*a)), sqrt(-delta)/(2*a), ((-b)/(2*a)), sqrt(-delta)/(2*a));
                		     }
		}
      }
  }
}
return 0;
}
