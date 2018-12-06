/* Łukasz Strzelec */ 

#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

void szukacz(int n, int a[], int *min, int *max);
int main ()
{
	
	/* napisać funkcję co wpisze min i max */
	int status, i=0, ilosc_elementow=0, min, max; 
	int tablica_1[20];

	FILE *fin, *fout;
	fin=fopen("dane.dat","r");
	fout=fopen("wyniki.txt", "w");
	/* Pętla co wczytuje liczby do tablicy int 		*/
	for (i=0; i<(sizeof(tablica_1)/sizeof(tablica_1[0])); i++)
	{
		status = fscanf(fin, "%d ", &tablica_1[i]);
		printf("\tSTATUS=%d\n", status);
		if(status == 1)
			ilosc_elementow += 1;
		else if(errno != 0) {
            perror("scanf:");
            break;
            }
        else if(status == EOF) {
       	printf("EOF \n");
       	 break;}
       	else {
            printf("No match.\n");
        }
	}

/* Zapisz tablicę do nowego pliku 		*/
	for (i=0; i<ilosc_elementow; i++)
	{
		fprintf(fout, "%d ", tablica_1[i]);
	}
/* znajdź wartość najmniejszą i największą i dopisz do pliku */	
	szukacz(ilosc_elementow, tablica_1, &min, &max);
	fprintf(fout, "\n%s%d\n%s%d\n", "Wartość_MAX=", max, "Wartość_MIN=", min);

	fclose(fin); 
	fclose(fout);
	printf("\n");
	return 0;
}

void szukacz(int n, int a[], int *min, int *max) 
{
	*max=a[0];
	*min=a[0];
	for(int i=0; i<n; i++)
	{
		if (a[i] > *max)
			*max=a[i];
		if (a[i] < *min)
			*min=a[i];

	}
	printf("max=%d\nmin=%d\n", *max, *min);
}