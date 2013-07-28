#include "Class.h" /* Class */
#include <stdarg.h> /* va_arg */

struct Array {
  const void * class;
  unsigned long int length;
};

static void * Array_constructor (struct Array * self, va_list * args) {
  self->length = va_arg(*args, unsigned long int);
  return self;
}

static const struct Class _Array = {
  name: "Array"
  size: sizeof(struct Array)
  constructor: Array_constructor
};

const void * Array = &_Array; // exports
