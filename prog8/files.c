/* Łukasz Strzelec */ 

#include <stdio.h>
#include <errno.h>
#include <stdbool.h>

void f(int n, int a[], int *min, int*max);
int main ()
{
	

	/* nappisać funkcję co wpisze min i max */
	int tablica_1[20], status;

	FILE *fin, *fout;
	fin=fopen("dane.dat","r");
	fout=fopen("wyniki.txt", "w");
	while (true) {
	status = fscanf(fin, "%d", tablica_1);
	if(status == 2)
            printf("\n%s \t %c", tablica_1, status);
        else if(errno != 0) {
            perror("scanf:");
            break;
        } else if(status == EOF) {
            break;
        } else {
            printf("No match.\n");
        }
	}
	for (int i=0; i<20; i++)
		printf("%d",tablica_1[i]);
	printf("\n");
	fclose(fin);
	fclose(fout);

	return 0;
}

