/* Łukasz Strzelec */

int get_bit (char c, int n)
{
int maska = (1 << n);
return ((maska&c)>>n);
}

/*maska=(1<<n);
* return >>n
* return (((1<<n)&c)>>n);
* zwraca 1 jeśli n jest 1 */

