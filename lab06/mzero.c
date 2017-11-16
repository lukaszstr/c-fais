/* Łukasz Strzelec */
# include <stdio.h>
# include <math.h>

double func (double x); /* prototyp */
double mzero (double xl, double xp, double eps, int metoda, int *kroki)
{ /* w ten sposob nie da sie wyciagnac liczby krokow */
double xm, fm, fl, fp;
/* do tej pory są ponoć 2 błędy */
fl = func(xl);
fp = func(xp);
(*kroki)=0;
if (fl * fp == 0)
	{
	 if (fl == 0)
		{
		 return xl;
		}
	else
		{
		 return xp;
		}
	}
if (fl * fp > 0)
	{
	 (*kroki) = -1;
	 printf("\nIloczyn wartości funkjci dla argumentów xl, xp jest dodatni \nW tym przedziale funkcja nie ma miejsc zerowych, albo ma ich parzystą ilość\n Wybierz inny zakres\n");
     return xp;
	}
else	{
	do {
		if (metoda == 0)
			{
			xm = 0.5 * (xl + xp);
		    (*kroki)=(*kroki) + 1;
            }
    		else
			{
			xm = (fp * xl - fl * xp)/(fp - fl);
			(*kroki)=(*kroki)+1;
			}
    	fm = func(xm);
    	if (fm == 0) { return xm; }
    	if (fm * fp < 0) { xl = xm; fl = fm; }
    	else { xp = xm; fp = fm; }
	}while (fabs(fm) > eps && fabs ((xp-xl) / xm) > eps);
}
return xm;
}
