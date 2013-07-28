#include <stddef.h> /* size_t */
#include <stdarg.h> /* va_list, va_start, va_end */
#include <stdlib.h> /* calloc */
#include <assert.h> /* assert */

typedef struct {
  char * name;
  size_t size;
  void * (* constructor) (const Class, va_list *);
  void * (* destructor) (const Class);
  void * prototype;
} Class;

void * new (const Class class, ...) {
  void * prototype = calloc(1, class.size);
  assert(p);

  class->prototype = prototype;
  * (const Class *) prototype = class;

  if (class->constructor) {
    va_list args;
    va_start(args, _class);
    prototype = class->constructor(prototype, &args);
    va_end(args);
  }
  return prototype;
}

//void dealloc (void * self) {
//  const struct Class ** cp = self;
//  if (self && * cp && (* cp) -> destructor)
//    self = (* cp) -> destructor(self);
//  free(self);
//}
