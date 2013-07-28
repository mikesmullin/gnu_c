#include <stdio.h>
#include "Class.h"

extern const void * Array;

void main() {
  void * a = new(Array);

  printf("ok\n");
}
