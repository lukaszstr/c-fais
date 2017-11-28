/* Łukasz Strzelec */

# include <stdio.h>
# include "bitowe.h"
# include <stdlib.h>

int main (int wybor, char ** argv) {
int i,k;
if (wybor < 2)
{
       printf("Error \nPodaj (jako argumenty wywolania programu) czego bity chcesz wypisac:\n 0 -- znak(ASCII)\n 1 -- liczba całkowita\n 2 -- liczba typu float\n 3 -- liczba typu double \n");
return -1;
}
else {
k = atoi(argv[1]);
union u {char z; int i; float f; double d;} u;
 if (k == 0)
 {
     printf("Wpisz jakiś znak:\t");
    scanf("%c", &u.z);
    printf("Wprowadzono:\t%c\n", u.z);
    for (i = 7; i >= 0; i--)
    {
              printf(" %d", get_bit(u.z,i));
    }
}
else if(k == 1)
{
    printf("Podaj jakas liczbe calkowita:\t");
    scanf("%d", &u.i);
    printf("Wprowadzono:\t%d\n", u.i);
/*for (j=1; j>=0; j--) {*/
	for (i=15; i>=0; i--)
  {
	printf(" %d", get_int_bit(u.i, i));
  }
}
else if (k == 2)
{
    printf("Podaj liczbe typu float:\t");
    scanf("%f", &u.f);
    printf("Wprowadzono: \t%f\n", u.f);
  /*  int *b=0;
    b = &u.f;  */
    for (i=31; i>=0; i--)
    {
        printf("%f", get_float_bit(u.f, i));
    }
}
else if (k == 3)
{
    printf("Podaj liczbe typu double:\t");
    scanf("%lf", &u.d);
    printf("\n");
}
else
{
    printf("Nieprawidlowy wybor\n");
    return -1;
}
}
printf("\n");
return 0;
}
