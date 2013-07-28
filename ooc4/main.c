#include "Hash.c" /* Hash */
#include <stdio.h> /* printf */

void main() {
  Hash A = new Hash();

  /*
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

  Class * A = Array // class A
  printf("%i\n", A->a()); // class method pre-override
  printf("%p\n", A->prototype); // class prototype
  printf("%i\n", A->prototype->b()); // instance method (pre-instantiation)
  ArrayPrototype * a = new(Array, 3); // instantiated class
  printf("%i\n", a->a()); // instance method (overrode class method)
  printf("%i\n", a->b()); // instance method
  printf("a->length is %i\n", a->length); // instance attribute
  printf("a->name is %i\n", a->name); // class attribute from instance
  if (!a->prototype)
    printf("instance has no prototype (good)\n");
  a.set('d', 7); // extend object with attribute
  a.set('f', ({ int lambda(const int i){ return i+1; }; lambda; })); // extend object with method
  printf("f(22) is %i\n", a.call('f', 22)); // invoke object method
}
