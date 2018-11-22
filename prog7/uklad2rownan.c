/* Łukasz Strzelec 							*/
/* Program rozwiązuje układy równań typu:	//
// 											//
// a_11*x + a_12*y=b_1						//
// a_21*x + a_22*y=b_2						//
//											//
// 08/11/18 	   							*/	
#include <stdio.h>

double a_table[2][2], b_table[2];

double det(double a_table[][2])
{
	return a_table[0][0]*a_table[1][1]-a_table[1][0]*a_table[0][1];
}
int uklad2(double a_table[][2], double b_table[], double x[])
{
	double wyznacznik_glowny, wyznacznik_x, wyznacznik_y;
	double temp[2][2];
	wyznacznik_glowny = det(a_table);
	printf("main-det=%g\n",wyznacznik_glowny);
	temp[0][0]=b_table[0];
	temp[1][1]=a_table[1][1];
	temp[1][0]=b_table[1];
	temp[0][1]=a_table[1][0];
	wyznacznik_x=det(temp);
	printf("det-x=%g\n",wyznacznik_x); 
	temp[0][0]=a_table[0][0];
	temp[1][1]=b_table[1];
	temp[0][1]=b_table[0];
	temp[1][0]=a_table[1][0];
	wyznacznik_y=det(temp);
	printf("det-y=%g\n",wyznacznik_y); 
	if (wyznacznik_glowny != 0)
	{
		x[0]=wyznacznik_x/wyznacznik_glowny;
		x[1]=wyznacznik_y/wyznacznik_glowny;
		return 1;
	}
	else if (wyznacznik_y == 0 && wyznacznik_x == 0) return 10000;
	else {
		 return -1;
	}
	return 0;

}

int uklad2rownan()
{
	printf("Podaj uklad rownan:\n");
	scanf("%lfx%lfy=%lf",&a_table[0][0], &a_table[0][1], &b_table[0]);
	scanf("%lfx%lfy=%lf", &a_table[1][0],&a_table[1][1],&b_table[1]);
	printf("Podano układ równań: \n\t");
	printf("%+gx%+gy = %+g\n\t%+gx%+gy = %+g\n\n",a_table[0][0], a_table[0][1], b_table[0],a_table[1][0],a_table[1][1],b_table[1]);
	double x[2];

	if(uklad2(a_table,b_table,x) == 1)
	{
		printf("Rozwiazanie:\n\t(%g,%g)\n",x[0],x[1]);
	}
	else if(uklad2(a_table,b_table,x) == 10000)
	{
		printf("Rownanie tozsamosciowe. Ma niezkonczenie wiele rozwiazan\n");
	}
	else
	{
		printf("Ten uklad rownan nie ma rozwiazania\n");
	}
	

	return 0;
}