#include "Array.c" /* Array */
#include <stdio.h> /* printf */

extern const void * Array;

void main() {
  //void * a = new(Array, 0); // length 0
  //void * b = new(Array, 3);  // undefined x length 3
  struct Array * a = new(Array, 0); // length 0
  struct Array * b = new(Array, 3);  // undefined x length 3
  struct Array * c = new(Array, 1, 2, 3);  // [1, 2, 3]

  printf("a->length is %lu\n", a->length);
  printf("b->length is %lu\n", b->length);
}
