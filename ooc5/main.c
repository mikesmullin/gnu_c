#include "Object.c"
#include <stdio.h>

void main() {
  struct Function A = new_Function(({ void * _(const struct Function this, int va_length, ...){
    printf("hello world!\n");
  } _; }));
  A.call(A, 0);
}
