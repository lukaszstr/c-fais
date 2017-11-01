/* Łukasz Strzelec */
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main() 
{
double a,b,c,delta,x1,x2,k,z;
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
      delta=b*b-4.0*a*c;
      printf("\n Wartosci zmiennych a=%.2f b=%.2f c=%.2f \n Δ=%.2f \n", a,b,c,delta);
      if (a==0)	/* sprawdzić czy jest to równanie kwadratowe */
        {printf("\n To nie jest rownanie kwadratowe!\n %.2f\n",a);
			if (b==0) 	/* sprawdzic czy nie jest to rownanie sprzecze/tozsamosciowe */
				{printf("\n A to nie jest nawet rownanie liniowe! \n b=%.2f \n Skompiluj program ponownie podajac jako wartosci zmiennych a,b,c lizby rozne od 0\n",b); 
				}
		else 		{
				printf("Twoje rownanie jest liniowe \n ma postac: (bx+c=0) \n Podaje rozwiazanie takiego rownania: \n x=%.2f \n",-c/b);
				}
	}
	else {}
      }
  }
}
return 0;
}
