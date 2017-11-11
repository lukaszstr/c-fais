/* Łukasz Strzelec */
# include <stdio.h>
# include 
double f (double x); /* prototyp */
double mzero (double xl, double xp, double eps, int metoda, int kroki)
{
double xm, fm, fl, fp;
/* do tej pory są ponoć 2 błędy */
fl=f(xl); fp=f(xp);
kroki = 0;
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
if (fl*fp > 0)
	{
	 kroki = -1;
	 return xp;
	}
else	{
/*	while (fabs(fm) > eps && fabs (xp-xl)/fabs(xm) */
do 
while (fabs(fm)>esp && fabs (xp-xl/xm)>eps)
	
	if (metoda == 0)
	{
	xm = 0.5 * (xl+xp); /* mnożenie 0.5 to shift binarny */
	else 
	{
	xm=(fp*xl-fl*xp)/(fp-fl);
	}
	fm=f(xm);
	kroki++;
	if(fm == 0) {return xm;}
	}
	if (fm*fp < 0) {xl=xm; fl=fm}
	else {xp=xm; fp=fm;}
	}
	
 return xm;
}
/* liczba kroków nigdy nie opuści tego czegoś
 * bo kroki są lokalne 
 * nie chcemy jednak zmiennych globalnych
 * ma to być adres do zmiennej
 * można użyć wskaźnika? int *kroki - nie skompiluje 
*/
