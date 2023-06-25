#include <stdio.h>

#define SIZE 5

int items[SIZE];
int front = -1;
int rear = -1;

int isFull()
{
  if (rear == SIZE - 1 || front == SIZE - 1)
    return 1;
  else
    return 0;
}

int isEmpty()
{
  if ((rear == -1 && front == -1) || (rear == SIZE - 1 && front == SIZE - 1))
    return 1;
  else
    return 0;
}

void queue(int item)
{
  if (rear == SIZE - 1 && front == SIZE - 1)
  {
    rear = -1;
    front = -1;
  }
  if (isFull())
  {
    printf("Queue is full.\n");
  }
  else
  {
    if (isEmpty())
    {
      front++;
    }
    rear++;
    items[rear] = item;
  }
}

int dequeue()
{
  if (isEmpty())
  {
    printf("Queue is empty.");
    return -1;
  }
  else
  {
    int item = items[front];
    front++;
    return item;
  }
}

int peek()
{
  if (isEmpty())
  {
    printf("Queue is empty.");
    return -1;
  }
  else
  {
    return items[front];
  }
}

void displayQueue()
{
  printf("Queue: ");
  for (int i = front; i <= rear; i++)
  {
    printf("%d ", items[i]);
  }
  printf("\n");
}

int main()
{
  queue(3);
  queue(5);
  queue(7);

  printf("%d \n", dequeue());
  queue(3);
  queue(5);
  queue(7);
  queue(7);

  displayQueue();

  printf("%d \n", dequeue());
  printf("%d \n", dequeue());
  printf("%d \n", dequeue());
  printf("%d \n", dequeue());
  printf("%d \n", dequeue());
  printf("%d \n", dequeue());
  printf("%d \n", dequeue());

  queue(3);
  queue(4);

  displayQueue();

  return 0;
}