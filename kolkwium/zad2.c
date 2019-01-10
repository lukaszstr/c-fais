/* Łukasz Strzelec 	*/
/* Kolowkium		*/ 
/* Zadanie 2 		*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringcopier(char *a, char *b)
{
	int i=0;
	int len = sizeof(a)/sizeof(char);
	for (i=0; i<=len-1; i++)
	{
		b[i] = a[i];
	}
	return 0;
}

int stringcomparator(char *a, char *b)
{
	int i=0;
	int len = 0;

	if(sizeof(a)>sizeof(b))
		len = sizeof(a)/sizeof(char);
	else
		len = sizeof(b)/sizeof(char);

	for (i=0; i<=len-1; i++)
	{
		/*printf("a=%c, b=%c\n",a[i], b[i]);*/
		if ( a[i] < b[i] )
			return 1;
		else if (a[i] > b[i])
			return -1;
		else
			printf("");
	}
	return 0;
}

int main() 
{
	char a[100];
	char b[100];
	printf("Podaj ciag znaków do skopiowania: ");
	scanf("%s", a);
	printf("Wpisano: %s\n", a);
	stringcopier(a,b);
	printf("Skopiowano: %s\n", b);

	printf("Podaj ciąg znaków do porównania: \n");
	scanf("%s", b);

	if (stringcomparator(a,b) == 1)
		printf("Pierwszy w porządku jest łańcuch: %s\n", a);
	else if (stringcomparator(a,b) == -1)
		printf("Pierwszyw porządku jest łańcuch %s\n", b);
	else
		printf("Oba łańcuchy są tego samego porządku\n");

	if (strcmp(a,b) < 0)
		printf("Wg strcmp: %s\n", a);
	else if (strcmp(a,b) > 0)
		printf("Wg strcmp: %s\n", b);
	else 
		printf("Wg strcmp oba są tego samego porzadku\n");
	return 0; 
}