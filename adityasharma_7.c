#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define length 5

int queue[length];
int front = -1;
int rear = -1;

void resetQueue()
{
    front = -1;
    rear = -1;
}

void enqueue(int theElement)
{
    if((rear+1)%length == front)
    {
        puts("Overflow!!!");
    }
    else
    {
        if(front == -1)
        {
            front = 0;
            rear = 0;
            queue[rear] = theElement;
        }
        else
        {
            rear = (rear + 1)%length;
            queue[rear] = theElement;
        }
    }
}

int dequeue()
{
    if(rear == -1)
        return -999;
    else
    {
        int returnValue;
        if(front == rear) // Only one element in the queue
        {
            returnValue = queue[front];
            resetQueue();
        }
        else
        {
            returnValue = queue[front];
            front = ++front % length;
        }
        return returnValue;
    }
}

bool isFullQueue()
{
    if((rear+1)%length == front)
        return true;
    else
        return false;
}

bool isEmptyQueue()
{
    if(rear == -1)
        return true;
    else
        return false;
}

int main(void)
{
    enqueue(5);
    enqueue(7);
    printf("%d\n", dequeue());
    enqueue(17);
    enqueue(75);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    enqueue(71);
    enqueue(27);
    printf("%d\n", dequeue());
    enqueue(76);
    enqueue(70);
    enqueue(48);
    enqueue(45);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
}