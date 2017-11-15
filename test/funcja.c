/* Łukasz Strzelec */
# include <stdio.h>
# include <math.h>

double func (double x)
{
    /*   x-2e:^(2x^2+5) */
    return 5*x;
}

int main () {
double xl = 5.f;
printf("f(x)=%lf", 5*xl);
printf("f(x)=%lf", func(xl));
return 0;
}
