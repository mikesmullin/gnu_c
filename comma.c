#include <stdio.h>

int hamster() {
  int a = 0, b = 20;

  // the comma operator (represented by the token ,)
  // is a binary operator that evaluates its first operand
  // and discards the result,
  // and then evaluates the second operand
  // and returns this value (and type).
  //
  // the use of the comma token as an operator is distinct
  // from its use in function calls and definitions,
  // variable declarations, enum declarations, and
  // similar constructs, where it acts as a separator.
  return a + 1, b;
}

void main() {
  printf("hamster sez %i\n", hamster());
}
