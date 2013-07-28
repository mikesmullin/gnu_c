#include "Class.h" /* new, delete, clone */
#include <stdio.h> /* printf */

extern const void * Array;

void main() {
  void * a = new(Array); // length 0
  void * b = new(Array, 3);  // undefined x length 3

  printf("ok\n");
}
