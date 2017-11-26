/* Łukasz Strzelec */

# include <stdio.h>
# include "bitowe.h"

int main(){

char c;
int i;
printf("Podaj jakis znak:\t");
scanf("%c", &c);
printf("\n\t");
for (i = 7; i >= 0; i--) {
      printf(" %d", get_bit(c,i));
			}
printf("\n\n");
return 0;
}

