#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int table[500], i;
srand(time(NULL));

 int r;
for (i=0; i<500; i++) {
 r=rand()%101;

 table[i]=r;
}
for (i=0; i<500; i++) {
 printf("%i\n",table[i]);
}
return 0;
}

