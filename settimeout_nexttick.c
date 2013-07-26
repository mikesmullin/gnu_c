#include <stdio.h>
#include <time.h>

// impressive that these work as well until you make them function declarations with {}
// instead of just function pointer declarations without {}
//void setTimeout(void(*)(), int i);
//void delay(int i, void(*)());
//void setInterval(void(*)(), int i);
//void interval(int i, void(*)());

int timer_callback_stack_index = 0;
void (*timer_callback_stack[4])();
void setTimeout(void(*cb)(), int i) {
  timer_callback_stack[timer_callback_stack_index++] = cb;
  // TODO also note the unix timestamp in the future when it should occur
  // TODO: learn to define my own datatype for that
}
void delay(int i, void(*cb)()){ setTimeout(cb, i); }
void nextTick(void(*cb)()){ setTimeout(cb, 0); }
void setInterval(void(*cb)(), int i){
  setTimeout(cb, i);
}
void interval(int i, void(*cb)()){ setInterval(cb, i); }

void main() {
  // implementing my own main event loop
  // i guess that's basically what node v8 does
  // to get shit done quick, fast, and in a hurry! :)
  time_t started = time(NULL); // now
  printf("started at %u\n", (unsigned int) started); // unix timestamp
  // TODO: hrmm i need to get miliseconds though, too...

  // TODO: how does one define a dynamically sized array? hmm
  // there should be a generic extension you can apply to any array to give it wings
  // so it can do things like .push() .pop() .shift() and .unshift() hmmm...
  // i guess that would be an array object
  // how to implement an array object in C?
  // one that can contain anything might be fun. if it did malloc() on every add()
  // hmmm.. now we're deep in the weeds of systems programming
  // i wonder how node and java et. all do it?
  // well, a static size will work for now in this example

  // queue some shit up
  delay(3000, ({void __fn__() {
    printf("this should happen after 3 seconds");
  }; __fn__; }));

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
  timer_callback_stack[0]();
  //}
}
