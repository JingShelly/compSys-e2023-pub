#include <stdio.h>
#include <assert.h>

struct stack {
  int elements[3];
  int top; // first free elements
  // it will be 16 bit long , because it has 4 elements in 
};

void stack_init(struct stack *s) {
  s->top = 0;
}

int stack_push(struct stack *s, int x) {
  //we take stack *s as pointer 
  if (s->top == 3) {
    return 1;
  }
  s->elements[s->top] = x;
  s->top = s->top + 1;  
  return 0;
}

int main(void) {
  struct stack s;
  stack_init(&s);
  printf("Initial top: %d\n", s.top);
  assert(stack_push(&s, 100) == 0);
  assert(stack_push(&s, 200) == 0);
  assert(stack_push(&s, 300) == 0);
<<<<<<< HEAD
  
=======
  printf("Final top: %d\n", s.top);
>>>>>>> d617e209b6ca9aa5eaf2c61d665042c00aebe6a1
}


// it is much faster to trnasfer one integer than a whole struct 
// that's why we pass only one element