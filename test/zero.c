/* Łukasz Strzelec */
# include <stdio.h>
# include <math.h>

double func (double x) /* prototyp */
{return  (-1 + 3*x + 5*x*x);}

double xl=-1, xp=-0.3, eps=0.0005, xm, fm, fl, fp;
int metoda,kroki;
int main (){
fl = func(xl);
fp = func(xp);
printf("Dane wejsciowe \n fl=%lf\tfp=%lf\n\n", fl, fp);
kroki = 0;
if (fl * fp == 0)
	{
	 if (fl == 0)
		{
			printf("Miejsce zerowe fl = 0\n");
		 return xl;
		}
	else
		{
			printf("Miejsce zerowe fp=%lf\n", xp);
		 return xp;
		}
	}
if (fl * fp > 0)
	{
	 kroki = -1;
	 printf("Iloczyn tych liczb jest dodatni.\n Wartości f mają ten sam znak \n Wybierz inne wartości przedziału (xl i xp)\n");
	 return xp;
	}
else	{
	do
	{
		if (metoda == 0)
			{
			xm = 0.5 * (xl + xp);
			printf("Metoda siecznych '0'\n xm=%lf\n", xm);
					}
    		else
			{
			xm = (fp * xl - fl * xp)/(fp - fl);
			kroki++;
			printf("Metoda stycznych \nxm=%lf\n\n", xm);
			}
    	fm = func(xm);
			printf("fm*fp=%lf\n\n", fm*fp);
    	if (fm == 0) { printf("fm=0, xm=%lf", xm); return xm; }
    	if (fm * fp < 0) { printf("iloczyn mniejszy od 0 \n Przechodzę dalej\n fm*fp=%lf\n\n", fm*fp); xl = xm; fl = fm; }
    	else { printf("Iloczyn dodatni \n Przechodzę dalej\n fm*fp=%lf\n\n", fm*fp); xp = xm; fp = fm; }
			printf("fabs(fm)-eps=%lf\t fabs(xp-xl)/xm)-eps=%lf\n",  fabs(fm)-eps, fabs((xp-xl)/xm)-eps);

		}
		while (fabs(fm) > eps) /* && fabs ((xp-xl) / xm) > eps)*/ ;
return xm;
}
 printf("\n\n\nxm=%lf\n", xm);
	return 0;
}
