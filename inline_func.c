#include <stdio.h>

void (*f)();
void (*f2)();

void hamster(void) {
  f();
  int x = 22;
  f2 = ({ void _(void) {
    printf("x is %i\n", x);
  } _; });
}

void main() {
  int this = 654;
  f = ({ void _(void) {
    printf("this is %i\n", this);
  } _; });
  hamster(); // this hasn't fallen out of scope
  f2(); // but x has fallen out of scope
  // we can probably get lucky and still reference
  // our variable, but its unwise
  // so this is an important difference from javascript
  // see also:
  // http://gcc.gnu.org/onlinedocs/gcc/Nested-Functions.html
}
