#include <stdio.h>

void unimplemented_function();

void named_function() {
  printf("named_function() called.\n");

  // we'll also have some fun with goto and labels in here
  my_label1:
  // this is the only time && is considered 'unary operator'
  // meaning it operates on just one expression
  // and in this case it is returning the address of a label
  // tricky tricky!
  printf("&&my_label1 is %p\n", &&my_label1);
}

void main() {
  printf("fun with parenthesis!\n");
  named_function();
  printf("the address of named_function() is %p\n", &named_function);
  printf("so technically we can call a function like so (*%p)()\n", &named_function);
  // it turns out that the ampersand is actually optional
  // since you can't get the address of an address
  // and technically the function name is an address of the function
  // like an array variable is the address of the first element of the array
  (*&named_function)();
  // so this works too
  (*named_function)();


  // here's an interesting thing
  // the compiler seems to take for granted that *foo is a name
  // even though foo is undefined or defined afterward
  // hmm i wonder what is happening there?
  void (*foo)(); // throws no error
  // even if you leave foo undefined
  // i guess this is like declaring a function interface/signature
  // and incidentally, it is how you declare a function pointer
  // just like you might declare an integer pointer:
  // int* i;
  foo = &named_function;

  // now here's how you call a function pointer
  (*foo)(); // i'm a bad-ass now
  // as with the & above, technically the * is not needed here
  // since you cannot dereference a ... wait
  // why does it work?
  (foo)(); // works
  foo(); // also works
  // a function is a pointer
  // this is a pointer
  // i guess when you're calling a function
  // the dereference is implied
  // technically you CAN dereference twice though
  // but i guess the compiler is recognizing this and improvising?

  // so how could i be sneaky and define my own address constant?
  printf("manually calling adddress\n");
  const void (*bar)() = 0x40057c; // be CAREFUL with this one!
  // techically you can also use the label address to jump
  //const void (*bar)() = 0x40058a; // be CAREFUL with this one!
  // into the scope of another variable
  // but once you're in, you're on your own
  // the authors assure CRAZY ASS THINGS may happen along that journey
  // i guess because after destructors take place your function might
  // not be there anymore, or it might be someone else's function, or
  // no function at all
  (*bar)();
}
