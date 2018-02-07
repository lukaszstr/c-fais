/* Łukasz Strzelec */
# include <stdio.h>

char decipher (char a, char b) {
  char c = (a - b);
  if (c > 127) {
    c = c/2;
  }
return c;
}
