#include "Class.h" /* Class, new, delete, clone */
#include <stdarg.h> /* va_list, va_start, va_end */
#include <stdlib.h> /* calloc */
#include <assert.h> /* assert */

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

void * clone (const void * self) {
  const struct Class * const * cp = self;

  assert(self && * cp && (* cp) -> clone);
  return (* cp) -> clone(self);
}
