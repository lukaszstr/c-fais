/* Łukasz Strzelec */

int get_bit (char c, int n) {
int maska = (1 << n);
return ((maska&c)>>n);
}

int zero_bit(char c, int n) {
int maska = (1 << n);
return (~maska&c);
}

int set_bit (char c, int n) {
int maska = (1 << n);
return (maska|c); 
}

int flip_bit (char c, int n) {
int maska = (1 << n);
return (maska^c); 
}

/*maska=(1<<n);
* return >>n
* return (((1<<n)&c)>>n);
* zwraca 1 jeśli n jest 1 */

