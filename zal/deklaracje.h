/* Łukasz Strzelec - deklaracje pozwalające zwiększyć czytelność kodu w main */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Deklaracje funkcji (de)/szyfrującej */
char cipher(char a, char b);
char decipher(char c, char b);
/* Deklaracja funkcji odczyytującej dane, wraz z dynamiczną alokacją pamięci */
char *alokator(FILE* fp, size_t size);
/* Deklaracje zmiennych */
int i=0, j=0;
struct crypter {char *plaintext; char *encrypted; char *klucz; } Crypter;
char *filename;
char wybor;
FILE *zapis, *odczyt;
