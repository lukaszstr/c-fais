# include <stdio.h>
# include <stdlib.h>
# include <math.h>

int main() 
{
double a,b,c,delta,x1,x2;
a=2; b=-2; c=2;
delta=b*b-4.0*a*c;
printf("Delta= %.2fi \n Sqrt(delta)=%fi \n", delta, sqrt(delta)));
return 0;
}

