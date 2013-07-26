#include <stdio.h>
void main() {
  float x;
  float* px;
  x = 6.5;
  px = &x;

  printf("\n%f\n", x);
  printf("%p\n", px);
  printf("%f\n", *px);
}
