#include <stddef.h> /* size_t */
#include <stdarg.h> /* va_list, va_start, va_arg, va_end */
#include <stdlib.h> /* calloc */
#include <assert.h> /* assert */

struct ArrayClass {
  char * name;
  size_t size;
  void * (* constructor) (void * self, va_list * args);
  void * (* dealloc) (void * self);
};

void * ArrayClass_new (const void * _class, ...) {
  const struct ArrayClass * class = _class;
  void * p = calloc(1, class -> size);

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

struct ArrayInstance {
  unsigned long int length;
};

static void * ArrayInstance_constructor(void * _self, va_list * args) {
  struct ArrayInstance * self = _self;
  self->length = va_arg(*args, unsigned long int);
  return self;
}

static const struct ArrayClass _Array = {
  name: "Array",
  size: sizeof(struct ArrayInstance),
  constructor: ArrayInstance_constructor
};

const void * Array = &_Array; // exports
