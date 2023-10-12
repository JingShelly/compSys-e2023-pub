#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int main(int argc, char** argv) {
  (void)argc;
  size_t num_gib = atoi(argv[1]);
  int num_writes = atoi(argv[2]);
  int stride = atoi(argv[3]);
  size_t to_alloc = num_gib * 1024 * 1024 * 1024;

  printf("allocating %ld bytes\n", (long)to_alloc);

  unsigned char *p = malloc(to_alloc);
  assert(p != NULL);

  if (p) {
    while (1) {
      for (int i = 0; i < num_writes; i++) {
        p[(i*stride) % to_alloc] = rand();
      }
    }
  }
}
// we are tring to acesse the memory several times and see how the stride.... 
// we can try to give the argument like 15 100000 100000(sth very large)
// and then give it 15 1000000 1000000 again,and observe how htop looks like
//if we keep allocate the memory again and again, then it is a lot of cache misses
// Then it will reach a point where the os will say stop it.

//we can assign more vitual memory than it is allowed 