#define rozmiar_plaintext 1000
#define rozmiar_klucz 25

char cipher(char a, char b);
char decipher(char a, char b);
int i, j;
struct crypter {char plaintext[rozmiar_plaintext]; char encrypted[rozmiar_plaintext]; char klucz[rozmiar_klucz]; } Crypter;
