/* Łukasz Strzelec 					//
/* Program rozwiązujący układ równań//
/*									//
/* 	a_11*x + a_12*y + a_13*z=b1		//
/* 	a_21*x + a_22*y + a_23*z=b2		//
/* 	a_31*x + a_32*y + a_33*z=b3		//
/*									//
/*		|a_11	a_12	a_13|		//
/*		|a_11	a_22	a_23| = W   //
/*		|a_31	a_32	a_33|		//
/*									//
/*		|b1		a_12	a_13|		//
/*		|b2		a_22	a_23| = Wx	//
/*		|b3		a_32	a_33|		//
/*									//
/*		|a_11	b1		a_13|		//
/*		|a_21	b2		a_23| = Wy	//
/*		|a_31	b3		a_33|		//
/*									//
/*		|a_11	a_12	b1	|		//
/*		|a_21	a_22	b2	| = Wz	//
/*		|a_31	a_32	b3	|		//
/*									//
/*		napisanie funkcji:			//
/*		double det3(double a[][3])	//
/*									//
/*									//	
/*									*/

# include <stdio.h>

double a[3][3], b[3];
double w_main;

double det3 (double a[][3])
{
	double w;
	w  = a[0][0]*a[1][1]*a[2][2];
	w += a[0][1]*a[1][2]*a[2][0];
	w += a[0][2]*a[1][0]*a[2][1];
	w -= a[0][2]*a[1][1]*a[2][0];
	w -= a[0][0]*a[1][2]*a[2][1];
	w -= a[0][1]*a[1][0]*a[2][2];
	printf("\nWyznacznik W= %g\n", w);
	return w;
}

int uklad3(double a[][3], double b[], double x[])
{
	double t[3][3];
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			t[i][j]=a[i][j];
		}
	}
	for (int i=0; i<3; i++)
	{
		t[0][i]=b[i];
	}
	x[0]=det3(t)/w_main;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			t[i][j]=a[i][j];
		}
	}
	for (int i=0; i<3; i++)
	{
		t[1][i]=b[i];
	}
	x[1]=det3(t)/w_main;

	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			t[i][j]=a[i][j];
		}
	}
	for (int i=0; i<3; i++)
	{
		t[2][i]=b[i];
	}
	x[2] = det3(t)/w_main;

} 

int main()
{
	printf("Podaj uklad rownan 3x3:\n");
	scanf("%lfx%lfy%lfz=%lf", &a[0][0], &a[0][1], &a[0][2], &b[0]);
	scanf("%lfx%lfy%lfz=%lf", &a[1][0], &a[1][1], &a[1][2], &b[1]);
	scanf("%lfx%lfy%lfz=%lf", &a[2][0], &a[2][1], &a[2][2], &b[2]);
	printf("Podano układ równań: \n\t");
	printf("%+gx%+gy%+gz = %+g\n\t%+gx%+gy%+gz = %+g\n\t%+gx%+gy%+gz = %+g\n",a[0][0], a[0][1], a[0][2], b[0],a[1][0],a[1][1], a[1][2],b[1], a[2][0],a[2][1],a[2][2],b[2]);
	w_main = det3(a);
	if (w_main == 0)
	{
		printf("\n Ten układ równań jest zbyt skomplikowany\n");
		return -3;
	}
	else
	{
	double x[3];
	uklad3(a, b, x);
	printf("\n ");
	for(int i=0; i<3; i++)
	{
		printf("\tx_%d = %g \n",i,x[i]);
	}
	printf("\n ");
	}
	

	return 0;
}