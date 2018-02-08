/* Łukasz Strzelec */
# include <stdio.h>

char decipher (char c, char b) {
    unsigned char a = c-b+94; /* unsigned żeby można było porównywać 8 bitów, a nie 7) */
    if (a>=32){
      printf("a wieksze %c-%c=%c\n", c,b,a );
      return a;
    }
    else if (a<32) {
    printf("a mniejsze %c-%c=%c\n", c,b,a );
      return (a+94);
    }
    else {
      printf("else %c-%c=%c", c,b,a );
        return a;
    }
}
