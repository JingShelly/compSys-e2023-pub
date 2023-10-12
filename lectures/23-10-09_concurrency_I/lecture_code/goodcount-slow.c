#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t cnt_mutex = PTHREAD_MUTEX_INITIALIZER;
volatile int cnt = 0;

void *thread(void *vargp) {
  int n = *((int*)vargp);

  for (int i = 0; i < n; i++) {
    pthread_mutex_lock(&cnt_mutex);
    cnt++;
    pthread_mutex_unlock(&cnt_mutex);
  }

  return NULL;
}

int main(int argc, char **argv) {
  int n = atoi(argv[1]);
  pthread_t tid1, tid2;
  pthread_create(&tid1,
                 NULL,
                 thread,
                 &n);
  pthread_create(&tid2,
                 NULL,
                 thread,
                 &n);
  pthread_join(tid1, NULL);
  pthread_join(tid2, NULL);
  if (cnt != 2 * n)
    printf("Bad:  %d\n", cnt);
  else
    printf("Good: %d\n", cnt);
}
///time ./goodcount-slow 20000 to calculate the time 
//real: physical time from starting command to finish, progresses
//system: time spent on the kernel cores
//user: it is a measure of each thread. the sum of each thread 
//The concept of mutex is to lock some of the memory and not permit parallel progress
//some of that time is overlap
//Because we lock it every time, so it is slow 
//graping it does take some of the competition 
