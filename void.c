#include <stdio.h>

void main() {
  // void is interesting
  // a little bit
  // it can be used to define a function that takes no arguments
  void f(void) {} // this cannot take arguments
  void f2() {} // this one takes variable number of arguments

  //f(1); // error: too many arguments to function 'f'
  f2(1);

  // now, when you use void to declare a void pointer
  // the compiler won't let you deference it without
  // casting the type every time
  int x;
  void *p = &x; // warning: dereferencing 'void *'pointer
  //*p = 2; // error: invalid use of void expression
  *(int*)p = 2;

  printf("rage against the machine %i\n", *(int*)p);

  void * undefined;
  void * null = 0x0;
  printf("undefined is %p\n", undefined);
  printf("null is %p\n", null);
  printf("NULL is %p\n", NULL);
  printf("undefined "); printf(undefined == null? "is null" : "isnt null"); printf("\n");
  printf("undefined "); printf(undefined == NULL? "is NULL" : "isnt NULL"); printf("\n");
  printf("undefined "); printf(undefined == 0? "is 0" : "isnt 0"); printf("\n");
  // but the addresses of undefined and null above are unique
  // because they are memory locations that point to zero, but each has
  // their own unique address
  // so if i wanted to come up with my own values like `undefined` i could
  // possibly do it by just reserving some address that is used globally throughout
  // my application. but that is kludgey because other apps wouldn't know what
  // the value was
}
