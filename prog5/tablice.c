/* Łukasz Strzelec 							*/
/* Program rozwiązuje układy równań typu:	//
// 											//
// a_11*x + a_12*y=b_1						//
// a_21*x + a_22*y=b_2						//
//											//
// 08/11/18 	   							*/	
#include <stdio.h>

double a[2][2], b[2];

double det(double a[][2])
{
	return a[0][0]*a[1][1]-a[1][0]*a[0][1];
}
int uklad2(double a[][2], double b[], double x[])
{
	double wyznacznik_glowny, wyznacznik_x, wyznacznik_y;
	double temp[2][2];
	wyznacznik_glowny = det(a);
	printf("main-det=%g\n",wyznacznik_glowny); 
	temp[0][0]=b[0];
	temp[1][1]=a[1][1];
	temp[0][1]=a[0][1];
	temp[1][0]=b[1];
	wyznacznik_x=det(temp);
	printf("det-x=%g\n",wyznacznik_x); 
	temp[0][0]=a[0][0];
	temp[1][1]=b[1];
	temp[0][1]=b[0];
	temp[1][0]=a[1][0];
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

int main()
{
	printf("Podaj uklad rownan:\n");
	scanf("%lfx%lfy=%lf",&a[0][0], &a[0][1], &b[0]);
	scanf("%lfx%lfy=%lf", &a[1][0],&a[1][1],&b[1]);
	printf("Podano układ równań: \n\t");
	printf("%+gx%+gy = %+g\n\t%+gx%+gy = %+g\n\n",a[0][0], a[0][1], b[0],a[1][0],a[1][1],b[1]);
	double x[2];

	if(uklad2(a,b,x) == 1)
	{
		printf("Rozwiazanie:\n\t(%g,%g)\n",x[0],x[1]);
	}
	else if(uklad2(a,b,x) == 10000)
	{
		printf("Rownanie tozsamosciowe. Ma niezkonczenie wiele rozwiazan\n");
	}
	else
	{
		printf("Ten uklad rownan nie ma rozwiazania\n");
	}
	

	return 0;
}