/* Łukasz Strzelec */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main()
{
  int a = 2;
  float b = 5.0; 
  double c = 7.0;
  printf("wartosc zmiennej int %d \n wartosc zmiennej float %f \n wartosc zmiennej float %f \n", a, b, c);
  double sinus = sin(b*c);
  double pierwiastek = sqrt(a);
  double cosinush = cosh(a);
/*  double urojony = sqrt(-1); */
  printf("sqrt(a) %f \n", pierwiastek);
  printf("sin(b*c) %f \n", sinus);
  printf("cosinus hiperboliczny %f \n", cosinush);
/*  printf("urojone %f \n", urojony); */
  return 0;
}
