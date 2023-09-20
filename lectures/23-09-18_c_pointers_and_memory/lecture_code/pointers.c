#include <stdio.h>

int main(void) {
  int x = 2;
  int y = 3;
  printf("x: %d\n", x); 
  printf("&x: %p\n", (void*)&x); // & is to say that return the address of the variable
  printf("y: %d\n", y);
  printf("&y: %p\n", (void*)&y);

  // return 0;

  int* px; // * Pointer Declaration
  int* py;

  px = &x;
  py = &y;

  // x x x x
  // y y y y
  // px px px px px px px px
  // py py py py py py py py


  // x has type T
  // &x has type T*
  printf("px: %p\n", (void*)px);
  printf("&px: %p\n", (void*)&px); // int**
  printf("py: %p\n", (void*)py);
  printf("&py: %p\n", (void*)&py); // int**

  *px = 5;// go to the position where px pointer to and sign this value to it .

  printf("x: %d\n", x);
  printf("y: %d\n", y);
}
