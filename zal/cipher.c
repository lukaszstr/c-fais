/* Łukasz Strzelec */
# include <stdio.h>

char cipher (char a, char b) {
  char c = (a + b)/2;
  if (c > 127) {
    c = (c/2);
  }
return c;
}
