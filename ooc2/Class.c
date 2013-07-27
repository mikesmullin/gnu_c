#include <stdio.h>
#include <assert.h>
#include <stdarg.h> /* va stuff */
#include <stdlib.h> /* calloc, free */
#include <string.h> /* strlen, strcpy */
#include <stddef.h> /* size_t */

extern const void * String;

struct Class {
  size_t size;
  void * (* ctor) (void * self, va_list * app);
  void * (* dtor) (void * self);
  void * (* clone) (const void * self);
  int (* differ) (const void * self, const void * b);
};

void * new (const void * _class, ...) {
  const struct Class * class = _class;
  void * p = calloc(1, class -> size);

  assert(p);
  * (const struct Class **) p = class;

  if (class -> ctor)
  {  va_list ap;

    va_start(ap, _class);
    p = class -> ctor(p, & ap);
    va_end(ap);
  }
  return p;
}

void delete (void * self) {
  const struct Class ** cp = self;

  if (self && * cp && (* cp) -> dtor)
    self = (* cp) -> dtor(self);
  free(self);
}

void * clone (const void * self) {
  const struct Class * const * cp = self;

  assert(self && * cp && (* cp) -> clone);
  return (* cp) -> clone(self);
}

int differ (const void * self, const void * b) {
  const struct Class * const * cp = self;

  assert(self && * cp && (* cp) -> differ);
  return (* cp) -> differ(self, b);
}

size_t sizeOf (const void * self) {
  const struct Class * const * cp = self;

  assert(self && * cp);
  return (* cp) -> size;
}

struct String {
  const void * class;  /* must be first */
  char * text;
};

static void * String_ctor (void * _self, va_list * app) {
  struct String * self = _self;
  const char * text = va_arg(* app, const char *);

  self -> text = malloc(strlen(text) + 1);
  assert(self -> text);
  strcpy(self -> text, text);
  return self;
}

static void * String_dtor (void * _self) {
  struct String * self = _self;

  free(self -> text), self -> text = 0;
  return self;
}

static void * String_clone (const void * _self) {
  const struct String * self = _self;

  return new(String, self -> text);
}

static int String_differ (const void * _self, const void * _b) {
  const struct String * self = _self;
  const struct String * b = _b;

  if (self == b)
    return 0;
  if (! b || b -> class != String)
    return 1;
  return strcmp(self -> text, b -> text);
}

static const struct Class _String = {
  sizeof(struct String),
  String_ctor, String_dtor,
  String_clone, String_differ
};

const void * String = & _String;

int main () {
  void * a = new(String, "a"), * aa = clone(a);
  void * b = new(String, "b");

  printf("sizeOf(a) == %lu\n", (unsigned long)sizeOf(a));
  if (differ(a, b))
    puts("ok");

  if (differ(a, aa))
    puts("differ?");

  if (a == aa)
    puts("clone?");

  delete(a), delete(aa), delete(b);
  return 0;
}
