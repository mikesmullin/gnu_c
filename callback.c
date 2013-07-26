#include <stdio.h>

/*

main = ->
  x = 1
  console.log "x is #{x}"
  console.log function_after_main x, (err, number) ->
    return console.log "Error: #{err}" if err
    console.log "number is #{number}"
  console.log "done" # it should echo this before the number, i think
  # actually no it wont because nothing here is async
  # if we did nextTick() or setTimeout((->), 0) then it would
  # cool. fine for now then.

# increment a number then execute callback and return
function_after_main = (i, cb) ->
  i++
  cb null, i
*/

// i want to explore:
//  const int i
//  int* i
//  when can/can't i change i so that it also changes in main?
//  when is it a copy of i? when is it not or by reference?
// but anyway, this for now...
void function_must_be_declared_before_main(int i, void(*cb)(char *, int)) { // also works!
//void function_must_be_declared_before_main(int i, void(*cb)(char [], int)) {
  i++;
  cb(NULL, i); // i just almost forgot i was writing ANSI C! :)
}

void my_callback(char *err, int number) { // this also works and may be preferable!
//void my_callback(char err[], int number) {
  if (err != NULL) {
    printf("Error: %s\n", err);
    return;
  }

  printf("number is %i\n", number);
}

void main() {
  int x = 1;
  printf("x is %i\n", x);
  function_must_be_declared_before_main(x, my_callback);
  printf("done.\n");
}
