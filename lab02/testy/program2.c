/* Łukasz Strzelec */ 

# include <stdio.h>
# include <stdlib.h>

int main()
{
  int a = 2;
  float b = 5.0; 
  double c = 7.0;
  printf("wartosc zmiennej int %d \n wartosc zmiennej float %f \n wartosc zmiennej float %f \n", a, b, c);
  printf("wynik dodawania a+b %f \n",a+b);
  printf("wynik odejmowania b-c %lf \n", b-c);
  printf("iloczyn c*a %lf \n",c*a);
  printf("iloraz a/c %lf \n", a/c);
return 0;
}
