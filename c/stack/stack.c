#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// defining structure for stack
struct stack
{
  int items[MAX];
  int top;
};
typedef struct stack stk;

void createEmptyStack(stk *s)
{
  s->top = -1;
}

int isFull(stk *s)
{
  if (s->top == MAX - 1)
    return 1;
  else
    return 0;
}

int isEmpty(stk *s)
{
  if (s->top == -1)
    return 1;
  else
    return 0;
}

void push(stk *s, int newItem)
{
  if (isFull(s))
  {
    printf("Stack is full, cannot push item \n");
  }
  else
  {
    s->top = s->top + 1;
    s->items[s->top] = newItem;
  }
}

int pop(stk *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty, cannot pop item");
    return -1; // error value
  }
  else
  {
    int value = s->items[s->top];
    s->top = s->top - 1;
    return value;
  }
}

int peek(stk *s)
{
  if (isEmpty(s))
  {
    printf("Stack is empty, cannot peek item");
  }
  else
  {
    return s->items[s->top];
  }
}

void displayStack(stk *s)
{
  printf("Stack: ");
  for (int i = 0; i <= s->top; i++)
  {
    printf("%d ", s->items[i]);
  }
  printf("\n");
}

int main()
{
  stk *s = (stk *)malloc(sizeof(stk));

  createEmptyStack(s);

  push(s, 1);
  push(s, 7);
  push(s, 10);

  printf("Top item: %d\n", peek(s));
  printf("Popped item: %d\n", pop(s));
  printf("Popped item: %d\n", pop(s));
  displayStack(s);

  push(s, 10);
  push(s, 6);
  push(s, 19);
  push(s, 8);
  push(s, 27);
  push(s, 20);
  push(s, 13);
  push(s, 19);
  push(s, 17);
  push(s,99);

  displayStack(s);
  return 0;
}