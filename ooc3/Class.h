#include <stddef.h> /* size_t */
#include <stdarg.h> /* va_list */

struct Class {
  char * name;
  size_t size;
  // constructor could be one of:
  // a method by the same name as the object, or
  // constructor or initialize or init or ctpr
  void * (* constructor) (void * self, va_list * app);
  // destructor or dealloc or dtor
  //void * (* dealloc) (void * self);
  void * (* clone) (const void * self);
};

void * new (const void * class, ...);
void delete (void * item);
void * clone (const void * self);
