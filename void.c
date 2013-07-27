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
}
