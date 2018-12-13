/* Łukasz Strzelec */

#include <stdio.h>
#include <string.h>

void minmax(char a[][15], int n, char first[], char last[])
{
	int i;
	first = a[0];
	last = a[0];
	for (i=0; i<n; i++)
	{
		if ( strcmp(first,a[i]) > 0)
		{
			strcpy(first, a[i]);
		}
		if ( strcmp(last,a[i]) < 0)
		{
			last=a[i];
		}
		printf("First: %s\t\t last: %s \n", first, last);
	}
	printf("First: %s\t\t last: %s \n", first, last);	
}

void sortuj(char a[][15], int n)
{
	char temp_imie[15];
	int i, j, k=0;
	printf("Sortuje...\n");
	for(i=n-1;i>0;i--)
	{
		for (j=0;j<i; j++)
		{
			if (strcmp(a[j],a[j+1]) > 0)
				{
					k++;
					strcpy(temp_imie, a[j+1]);
					strcpy(a[j+1],a[j]);
					strcpy(a[j],temp_imie);
				}
				
		}
	}
	printf("Dokonano %d zamian\n", k);
}

int main(int argc, char *argv[])
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout=fopen(argv[2], "w");
	char imiona[50][15], first[15], last[15];
	int liczba_imion, i;
/* wczytaj imiona */
	while(fscanf(fin, "%s", imiona[liczba_imion])==1)liczba_imion++;
	printf("imion=%d\n", liczba_imion);

/* znajdź pierwsze i ostatnie */
	minmax(imiona, liczba_imion, first, last);

/* sortuj i zapisz posortowane */	
	sortuj(imiona,liczba_imion);
	fprintf(fout, "Pierwsze wg alfabetu imie: %s\n", imiona[0]);
	fprintf(fout, "Ostatnie wg alfabetu imie: %s\n", imiona[liczba_imion-1]);
	for(i=0; i<liczba_imion; i++)
	{
		fprintf(fout, "%s\n", imiona[i]);
	} 

	fclose(fin);
	fclose(fout);
	return 0;
}