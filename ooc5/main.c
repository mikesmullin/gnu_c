#include "Object.c"
#include <stdio.h>

void main() {
  struct Function A = Function(({ void * _(void * this, int va_length, ...){
    printf("hello world!\n");
  }; _; });
  A.call(A, 0);
}
