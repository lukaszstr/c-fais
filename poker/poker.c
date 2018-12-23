/* How many games do you need to get poker ? */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

#define liczba_kolorow 4
#define liczba_figur 13

double numer_partii = 0.0;
char kolory[liczba_kolorow] = {'s', 'd', 'w', 't'}; 
char figury[liczba_figur] = {'2', '3', '4', '5', '6', '7', '8', '9' ,'0' ,'J', 'Q', 'K', 'A' };
char reka[5];
int karty_w_rece[liczba_figur][liczba_kolorow] = {0};
int i=0, j=0;
int figura=0, kolor=0;
void sortuj(char a[], int n)
{
	char temp;
	int i=0, j=0;
	for (j=0;j<n;j++){
		for(i=n-1;i>0;i--)
		{
			if (a[i]<a[i-1])
				{
					temp = a[i-1];
					a[i-1] = a[i];
					a[i] = temp;
				}
		}		
	}
}
int rozdaj(void)
{
	int liczba_kart_w_rece=0;
	while (liczba_kart_w_rece < 5)
		{
		figura = rand()%liczba_figur;
		kolor = rand()%liczba_kolorow;
		if(karty_w_rece[figura][kolor]);
		karty_w_rece[figura][kolor]=1;
		liczba_kart_w_rece++;
		}
	return 1;
}
int sprawdz(void)
{
	int k=0;
	for(i=12;i>=0;i--)
		{
			for (j=0;j<4;j++)
			{
				if(karty_w_rece[i][j])
				{
					reka[k]=figury[i];
					reka[k+1]=kolory[j];
					k = k+2;
					karty_w_rece[i][j]=0;
				}
			}
		}
		return 1;
}

int main(void)
{
	printf("Reka: ,\tPartia:\n");
	srand( (unsigned) time(NULL) ) ;
	while (1)
	{
		rozdaj();
		sprawdz();
		sortuj(reka,10);
		printf("%s,\t", reka);
		printf("%g\n", numer_partii);
		numer_partii++;		
		/*sleep(1);*/
		if (((strcmp(reka, "0AJKQsssss") == 0) || (strcmp(reka, "0AJKQddddd") == 0) || (strcmp(reka, "0AJKQwwwww") == 0) || (strcmp(reka, "0AJKQppppp") == 0 )))
		{
			printf("Koniec partii. \n rozegranych =%g\n", numer_partii);
			return 1;
		}

			for(i=0;i<10;i++)
		{
			reka[i]='0';
		}
	}
	return 0;
}
