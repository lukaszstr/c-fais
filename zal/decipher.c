/* Łukasz Strzelec */
# include <stdio.h>

char decipher (char a, char b) {
    unsigned char c = a-b+126-32; /* unsigned żeby można było porównywać 8 bitów, a nie 7) */
return c;
}
