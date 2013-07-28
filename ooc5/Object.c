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
  void * (* get)(void * this, char * key); // get value of given key
};

struct Function {
  // Functions are compatible with Objects
  struct Hash hash;
  int length; // number of keys
  void * (* set)(void * this, char * key, void * value); // set value of given key
  void * (* get)(void * this, char * key); // get value of given key

  void * (* constructor)(); // optional, if function
  void * (* destructor)(); // optional, dealloc
  void * (* bind)(const void * this); // change value of this
  void * (* call)(const struct Function this, int va_length, ...); // calls constructor with variable arguments
  void * (* apply)(); // calls constructor given array of arguments
};

void * Object_set(void * _this, char * key, void * value) {
  struct Object * this = _this;
  struct Hash * item = (struct Hash *) malloc(sizeof(struct Hash));
  strcpy(item->key, key);
  strcpy(item->value, value);
  HASH_ADD_STR(this->hash, key, item);
}
void * Object_get(void * _this, char * key) {
  struct Object * this = _this;
  struct Hash * item;
  HASH_FIND_STR(this->hash, key, item);
  return item->value;
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
