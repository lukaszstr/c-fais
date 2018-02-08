/* Łukasz Strzelec */
# include <stdio.h>

char decipher (char c, char b) {
    unsigned char a = c-b+94; /* unsigned żeby można było porównywać 8 bitów, a nie 7) */
/*      printf("%c = %c - %c + 94", a, c, b );  */
    if (a>=32 && a < 126){  /* Jeśli wynik w zakresie znaków drukowalnych */
/*      printf("\n" ); */
      return a;
    }
    else if (a<32) {    /* Kiedy a jest mniejsze -- przesunięcie z lewego końca */
  /*  printf("\t nowe a: %c \n", a+94 ); */
      return (a+94);
    }
    else { /* Kiedy a jest większe niż drukowalne przesunięcie z prawej */
  /*    printf("\t nowsze a %c", a-94 ); */
        return a-94;
    }
}
