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

  /*
  ROADBLOCK:

  (6:58:54 PM) _numbers: how is the data from variables in dynamically typed languages represented at the C or ASM level? any good books or examples revealing the wizard behind the curtain on these details?
  (6:58:55 PM) frog_sha0: comex: I know. :)
  (6:59:18 PM) pippijn: _numbers: tagged union, for example
  (6:59:32 PM) comex: _numbers: depends on the VM.  in efficient VMs, it gets really complicated
  (6:59:58 PM) comex: in something like Python, which is not, you can look at PyObject, pretty straightforward
  (7:00:44 PM) pippijn: https://paste.xinu.at/zZFnE/ <- perl
  (7:01:57 PM) _numbers: ah i c. great examples. thx :)

  ok so i realize now how pure ASM or C binaries can use so little memory.
  whereas the same app in another dynamically typed language is likely
  way over-allocating memory "just in case".

  however it also means if i want a dynamically typed feeling in C
  which is basically what its turning out i'm after
  (all this typing is exhausting)

  i'll have to make structs that represent the dynamically typed data types that
  i want to represent. in a way that you can just look at the struct and know what
  type it is. may as well do the same with arguments; make a struct that
  tracks their length and composes them before passing to a function, or something.
  i'm basically reverse engineering javascript a bit here

  see also:
  http://stackoverflow.com/questions/5384762/tiny-javascript-implementation

  this one is very close to what i'm doing:
  https://code.google.com/p/tiny-js/source/browse/trunk/TinyJS.cpp
  http://www.w3schools.com/js/js_datatypes.asp
  http://stackoverflow.com/questions/307179/what-is-javascripts-max-int-whats-the-highest-integer-value-a-number-can-go-t
  */

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
