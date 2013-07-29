#include "Object.c"
#include <stdio.h>

void main() {
  /*
  what i want, in coffeescript:

  class A
    @a: -> 1
    a: -> 2
    b: -> 3
    @c: -> 4

  console.log '--'
  console.log A.a() # class has a class method (pre-override)
  console.log A.c() # class has a class method (won't be overriden)
  console.log A.prototype # class has prototype object, b method
  console.log A.prototype.b() # can execute class prototype's b without instantiation
  console.log (new A).a() # object has overridden a instance method
  console.log (new A).b() # object has b method
  console.log (new A).class # object has no class attribute
  console.log (new A).prototype # object has no prototype attribute
  console.log (new A).c() # object #<A> has no method 'c'

  c = ->
  Object.a = 1
  Object.prototype.b = 2
  f = -> 1
  console.log '--'
  console.log f() #  1
  console.log f.a # undefined
  console.log f.b # 2
  console.log Object.a # 1
  console.log Object.prototype.b # 2
  console.log f.c # undefined

  so it should be like:
  */

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

  //int (*f)(void) = A.get(&A, "a");
  struct Function * f = A.get(&A, "a");
  int ii = f->call(*f, 0); // fails because call doesn't know the lambda return type
  printf("%i\n", ii);

  //f = A.get(&A, "c");
  //printf("%i\n", f());

  //struct Object * p = A.get(&A, "prototype");
  //printf("A.prototype is %p\n", p);

  //f = p->get(p, "b");
  //printf("A.prototype.b() is %i\n", f());

  //struct Function * a = new(A, 0); // this should invoke our constructor from above
  //f = a->get(&a, "a");
  //printf("%i\n", f());

  //f = a->get(&a, "b");
  //printf("%i\n", f());

  //A.call(A, 0);
  //int i = 1;
  //A.set(&A, "a", (void *) &i);
  //printf("i is %i\n", * (int *) A.get(&A, "a"));
}
