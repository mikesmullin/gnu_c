#include <stdarg.h>
#include <assert.h>

// we'll be using lambdas a lot
#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })

struct Object {
  // all Objects are little more than hash tables
  void * hash_table;
  int length; // number of keys
  void * (* set)(const void * this, char * key, void * value); // set value of given key
  void * (* get)(const void * this, char * key); // get value of given key
};

struct Function {
  // Functions are compatible with Objects
  void * hash_table;
  int length; // number of keys
  void * (* set)(const void * this, char * key, void * value); // set value of given key
  void * (* get)(const void * this, char * key); // get value of given key

  void * (* constructor)(); // optional, if function
  void * (* destructor)(); // optional, dealloc
  void * (* bind)(const void * this); // change value of this
  void * (* call)(const struct Function this, int va_length, ...); // calls constructor with variable arguments
  void * (* apply)(); // calls constructor given array of arguments
};

void * Object_set(const void * _this, char * key, void * value) {
  struct Object * this = _this;
  void * pair[2] = [key, value];
  this->hash_table = &pair;
}
void * Object_get(const void * _this, char * key) {
  struct Object * this = _this;
  void * pair[2] = this->hash_table;
  char * k = pair[0];
  if (strcp(k, key) == 0) {
    return pair[1];
  }
}
void * Function_constructor(){};
void * Function_destructor(){};
void * Function_bind(const void * this){};
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
