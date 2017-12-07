int get_bitP(void* p, int n)
{ 
int charnumber = n%8; /*numer bitu */
int elementNumber=n/8; /* numer bajtu */
return get_bit((char*)p)[elementNumber],charNumber);
}

/*
for (i = sizeof(float)*8-1; i>=0; i--)
{
	printf("%d", get_bitP(&f, i));
}
*/
