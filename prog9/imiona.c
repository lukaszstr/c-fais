/* Łukasz Strzelec */

#include <stdio.h>

int main(int argc, char *argv[])
{
	FILE *fin = fopen(argv[1], "r");
	FILE *fout=fopen(argv[2], "w");
	char imiona[50][30];
	int liczba_imion, i;

	while(fscanf(fin, "%s", imiona[liczba_imion])==1)liczba_imion++;
	printf("imion=%d\n", liczba_imion);

	
	for(i=0; i<liczba_imion; i++)
	{
		fprintf(fout, "%s\n", imiona[i]);
	} 
	fclose(fin);
	fclose(fout);
	return 0;
}