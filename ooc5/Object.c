#include <stdarg.h>
#include <assert.h>
#include <string.h>
#include "vendor/lambda.h"
#include "vendor/uthash.h"

struct Hash {
  char key[255];
  char value[255];
  UT_hash_handle hh;
};

struct Object {
  // all Objects are little more than hash tables
  struct Hash * hash;
  int length; // number of keys
  void * (* set)(void * this, char * key, void * value); // set value of given key
  void * (* get)(const void * this, char * key); // get value of given key
};

void * Object_set(void * _this, char * key, void * value) {
  struct Object * this = _this;
  struct Hash * item = (struct Hash *) malloc(sizeof(struct Hash));
  strcpy(item->key, key);
  strcpy(item->value, value);
  HASH_ADD_STR(this->hash, key, item);
}
void * Object_get(const void * _this, char * key) {
  const struct Object * this = _this;
  struct Hash * item;
  HASH_FIND_STR(this->hash, key, item);
  return item->value;
}

struct Object new_Object(void) {
  struct Object o = {
    length: 0,
    set: Object_set,
    get: Object_get
  };
  return o;
}

struct Function {
  // Functions are compatible with Objects
  struct Hash hash;
  int length; // number of keys
  void * (* set)(void * this, char * key, void * value); // set value of given key
  void * (* get)(const void * this, char * key); // get value of given key

  void * (* constructor)(); // optional, if function
  void * (* destructor)(); // optional, dealloc
  void * (* bind)(const void * this); // change value of this
  void * (* call)(const struct Function this, int va_length, ...); // calls constructor with variable arguments
  void * (* apply)(); // calls constructor given array of arguments
};

void * Function_constructor(){};
void * Function_destructor(){};
void * Function_bind(const void * this){};
void * Function_call(const struct Function this, int va_length, ...) {
  va_list args;
  assert(this.constructor);
  return this.constructor(this, va_length, &args);
};
void * Function_apply(){};

struct Function new_Function(void * f) {
  struct Function this = {
    length: 1,
    constructor: f,
    destructor: Function_destructor,
    set: Object_set,
    get: Object_get,
    call: Function_call,
    apply: Function_apply
  };
  return this;
}

struct Function * new(const struct Function this, int va_length, ...) {
  va_list args;
  assert(this.constructor);
  this.constructor(this, va_length, &args);
  // should malloc fresh copies of each prototype object key
  // and return a pointer to them below
  return this.get(&this, "prototype");
}

void * delete() {
  // calls object destructor
}
