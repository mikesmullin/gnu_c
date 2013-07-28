/*  in my world,
all functions are objects
and all objects are hash tables
objects don't have to have functions, though
*/
#include <stdarg.h>

struct Object {
  int length; // number of keys
  void * (* set)(); // set value of given key
  void * (* get)(); // get value of given key
};

void * Object_set(){}; // set value of given key
void * Object_get(){}; // get value of given key

struct Function {
  int length; // number of keys
  void * (* set)(); // set value of given key
  void * (* get)(); // get value of given key
  void * (* constructor)(); // optional, if function
  void * (* destructor)(); // optional, dealloc
  void * (* bind)(void * this); // change value of this
  void * (* call)(void * this, int va_length, va_list * args); // calls constructor with variable arguments
  void * (* apply)(); // calls constructor given array of arguments
};

void * Function_constructor(){}; // optional, if function
void * Function_destructor(){}; // optional, dealloc
void * Function_bind(void * this){}; // change value of this
void * Function_call(void * _this, int va_length, ...){
  va_list args;
  // for(
  assert(this->constructor);
  return this->constructor();
};
void * Function_apply(){}; // calls constructor given array of arguments

void * Function(void * f) {
  struct Function this = {
    constructor: f;
    destructor: Function_destructor;
    length: 1;
    set: Object_set;
    get: Object_get;
    call: Function_call;
    apply: Function_apply;
  }
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
