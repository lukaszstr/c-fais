/* Łukasz Strzelec */

#include <stdio.h>

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

int main(int argc, char *argv[])
{
	FILE *fin=fopen(argv[1], "r");
	FILE *fout=fopen(argv[2], "w");
	int a[100], n=0, min, max;
	while(fscanf(fin, "%d", &a[n])==1)n++;
	int i;
	for(i=0; i<n; i++)
		fprintf(fout, "%d ",a[i]); 
	szukacz(n, a, &min, &max);
	fprintf(fout, "\n%s%d\n%s%d\n", "Wartość_MAX=", max, "Wartość_MIN=", min);
	fclose(fin);
	fclose(fout);
	return 0;
}  