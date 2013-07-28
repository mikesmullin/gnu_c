#include "Array.c" /* Array */
#include <stdio.h> /* printf */

void main() {
  ArrayPrototype * a = new(Array, 0); // length 0
  ArrayPrototype * b = new(Array, 3);  // undefined x length 3

  printf("instance variables:\n");
  printf("a->length is %lu\n", a->length);
  printf("b->length is %lu\n", b->length);
  printf("class variables:\n");
  printf("Array->name is %s\n", ((struct Class) Array).name);
}
