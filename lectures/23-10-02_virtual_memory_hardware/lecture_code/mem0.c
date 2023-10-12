#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
  (void)argc;
  size_t num_gib = atoi(argv[1]);
  size_t to_alloc = num_gib * 1024 * 1024 * 1024;

  printf("allocating %ld bytes\n", (long)to_alloc);

  unsigned char *p = malloc(to_alloc);
  assert(p != NULL);

  if (p) {
    while (1) ;
  }
}

//using htop to show the memory
// there is additional swp memeory, which is not 

//SO if I have 15g, but swp has 2g, so I have totally 17g can be allocated
//but it will be a litte slower 
//it means that we can run a program that is a slight larger than our memory 

//To run this program, you should give a gega byte to the argument 