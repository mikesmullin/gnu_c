#include <stdarg.h>
#include <assert.h>

// we'll be using lambdas a lot
#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })

// all Objects are just hash tables
struct Object {
  int length; // number of keys
  void * (* set)(); // set value of given key
  void * (* get)(); // get value of given key
};

// Functions are compatible with Objects
struct Function {
  int length; // number of keys
  void * (* set)(); // set value of given key
  void * (* get)(); // get value of given key
  void * (* constructor)(); // optional, if function
  void * (* destructor)(); // optional, dealloc
  void * (* bind)(void * this); // change value of this
  void * (* call)(const struct Function this, int va_length, ...); // calls constructor with variable arguments
  void * (* apply)(); // calls constructor given array of arguments
};

void * Object_set(){};
void * Object_get(){};
void * Function_constructor(){};
void * Function_destructor(){};
void * Function_bind(void * this){};
void * Function_call(const struct Function this, int va_length, ...) {
  va_list args;
  // for(
  assert(this.constructor);
  return this.constructor(this, va_length, &args);
};
void * Function_apply(){};

struct Function new_Function(void * f) {
  struct Function this = {
    constructor: f,
    destructor: Function_destructor,
    length: 1,
    set: Object_set,
    get: Object_get,
    call: Function_call,
    apply: Function_apply
  };
  return this;
}

void * new() {
  //return struct Object Object = {
  //  Object_constructor,
  //  Object_destructor,
  //  Object_length,
  //  Object_set,
  //  Object_get,
  //  Object_call,
  //  Object_apply
  //}
}

void * delete() {
  // calls object destructor
}
