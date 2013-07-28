#include "Class.h"

struct Array {
  const void * class;
};

void f() {};

static const struct Class _Array = {
  sizeof(struct Array)
};

const void * Array = &_Array;
