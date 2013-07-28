#include <stddef.h> /* size_t */
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <stdlib.h> /* calloc */
#include <assert.h> /* assert */

struct Class {
  char * name;
  size_t size;
  // constructor could be one of:
  // a method by the same name as the object, or
  // constructor or initialize or init or ctpr
  void * (* constructor) (void * self, va_list * args);
  // destructor or dealloc or dtor
  void * (* dealloc) (void * self);
};

void * new (const void * _class, ...) {
  const struct Class * class = _class;
  void * p = calloc(1, class -> size);

  assert(p);
  * (const struct Class **) p = class;

  if (class->constructor) {
    va_list ap;

    va_start(ap, _class);
    p = class->constructor(p, & ap);
    va_end(ap);
  }
  return p;
}

void delete (void * self) {
  const struct Class ** cp = self;
  free(self);
}

struct Array {
  unsigned long int length;
};

static void * Array_constructor(void * _self, va_list * args) {
  struct Array * self = _self;
  self->length = va_arg(*args, unsigned long int);
  return self;
}

static const struct Class _Array = {
  name: "Array",
  size: sizeof(struct Array),
  constructor: Array_constructor
};

const void * Array = &_Array; // exports
