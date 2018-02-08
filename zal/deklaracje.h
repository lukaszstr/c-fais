#define rozmiar_plaintext 1000
#define rozmiar_klucz 25

char cipher(char a, char b);
char decipher(char c, char b);
int i=0, j=0;
struct crypter {char plaintext[rozmiar_plaintext]; char encrypted[rozmiar_plaintext]; char klucz[rozmiar_klucz]; } Crypter;
