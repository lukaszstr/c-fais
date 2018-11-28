/* Łukasz Strzelec */

# include <stdio.h>
# include "bitowe.h"
# include <stdlib.h>

int main (int wybor, char ** argv) {

int i,z,k;
char a,b;
if (wybor < 2)
{
       printf("Error \nPodaj (jako argumenty wywolania programu) Jaka operacje chcesz wykonac\n\t0 - zero_bit\n\t1-set_bit\n\t2-flip_bit\n");
return -1;
}
else {
z = atoi(argv[1]);
printf("podaj znak:\t");
scanf("%c", &a);
	for (i=7; i>=0;i--) {
	printf("%d", get_bit(a, i));
	}
printf("\n");
printf("Ktory bit zmienic? (0-7)");
scanf("%d", &k);
if (z == 0) {
	b = zero_bit(a,k);
	}
else if (z == 1) {
	b = set_bit(a,k);
	}
else if (z == 2) {
	b = flip_bit(a,k);
	}
else printf("Zły wybór");
printf("\tNowy znak to:\t\n\t%c\n", b);
	for (i=7; i>=0; i--) {
	printf("%d", get_bit(b, i));
	}
printf("\n");
}
return 0;
}
