/* Łukasz Strzelec */
# include <stdio.h>

/* Funkcja szyfruje poprzez zmianę znaku plaintextu (przeniesienie do przodu o tyle znaków ASCII ile wynosi kod ASCII odpowiadającego znaku klucza */
char cipher (char a, char b) {

  unsigned char c = a+b;  /* unsigned żeby można było porównywać 8 bitów, a nie 7) */

  if (c < 126) {  /* Przypadek kiedy przesunięcie kodu jest w zakresie drukowalnych znaków */
    return c;
  }
  else if (c > 220) {
    return (c - 220 + 32);  /* Przypadek, kiedy suma znaku wiadomości i znaku klucza jest większa niż 2 obroty zakresu znaków drukowalnych */
  }
  else {
    return (c - 126 + 32);  /* Przypadek kiedy suma znaku wiadomości i znaku klucza jest większa niż zakres. Powraca do początku znaków drukowalnych */
  }
}
/* Zakres znaków drukowalnych to (32-126) stąd odejmowanie 126 */ 
