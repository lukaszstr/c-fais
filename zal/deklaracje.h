#include <stdio.h>

char cipher(char a, char b);
char decipher(char c, char b);
char *alokator(FILE* fp, size_t size);
int i=0, j=0;
struct crypter {char *plaintext; char *encrypted; char *klucz; } Crypter;
