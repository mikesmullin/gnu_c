#include "Object.c"
#include <stdio.h>

void main() {
  struct Function A = new_Function(lambda(void *, (const struct Function this, int va_length, ...) {
    printf("hello world!\n");
  }));
  A.call(A, 0);
  int i = 1;
  A.set(&A, "a", (void *) &i);
  printf("i is %i\n", * (int *) A.get(&A, "a"));
}
