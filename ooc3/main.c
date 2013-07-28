#include "Array.c" /* Array */
#include <stdio.h> /* printf */

void main() {
  //void * a = new(Array, 0); // length 0
  //void * b = new(Array, 3);  // undefined x length 3
  struct ArrayInstance * a = ArrayClass_new(Array, 0);
  struct ArrayInstance * b = ArrayClass_new(Array, 3);

  printf("a->length is %lu\n", a->length);
  printf("b->length is %lu\n", b->length);
}
