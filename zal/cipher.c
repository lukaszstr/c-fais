/* Łukasz Strzelec */
# include <stdio.h>

/* Funkcja szyfruje poprzez zmianę znaku plaintextu (przeniesienie do przodu o tyle znaków ASCII ile wynosi kod ASCII odpowiadającego znaku klucza */
char cipher (char a, char b) {

  unsigned char c = a+b;  /* unsigned żeby można było porównywać 8 bitów, a nie 7) */
  /* printf("%c + %c = %c",a,b,c ); */
  if (c < 126) {  /* Przypadek kiedy przesunięcie kodu jest w zakresie drukowalnych znaków */
/*    printf("\n" ); */
    return c;
  }
  else {
    c = c-94;   /*Przesunięcie rozpoczętę od nowa*/
  /*  printf("\t nowe c=%c", c); */

    if (c<126) {
      printf("\n" );
      return c;
    }
    else {
  /*    printf("\tnowsze %c\n", c-94); */
      return (c-94);  /* Drugie przesunięcie, kiedy znak wiadomości i znak klucza są naprawdę duże */
    }

  }
}
/* Zakres znaków drukowalnych to (32-126) stąd odejmowanie 126 */
