/* Łukasz Strzelec 							*/
/* Program rozwiązuje układy równań typu:	//
// 											//
// a_11*x + a_12*y=b_1						//
// a_21*x + a_22*y=b_2						//
//											//
// 08/11/18 	   							*/	
#include <stdio.h>

double a[2][2], b[2];

int main()
{
	printf("Podaj uklad rownan:\n");
	scanf("%lfx%lfy=%lf",&a[0][0], &a[0][1], &b[0]);
	scanf("%lfx%lfy=%lf", &a[1][0],&a[1][1],&b[1]);
	printf("Podano układ równań: \n\t");
	printf("%gx+%gy=%g\n\t%gx+%gy=%g\n\n",a[0][0], a[0][1], b[0],a[1][0],a[1][1],b[1]);
	return 0;
}