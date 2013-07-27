#include <stdio.h>
void main() {
  int i = 5, j = 6, k = 7; // integer data representations
  int *ip1 = &i, *ip2 = &j; // integer pointers
  int **ipp = &ip1; // pointer to an integer pointer
  // for the lulz! little/no practical use for the following declarations
  int ***ippp = &ipp; // pointer -> pointer -> integer.
  // if you try to declare a *** that points to anything other than a **
  // or a **** pointing other than ***, etc. the compiler will issue this warning
  // warning: initialization from incompatible pointer type [enabled by default]
  // because technically its just an address byte so it can fit and its allowed
  // but it wants you to know you're technically not pointing to what you think 
  // you are pointing to.
  int ****ipppp = &ippp; // p -> p -> p -> p
  int *****ippppp = &ipppp; // p -> p -> p -> p -> p
  int ******ipppppp = &ippppp; // p -> p -> p -> p -> p -> p

  printf("i is %i, j is %i, k is %i\n", i, j, k);
  printf("addressOf i is %p, addressOf j is %p, addressOf k is %p\n", &i, &j, &k);
  printf("ip1 is %p, ip2 is %p\n", ip1, ip2);
  printf("ipp is %p\n", ipp);
  printf("ippp is %p, ipppp is %p, ippppp is %p, ipppppp is %p\n", ippp, ipppp, ippppp, ipppppp);

  // what happens when we dereference N pointers to pointers?
  // well its pretty amusing as you might expect
  printf("*ip1 is %i, ", *ip1);
  printf("**ipp is %i, ", **ipp);
  printf("***ippp is %i, ", ***ippp);
  printf("*ippp is %p, ", *ippp);
  printf("****ipppp is %i, ", ****ipppp);
  printf("*****ippppp is %i, ", *****ippppp);
  printf("******ipppppp is %i\n", ******ipppppp);

  printf("what if we redirect a pointer in the chain?\n");
  ip1 = &k; // set address of k
  printf("now *ip1 is %i, ", *ip1);
  printf("**ipp is %i, ", **ipp);
  printf("***ippp is %i, ", ***ippp);
  printf("*ippp is %p, ", *ippp);
  printf("****ipppp is %i, ", ****ipppp);
  printf("*****ippppp is %i, ", *****ippppp);
  printf("******ipppppp is %i\n", ******ipppppp);

  *ipp = &j; // dereference one level, then set address of j
  // note that the compiler will let me point ipp anywhere
  // even without dereferencing it first
  // but if its not to the matching (int *) then when we
  // go to dereference ipp it will throw a segfault
  // so to change ipp in a practical way without dereffing one level
  // then i'd need to declare a new (int *) to point it to
  printf("now *ip1 is %i, ", *ip1);
  printf("**ipp is %i, ", **ipp);
  printf("***ippp is %i, ", ***ippp);
  printf("*ippp is %p, ", *ippp);
  printf("****ipppp is %i, ", ****ipppp);
  printf("*****ippppp is %i, ", *****ippppp);
  printf("******ipppppp is %i\n", ******ipppppp);

  // how can we utilize a pointer to a pointer?
  // what are the real-world applications?

  // well, array data representation is really just a pointer to the first element
  int a[3] = { 1, 2, 3 };
  printf("a is %p and sizeof(a) is %lu\n", a, sizeof(a));
  // as is the function name
  void f(void) {};
  printf("f is %p and sizeof(f) is %lu\n", f, sizeof(f));

  // but when you get into creating your own data types/representations
  // with struct and union
  // and multi-dimensional arrays
  // and building classes and instantiating them as objects
  // and calling their methods
  // then pointers that point to pointers are actually super common
  // for instance, its easier to redirect a pointer than to zero-out
  // a large section of memory which was just abandoned
}
