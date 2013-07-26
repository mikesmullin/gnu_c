#include <stdio.h>

void main() {
  printf("fun with lambdas!\n");

  // a lambda in ANSI C may not exist
  // but in GNU C we have 1. nested functions, and
  // 2. statement expressions ({})
  // the traditional way of doing this is with a macro
  // called lambda which essentially generated the following
  // syntax after it was used
  int (*max)(int, int) = ({
    int __fn__ (int a, int b) {
      return a > b ? a : b;
    }
    __fn__;
  });

  printf("max(1,3) is %i\n", max(1,3));

  // so we like GNU C now, better than ANSI C
  // of course we always knew Richard Stallman was "The Man"
  // now let's see
  // that's a lot of cruft if we think about it
  // we could also define a lambda just using a nested function
  int min(int a, int b) {
    return a < b ? a : b;
  }

  printf("min(1,3) is %i\n", min(1,3));

  // though we can't just use a statement expression

  // and i'm not sure if/what the difference is between the two
  // examples at the ASM level? hmm...
  // well i guess the first function doesn't have to have a name
  // or a declaration. technically it could be passed to a function
  // as an argument without ever first giving it a name outside of __fn__
  // so that's probably what makes it a lambda vs. a nested function
}
