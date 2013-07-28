#include "Class.c" /* Class, new, dealloc */
#include <stdarg.h> /* va_arg */

struct Array {
  unsigned long int length;
};

static void * ArrayPrototype_constructor(void * _self, va_list * args) {
  struct Array * self = _self;
  self->length = va_arg(*args, unsigned long int);
  return self;
}

static const struct Class Array = {
  name: "Array",
  size: sizeof(struct Array),
  constructor: ArrayPrototype_constructor
};
