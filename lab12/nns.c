/* Łukasz Strzelec */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (int argc, int** argv) {
if (argc<3) {
  printf("Niepoprawny sposob wywolania programu. Jako argumenty wywolania podaj: 1) liczbe liczb losowych 2) rozmiar macierzy n 3) sposob dzialania programu: 0/1 (0-srand48, 1-rand)");
}
else {
int i;
time_t t;
  srand48(time(&t));
printf("liczba= %d\n", drand48());
}

return 0;
}
