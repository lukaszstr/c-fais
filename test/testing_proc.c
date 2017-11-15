/*Łukasz Strzelec */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func (double x)
{
    /*   x-2e:^(2x^2+5) */
    return  (-1 + 3*x + 5*x*x);
}
double mzero (double xl, double xp, double eps, int metoda, int kroki)
{ /* w ten sposob nie da sie wyciagnac liczby krokow */
double xm, fm, fl, fp;
/* do tej pory są ponoć 2 błędy */
fl = func(xl);
fp = func(xp);
kroki = 0;
if (fl * fp == 0)
	{
	 if (fl == 0)
		{
		 return xl;
		}
	else
		{
		 return xp;
		}
	}
if (fl * fp > 0)
	{
	 kroki = -1;
	 return xp;
	}
else	{
/*	while (fabs(fm) > eps && fabs (xp-xl)/fabs(xm) */
	do {
		if (metoda == 0)
			{
			xm = 0.5 * (xl + xp); /* mnożenie 0.5 to shift binarny */
    			}
    		else
			{
			xm = (fp * xl - fl * xp)/(fp - fl);
			kroki++;
			}
    	fm = func(xm);
    	if (fm == 0) { return xm; }
    	if (fm * fp < 0) { xl = xm; fl = fm; }
    	else { xp = xm; fp = fm; }
	}while (fabs(fm) > eps && fabs (xp-xl / xm) > eps);
    		}
return xm;
}
int main (int wybor, char ** argv)
{
  if (wybor < 2) {printf("Nie wybrano metody poszukiwania miejsca zerowego.\nPodaj argument wywołania\n 0 - metoda siecznych \n 1 - metoda stycznych\n");
      return -1;}
  else {
char u_xl[10], u_xp[10], u_eps[10]; /* stringi zachowujące input użytkownika */
double xl, xp, eps;
char *err_xl, *err_xp, *err_eps; /*zmienne pomocnicze, pozwalające wykryć błąd */
int metoda, kroki = 0;
    printf("Szukacz miejsc zerowych funkcji\n");
    metoda = atoi(argv[1]);
      if (metoda == 0) {printf("Wybrano metodę siecznych \n");}
      else {printf("Wybrano metodę stycznych \n");}
    printf("Podaj lewy zakres:\t");
    scanf("%s", u_xl);
    printf("\nPodaj prawy zakres:\t");
    scanf("%s", u_xp);
    printf("\nPodaj wartość współczynnika Epsilion:\t");
    scanf("%s", u_eps);
    xl = strtod(u_xl, &err_xl);
    xp = strtod(u_xp, &err_xp);
    eps = strtod(u_eps, &err_eps);
    printf("xl=%g \txp=%g \teps=%g \n", xl, xp, eps);
    if (!(err_xl[0] == 0 && err_xp[0] == 0 && err_eps[0] == 0))
        {   printf("\t Konwersja do liczb nie powiodla sie \n\tPopelniono blad przy podawaniu argumentow\n\tWpisz prawidlowa liczbe przy kazdym zapytaniu o wartosc zmiennej!\n");
        }
        else
        {printf("Miejsce zerowe:\t%lf", mzero(xl, xp, eps, metoda, kroki));
    }}
return 0;
}
