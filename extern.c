#include <stdio.h>

int d = 2;
void main() {
  // extern just tells the compiler not to err
  // if i isnt defined in the same function or file
  // but instead to look elsewhere first
  extern int i;
  printf("i is %i\n", i);
  printf("d is %i\n", d);
  //printf("e is %i\n", e); // won't work
}
