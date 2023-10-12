#include <unistd.h>
#include <stdio.h>

int main(void) {
  int num_children = 10;

  for (int i = 0; i < num_children; i++) {
    if (fork() == 0) {
      // In child.
      while (1); 
    }
  }

  return 0; // Parent terminates.
}

//The children will run without termination, the parent return 0, it finished.
// So there is no parent to kill the processing children. if you write htop in 
//the terminal, you will see that there will be 10 process going. 
//you can kill them by type in "pkill -f ./zombies"