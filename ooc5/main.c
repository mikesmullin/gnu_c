#include "Object.c"
#include <stdio.h>

void main() {
  // new function object with empty constructor
  struct Function A = new_Function(lambda(void *, (const struct Function this, int va_length, ...) {
  }));

  // extend function object with new class method (will be overridden)
  A.set("a", new_Function(lambda(int, (void) { return 1; }));

  struct Object prototype = new_Object();

  // extend function object with new instance method (will override)
  prototype.set("a", new_Function(lambda(int, (void) { return 2; }));

  // extend function object with new instance method (will not override)
  prototype.set("b", new_Function(lambda(int, (void) { return 3; }));

  A.set("prototype", &prototype);

  // extend function object with new class method (won't be overridden)
  A.set("c", new_Function(lambda(int, (void) { return 4; }));

  printf("%i\n", A.get(&A, "a")());


  //A.call(A, 0);
  //int i = 1;
  //A.set(&A, "a", (void *) &i);
  //printf("i is %i\n", * (int *) A.get(&A, "a"));
}
