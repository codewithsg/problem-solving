#include <stdio.h>
#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
  if (rear == front - 1 || (rear == SIZE - 1 && front == SIZE - 1))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int isEmpty()
{
  if ((front == -1 && rear == -1))
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void enqueue(int item)
{
  if (isFull())
  {
    printf("Queue is full\n");
  }
  else
  {
    if (isEmpty())
    {
      front = 0;
    }
    if (rear == SIZE - 1 && front != 0)
    {
      rear = -1;
    }
    rear++;
    items[rear] = item;
  }
}

int dequeue()
{
  if (isEmpty())
  {
    printf("Queue is empty");
    return -1;
  }
  else
  {
    int item = items[front];
    if (front == rear)
    {
      front = -1;
      rear = -1;
      return item;
    }
    front++;
    if (front == SIZE && rear != SIZE - 1)
    {
      front = 0;
    }
    return item;
  }
}

void display()
{
  printf("Queue: ");
  int k = front;
  printf("%d ", items[k]);
  while (k != rear)
  {
    k = k + 1;
    if (k == SIZE)
    {
      k = 0;
    }
    printf("%d ", items[k]);
  }
  printf("\n");
}

int main()
{
  enqueue(3);

  enqueue(5);

  enqueue(7);

  enqueue(9);

  enqueue(11);

  printf("%d \n", dequeue());

  enqueue(13);

  enqueue(15);

  printf("%d \n", dequeue());

  printf("%d \n", dequeue());

  printf("%d \n", dequeue());

  printf("%d \n", dequeue());

  printf("%d \n", dequeue());

  enqueue(15);

  enqueue(17);

  printf("%d \n", dequeue());

  printf("%d \n", dequeue());

  printf("%d \n", dequeue());

  return 0;
}
