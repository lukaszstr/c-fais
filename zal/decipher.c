/* Łukasz Strzelec - Funkcja odszyfrowywująca kod przestawieniowy*/
# include <stdio.h>

/* Funkcja pobiera znak zaszyfrowanej wiadomości i odpowiadający znak klucza */
char decipher (char c, char b) {
    unsigned char a = c-b+94; /* unsigned żeby można było porównywać 8 bitów, a nie 7) */
    if (a>=32 && a < 126){  /* Jeśli wynik w zakresie znaków drukowalnych */
      return a;
    }
    else if (a<32) {    /* Kiedy a jest mniejsze -- przesunięcie z lewego końca */
      return (a+94);
    }
    else { /* Kiedy a jest większe niż drukowalne przesunięcie z prawej */
        return a-94;
    }
}
