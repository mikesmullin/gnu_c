#include <stdio.h>

void main() {
  // watch this shit
  int a[] = { 3, 1, 2 }; // define array of size 3
  printf("a[0] is %i\n", a[0]);
  printf("a[1] is %i\n", a[1]);
  printf("a[2] is %i\n", a[2]);
  printf("remember that a is just a pointer %p\n", a);
  printf("and the square brackets expr1[expr2] are lexically equivalent to *(expr1 + expr2)\n");
  printf("so %p + %i is %p, therefore *(%p + %i) is %i as *(%p) is %i\n", a, 0, a+0, a, 0, *(a+0), a+0, *(a+0));
  printf("and %p + %i is %p, therefore *(%p + %i) is %i as *(%p) is %i\n", a, 1, a+1, a, 1, *(a+1), a+1, *(a+1));
  printf("and %p + %i is %p, therefore *(%p + %i) is %i as *(%p) is %i\n", a, 2, a+2, a, 2, *(a+2), a+2, *(a+2));
}
