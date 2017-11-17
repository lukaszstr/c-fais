/*Łukasz Strzelec */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mzero (double xl, double xp, double eps, int metoda, int *kroki);
int main (int wybor, char ** argv)
{
  if (wybor < 2) {printf("Nie wybrano metody poszukiwania miejsca zerowego.\nPodaj argument wywołania\n 0 - metoda bisekcji \n 1 - metoda stycznych\n");
      return -1;}
  else {
char u_xl[10], u_xp[10], u_eps[10]; /* stringi zachowujące input użytkownika */
double xl, xp, eps;
char *err_xl, *err_xp, *err_eps; /*zmienne pomocnicze, pozwalające wykryć błąd */
int metoda, kroki;
    printf("\nSzukacz miejsc zerowych funkcji\n");
    metoda = atoi(argv[1]);
      if (metoda == 0) {printf("Wybrano metodę bisekcji \n");}
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
    printf("\n\nxl=%g \txp=%g \teps=%g \n", xl, xp, eps);
    if (!(err_xl[0] == 0 && err_xp[0] == 0 && err_eps[0] == 0))
        {   printf("\t Konwersja do liczb nie powiodla sie \n\tPopelniono blad przy podawaniu argumentow\n\tWpisz prawidlowa liczbe przy kazdym zapytaniu o wartosc zmiennej!\n");
        }
        else
        {printf("\nMiejsce zerowe dla:\tx_0 = %g\n", mzero(xl, xp, eps, metoda, &kroki));}
            printf("\nLiczba kroków:%d\n\n\n", kroki);
        }
return 0;
}
