#include "Class.h" /* new, delete, clone */
#include <stdio.h> /* printf */

extern const void * Array;

void main() {
  void * a = new(Array);

  printf("ok\n");
}
