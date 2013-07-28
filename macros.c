#include <stdio.h>
#include <stdarg.h>
#define lambda(return_type, ...) \
  __extension__ \
  ({ \
    return_type __fn__ __VA_ARGS__ \
    __fn__; \
  })

void main() {
  void * a = lambda(void *, (void * this, int va_length, ...) {
    printf("hello world!\n");
  });
  /*
  translates to:
  void * a = ({ void * __fn__ (void * this, int va_length, ...) {
    printf("hello world!\n");
  } __fn__; });


  eventually i'll have my coffee version translate from:

  void * a = (int x, int y) ->
    console.log "hello world!";
  }

  to:

  #include <stdarg.h>
  void * a = ({ void * __lambda(void * this, int va_length, ...){
    va_list args;
    va_start(args, va_length);
    int x = va_arg(args, int);
    int y = va_arg(args, int);
    printf("hello world!\n");
  } __lambda; });

  */
}
