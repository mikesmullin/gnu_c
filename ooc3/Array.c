#include "Class.h" /* Class */

struct Array {
  const void * class;
};

void f() {};

static const struct Class _Array = {
  size: sizeof(struct Array)
};

const void * Array = &_Array; // exports
