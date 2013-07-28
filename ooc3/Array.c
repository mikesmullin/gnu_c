#include "Class.c" /* Class, new, dealloc */
#include <stdarg.h> /* va_arg */

typedef struct {
  //struct Class * class;
  unsigned long int length;
} ArrayPrototype;

static void * ArrayPrototype_constructor(void * _self, va_list * args) {
  ArrayPrototype * self = _self;
  self->length = va_arg(*args, unsigned long int);
  return self;
}

static const struct Class Array = {
  name: "Array",
  size: sizeof(ArrayPrototype),
  constructor: ArrayPrototype_constructor
};
