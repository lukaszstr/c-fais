/* Łukasz Strzelec */
# include <stdio.h>

/* Funkcja szyfruje poprzez zmianę znaku plaintextu (przeniesienie do przodu o tyle znaków ASCII ile wynosi kod ASCII odpowiadającego znaku klucza */
char cipher (char a, char b) {

  unsigned char c = a+b;  /* unsigned żeby można było porównywać 8 bitów, a nie 7) */
printf("c=%c\n",c );
  if (c < 126) {  /* Przypadek kiedy przesunięcie kodu jest w zakresie drukowalnych znaków */
    return c;
  }
  else {
    c = c-94;
    if (c<126) {
      return c;
    }
    else {
      return (c-94);  /* Przypadek kiedy suma znaku wiadomości i znaku klucza jest większa niż zakres. Powraca do początku znaków drukowalnych */
    }

  }
}
/* Zakres znaków drukowalnych to (32-126) stąd odejmowanie 126 */
