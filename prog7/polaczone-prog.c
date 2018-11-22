/* 		Łukasz Strzelec 		//
//	Program łączoący napisane 	//
//	wcześniej programy. :-)		*/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "dwumian-newtona.c"
#include "uklad2rownan.c" 
#include "potrojny_uklad.c"
#include "dwumian-kwadratowy.c"		

int menu()
{
	printf("===================================");
	printf("\n\t1. Dwumian Newtona\n");
	printf("\t2· Równanie kwadratowe\n");
	printf("\t3. Układ 2 równań\n");
	printf("\t4. Układ 3 równań\n");
	printf("\t5. Zakonczenie programu\n");
	printf("===================================\n");
	int n;
	printf("Dokonaj wyboru:\t");
	scanf("%d",&n);
	return n;
}

int rownaniekwadratowe();
int potrojnyuklad();
int uklad2rownan();
int dwumiannewtona();
int main()
{
	int n;
	
	while(1)
	switch(menu())
	{
		case 1:
			printf("Wybrano Dwumian Newtona\n");
			dwumiannewtona();
			break;
		case 2:
			printf("Wybrano rownanie kwadratowe\n");
			rownaniekwadratowe();
			break;
		case 3:
			printf("Wybrano uklad 2 równań\n");
			uklad2rownan();
			break;
		case 4:
			printf("Wybrano układ 3 równań\n");
			potrojnyuklad();
			break;
		case 5:
			exit(0);
		default:
			printf("Nieprawidlowy wybor\n");
			return 0;
	}

	return 0;
}