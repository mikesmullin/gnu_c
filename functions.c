#include <stdio.h>

//void include?() { // error: expected something else before '?' token
void include_question_mark() {
}

//void gsub!() { // error: expected something else before '!' token
void gsub_exclaimation_mark() {
}

void a(void) {
  printf("successfully called a()\n");
}

void * b(void) {
  return a;
}

void main() {
  unsigned long int a = 10L;

  void (*x)(void) = b();
  printf("x is %p\n", x);
  x();

  // technically some crazy crap like this
  // could combine the above two lines into one
  // but its beyond me at the moment
  //(void (*x(void * b()))(void)) ();
  // see also:
  // http://tigcc.ticalc.org/doc/opers.html#asterisk
}
