#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Check overflow and underflow in stack
#define length 100

int enqueueStack[length];
int enqueueTop = -1;

int dequeueStack[length];
int dequeueTop = -1;
 
void enqueuePush(int element)
{
    if(enqueueTop < length-1)
        enqueueStack[++enqueueTop] = element;
    else
        printf("Stack Overflow, Use bigger stack");
}
 
int enqueuePop()
{
    if(enqueueTop == -1)
        return -999;
    else
        return enqueueStack[enqueueTop--];
}

bool enqueueIsFull()
{
    if(enqueueTop < length - 1)
        return false;
    else
        return true;
}

bool enqueueIsEmpty()
{
    if(enqueueTop < 0)
        return true;
    else
        return false;
}

void dequeuePush(int element)
{
    if(dequeueTop < length-1)
        dequeueStack[++dequeueTop] = element;
    else
        printf("Stack Overflow, Use bigger stack");
}
 
int dequeuePop()
{
    if(dequeueTop == -1)
        return -999;
    else
        return dequeueStack[dequeueTop--];
}

bool dequeueIsFull()
{
    if(dequeueTop < length - 1)
        return false;
    else
        return true;
}

bool dequeueIsEmpty()
{
    if(dequeueTop < 0)
        return true;
    else
        return false;
}

void enqueue(int theElement)
{
    while (!dequeueIsEmpty())
    {
        enqueuePush(dequeuePop());
    }
    enqueuePush(theElement);
}

int dequeue()
{
    while(!enqueueIsEmpty())
    {
        dequeuePush(enqueuePop());
    }

    return dequeuePop();
}

int main(void)
{
    enqueue(1);
    enqueue(2);
    enqueue(6);
    enqueue(3);
    enqueue(4);

    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());


}