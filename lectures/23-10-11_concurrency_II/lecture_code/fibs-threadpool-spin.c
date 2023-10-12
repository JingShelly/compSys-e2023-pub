#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>


//This is kind of academic correct, but we waste some resources 
//waiting for response of 1 
//waste some clock cycle for this continuous spining
//We want to sleep spining 
int fib (int n) {
  if (n < 2) {
    return 1;
  } else {
    return fib(n-1) + fib(n-2);
  }
}

pthread_mutex_t line_mutex = PTHREAD_MUTEX_INITIALIZER;
char *volatile line = NULL;
volatile int die = 0;

void* worker(void* arg) {
  arg=arg;
  int done = 0;

  //!done, if done is 0, then !done is true, 
  //Otherwise !done is false
  while (!done) {
    char *my_line = NULL;
    assert(pthread_mutex_lock(&line_mutex) == 0);

    if (line == NULL && die) {
      done = 1;
    }

    if (line != NULL) {//we protected the shared global variable line 
      my_line = line;
      line = NULL;
    }

    assert(pthread_mutex_unlock(&line_mutex) == 0);

    if (my_line != NULL) {
      int n = atoi(my_line);
      printf("fib(%d) = %d\n", n, fib(n));
      free(my_line);
    }
  }

  return NULL;
}

int main(void) {
  char *my_line = NULL;
  ssize_t line_len;
  size_t buf_len = 0;

  // Create the threads.
  int num_threads = sysconf(_SC_NPROCESSORS_ONLN);
  pthread_t *threads = malloc(num_threads*sizeof(pthread_t));
  for (int i = 0; i < num_threads; i++) {
    pthread_create(&threads[i], NULL, worker, NULL);
  }

  while ((line_len = getline(&my_line, &buf_len, stdin)) != -1) {
    int done = 0;
    while (!done) {
      assert(pthread_mutex_lock(&line_mutex) == 0);
      if (line == NULL) {
        line = strdup(my_line);
        done = 1;
      }
      assert(pthread_mutex_unlock(&line_mutex) == 0);
    }
  }

  die = 1;//be careful about mutex. do more mutex than possible

  for (int i = 0; i < num_threads; i++) {
    pthread_join(threads[i], NULL);
  }

  free(my_line);
}
