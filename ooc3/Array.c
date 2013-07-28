#include "Class.h" /* struct Class */
#include "Array.h" /* struct Array */
#include <stdarg.h> /* va_arg */

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
