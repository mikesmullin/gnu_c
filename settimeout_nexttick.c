#include <stdio.h>
#include <time.h>

// impressive that these work as well until you make them function declarations with {}
// instead of just function pointer declarations without {}
//void setTimeout(void(*)(), int i);
//void delay(int i, void(*)());
//void setInterval(void(*)(), int i);
//void interval(int i, void(*)());

void setTimeout(void(*cb)(), int i){}
void delay(int i, void(*cb)()){}
void nextTick(){}
void setInterval(void(*cb)(), int i){}
void interval(int i, void(*cb)()){}

void main() {
  // implementing my own main event loop
  // i guess that's basically what node v8 does
  // to get shit done quick, fast, and in a hurry! :)
  time_t started = time(NULL); // now
  printf("started at %u\n", (unsigned int) started); // unix timestamp

  // define an array of function pointers
  // TODO: how does one define a dynamically sized array? hmm
  void (*callbacks[4])();

  // TODO: hrmm i need to get miliseconds though, too...

  // queue some shit up
  // loop until queue is empty
  /*
  while (1) {
    // loop until, either:
    //   (some timers are in queue; and,
    //     enough milliseconds have passed that a timeout or interval should execute); or,
    //   (there is some function that hasn't returned/exited yet)
    // ok so here is where the hot coffee analogy comes in
    //   a callback throws your coffee at you
    //   i wonder how that works when javascript is doing something
    //   does it get interrupted by setTimeout? or does setTimeout get delayed?
    //   i would guess it has to get delayed
    //   i could test this in node
    //     setTimeout(function(){console.log('interrupt');}, 1000); while(1){}; # uninterruptable?
    //   aha so if there is a system-level blocking event happening, setTimeout gets delayed
    //   which makes sense cuz how else could the main event loop operate?
  }
  */

  //while (1) {
  //}
}
