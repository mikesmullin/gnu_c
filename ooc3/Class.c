#include <stddef.h> /* size_t */
#include <stdarg.h> /* va_list, va_start, va_end */
#include <stdlib.h> /* calloc */
#include <assert.h> /* assert */

struct Class {
  char * name;
  size_t size;
  void * (* constructor) (void * self, va_list * args);
  void * (* destructor) (void * self);
};

void * new (const struct Class _class, ...) {
  const struct Class * class = &_class;
  void * p = calloc(1, class->size);

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

void dealloc (void * self) {
  const struct Class ** cp = self;
  free(self);
}
