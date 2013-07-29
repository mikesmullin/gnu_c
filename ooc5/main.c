#include "Object.c"
#include <stdio.h>

void main() {
  // new function object with empty constructor
  struct Function A = new_Function(lambda(void *, (const struct Function this, int va_length, ...) {
    printf("constructor called.\n");
  }));

  // extend function object with new class method (will be overridden)
  struct Function _f = new_Function(lambda(int, (void) { return 1; }));
  A.set(&A, "a", (void *) &_f);

  struct Object prototype = new_Object();

  // extend function object with new instance method (will override)
  _f = new_Function(lambda(int, (void) { return 2; }));
  prototype.set(&prototype, "a", (void *) &_f);

  // extend function object with new instance method (will not override)
  _f = new_Function(lambda(int, (void) { return 3; }));
  prototype.set(&prototype, "b", (void *) &_f);

  A.set(&A, "prototype", &prototype);

  // extend function object with new class method (won't be overridden)
  _f = new_Function(lambda(int, (void) { return 4; }));
  A.set(&A, "c", (void *) &_f);

  int (*f)(void) = A.get(&A, "a");
  printf("%i\n", f());

  f = A.get(&A, "c");
  printf("%i\n", f());

  struct Object * p = A.get(&A, "prototype");
  printf("A.prototype is %p\n", p);

  f = p->get(p, "b");
  printf("A.prototype.b() is %i\n", f());

  struct Function * a = new(A, 0); // this should invoke our constructor from above
  f = a->get(&a, "a");
  printf("%i\n", f());

  f = a->get(&a, "b");
  printf("%i\n", f());

  //A.call(A, 0);
  //int i = 1;
  //A.set(&A, "a", (void *) &i);
  //printf("i is %i\n", * (int *) A.get(&A, "a"));
}
