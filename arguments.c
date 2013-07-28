#include <stdio.h>

typedef struct {
  void ** arguments;
} ArgumentList;

void make_arguments(...) {
  // hmm no matter what i do i need to know the number of arguments ahead of time
  // it will only work if i have a precompiler involved here or if i just adopt a
  // convention of always passing the number of args first to a function that could
  // take a variable number of arguments
  // so i guess if i wanted javascript-like functionality i would need to build this
  // into the preprocessor/transpiler
}

void hamster(ArgumentList arguments) {
  ArgumentList.arguments()
}


void main() {
  hamster(make_arguments(3));
}
