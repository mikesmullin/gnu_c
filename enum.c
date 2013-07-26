#include <stdio.h>

//enum Numbers {One = 1, Two = 2, Three = 3, Four = 4, Five = 5};
enum Numbers {x, y, z};

/*
Using enums increase the level of abstraction and lets the
programmer think about what the values mean rather than
worry about how they are stored and accessed.
*/

// these are preprocessor macros
// no memory allocated for these
#define red 1
#define orange 2

// memory will actually be allocated for this variable
// and const makes it immutable so it can't change
// (enforced at compile-time only, of course)
// you can trick the compiler so its mostly a weak check
const int blue = 3;

int main() {
  enum Numbers bob = x;
  printf("\nhello %i %i %i %i\n", bob, red, orange, blue);
  return 0;
}
