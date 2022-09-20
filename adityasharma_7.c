#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define length 100

int queue[length];
int front = 0;
int rear = -1;

void resetQueue()
{
    front = 0;
    rear = -1;
}

void enqueue(int theElement)
{
    if(rear == length-1)
        printf("Overflow!!!\n");
    else
    {
        queue[++rear] = theElement;
    }
}

int dequeue()
{
    if(rear == -1)
        return -999; // Underflow
    else
    {
        int temp = queue[front];
        front++;

        if(front > rear)
            resetQueue();

        return temp;
        
    }
}

bool isFullQueue()
{
    if(rear == length-1)
        return true;
    else
        return false;
}

bool isEmptyQueue()
{
    if(front > rear)
        return true;
    else
        return false;
}

int main(void)
{
    //
}