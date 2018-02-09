/* Łukasz Strzelec - Funkcja szyfrująca przestawieniowo*/
# include <stdio.h>

/* Funkcja szyfruje poprzez zmianę znaku plaintextu (przeniesienie do przodu o tyle znaków ASCII ile wynosi kod ASCII odpowiadającego znaku klucza */
char cipher (char a, char b) {
  unsigned char c = a+b;  /* unsigned żeby można było porównywać 8 bitów, a nie 7, suma czasem jest większa niż 128 - potrzebny więc 8 bit) */
  if (a < 32) {
	return a;
	}	
  else if (c < 126) {  /* Przypadek kiedy przesunięcie kodu jest w zakresie drukowalnych znaków */
    return c;
  }
  else {
    c = c-94;   /*Przesunięcie rozpoczętę od nowa*/
    if (c<126) {
      return c;
    }
    else {
      return (c-94);  /* Drugie przesunięcie, kiedy znak wiadomości i znak klucza są naprawdę duże */
    }

  }
}
/* Zakres znaków drukowalnych to (32-126) stąd odejmowanie 126 */
