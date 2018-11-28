/* Łukasz Strzelec */
# include <stdio.h>
# include "bitowe.h"
# include <stdlib.h>

int main (int wybor, char ** argv) {

if (wybor < 2)
{
       printf("Error \nPodaj (jako argumenty wywolania programu) czego bity chcesz wypisac:\n 0 -- znak(ASCII)\n 1 -- liczba całkowita\n 2 -- liczba typu float\n 3 -- liczba typu double \n");
return -1;
}
else {
int k,i,j,e,z;
char p;
k = atoi(argv[1]);
int tablica[64];	
union u {char z; int i; float f; double d;} u;
/* i,j - zmienne pomocnicze do pętli. k - zmienna do wyboru działania programu, e - zmienna do odpowiedniego umiejscowienia wartości bitu w tabeli */
{
if (k == 0) 
{
	printf("Podaj jakis znak:\t");
	scanf("%c", &u.z);
	z = sizeof(u.z);
}
else
{
    printf("Nieprawidlowy wybor\n");
    return -1;
}
unsigned char *wsk_bajtu ;
wsk_bajtu = (unsigned char *) &u ;

printf("rozmiar:\t%d bajt\n", z);
	for (j = 0; j < z; j++ ) 
	{
	for (i=0; i<=7; i++)
  		{
	e = i + j*8;
	tablica[e] = get_bit(*wsk_bajtu, i); 
	/* printf(" %d", get_bit(*wsk_bajtu, i)); 
	 printf("%d", tablica[e]); 			*/ 
  		}
	printf(" ");
	*wsk_bajtu++;
	}
 for (i=(z*8-1); i >= 0; i--) 
{
	printf("%d", tablica[i]);
}	
}
printf("\nZamieniamy bit? 0 / 1\t");
scanf("%d", &k);
if (k == 1) {
    /* printf("Podaj jakis znak:\t");
     * scanf("%c", &u.z);
    * z = sizeof(u.z); */
    printf("\nPodaj ktory bit podmienic na 0: \t");
    scanf("%d", &k);
    p = zero_bit( 
	for (i=z*8-1; i >= 0; i--) {
         printf("%d", tablica[i]);
                 }
}
else printf("Koniec\n");
}

printf("\n");
return 0;
}
