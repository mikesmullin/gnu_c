#include "Array.c" /* Array */
#include <stdio.h> /* printf */

void main() {
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

  // TODO: extend a class after it has been initialized
  // just realized i'm going to have to
  // rely on a convention here to get the same syntax i'm used to
  // cuz you can't just add an attribute or method to a struct
  // you would need an object with a variable length hash table to handle that
  // and it looks like basically that's the heart of it
  // the magic of hash tables at runtime
  // it must be why js has an Object object
  // which is really just a hash table that can store any kind of data type
  // strong typing advocates will want a hash table that still validates its types

  /*
  compiling this way will make the C language less readable for
  hardcore ANSI C people, possibly
  i mean for every time i use dot notation it would be translating like:
  a.c = 2
  becomes:
  a.set('c', 2);
  which then means we also have to implement something like .call() and .apply()
  because we wouldn't want the user unable to define a 'set' method of their own
  so theirs would get called by translating to
  a.set 2
  becomes
  a.call('set', 2);

  but i'm already having to do something similar with function arguments
  its basically like a set of opinionated macros based on well-established design patterns
  but it doesn't have to be interpreted by a tokenizer at runtime
  it could compile down to 'bytecode'
  with almost no middle layers inbetween

  i think i'll try implementing this with an inefficient hash object to start
  then switch to judy array as/if i see fit
  */
}
