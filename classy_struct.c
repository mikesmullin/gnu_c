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
}
