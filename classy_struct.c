#include <stdio.h>

void main() {
  struct car {
    unsigned char * color;
    unsigned int year;
  } my_car;
  typedef struct car vehicle;
  my_car.color = "green";
  my_car.year = 2001;
  vehicle wife_car;
  wife_car.color = "white";
  wife_car.year = 2013;
  printf("my car's color is %s and the year is %i\n", my_car.color, my_car.year);
  printf("wife car's color is %s and the year is %i\n", wife_car.color, wife_car.year);
  typedef struct {unsigned char * name, * color;} pet;
  pet dog = { name: "Honey", color: "brown with white patches" };
  pet guinea = { "Ariel", "black with white patches" };
  printf("our pet's name is %s and her color is %s\n", dog.name, dog.color);
  printf("our other pet's name is %s and her color is %s\n", guinea.name, guinea.color);
  // use the dot version when accessing elements of a struct/class
  // use the Arrow Operator (->) when operating on a pointer to a struct
  // e.g., foo->bar is equivalent to (*foo).bar
  pet * alias = &guinea;
  alias->name = "Red";
  alias -> color = "Strawberry Blonde; red, white, with some dark brown";
  printf("our other pet's name is %s and her color is %s\n", guinea.name, guinea.color);

  // you can initialize structs while you define them
  // and set all or part of the possible data
  struct Class {
    char * name;
    void * (*ctor)(void);
    void * (*dtor)(void);
  } Animal = { name: "Canine" };
  struct Class * my_pet = &Animal;

  // you can also test for the presence of data assignment like so
  if (my_pet -> ctor) { // non-zero value
    printf("Animal has a constructor.\n");
  }
  else if (my_pet->ctor == 0) { // zero?
    // i guess when a pointer is uninitialized, it is zero
    printf("Animal has no constructor.\n");
  }
}
