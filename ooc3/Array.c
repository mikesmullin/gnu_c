#include <stddef.h> /* size_t */
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <stdlib.h> /* calloc */
#include <assert.h> /* assert */

// TODO: split into Class.c
// or will that prohibit class vs. instance variables per object?
// how do you do that according to ooc?
// we'll just have to do it ourselves
// we know the requirements
// basically a class variable is only instantiated once per class
// while instance variables are instantiated unique to every new object in its constructor
// you should be able to reference the class variable of any object.
struct ArrayClass {
  char * name;
  size_t size;
  void * (* constructor) (void * self, va_list * args);
  void * (* destructor) (void * self);
};

void * ArrayClass_new (const void * _class, ...) {
  const struct ArrayClass * class = _class;
  void * p = calloc(1, class->size);

  assert(p);
  * (const struct ArrayClass **) p = class;

  if (class->constructor) {
    va_list ap;

    va_start(ap, _class);
    p = class->constructor(p, & ap);
    va_end(ap);
  }
  return p;
}

void ArrayClass_delete (void * self) {
  const struct ArrayClass ** cp = self;
  free(self);
}

struct ArrayPrototype {
  unsigned long int length;
};

static void * ArrayPrototype_constructor(void * _self, va_list * args) {
  struct ArrayPrototype * self = _self;
  self->length = va_arg(*args, unsigned long int);
  return self;
}

static const struct ArrayClass ArrayClass = {
  name: "Array",
  size: sizeof(struct ArrayPrototype),
  constructor: ArrayPrototype_constructor
};

const void * Array = &ArrayClass; // exports
