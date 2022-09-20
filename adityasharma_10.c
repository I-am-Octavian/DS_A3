#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define length 100

int FirstQueue[length];
int FirstFront = 0;
int FirstRear = -1;

int SecondQueue[length];
int SecondFront = 0;
int SecondRear = -1;

void resetFirstQueue()
{
    FirstFront = 0;
    FirstRear = -1;
}

void FirstEnqueue(int theElement)
{
    if(FirstRear == length-1)
        printf("Overflow!!!\n");
    else
    {
        FirstQueue[++FirstRear] = theElement;
    }
}

int FirstDequeue()
{
    if(FirstRear == -1)
        return -999; // Underflow
    else
    {
        int temp = FirstQueue[FirstFront];
        FirstFront++;

        if(FirstFront > FirstRear)
            resetFirstQueue();

        return temp;
        
    }
}

bool isFullFirstQueue()
{
    if(FirstRear == length-1)
        return true;
    else
        return false;
}

bool isEmptyFirstQueue()
{
    if(FirstFront > FirstRear)
        return true;
    else
        return false;
}


void resetSecondQueue()
{
    SecondFront = 0;
    SecondRear = -1;
}

void SecondEnqueue(int theElement)
{
    if(SecondRear == length-1)
        printf("Overflow!!!\n");
    else
    {
        SecondQueue[++SecondRear] = theElement;
    }
}

int SecondDequeue()
{
    if(SecondRear == -1)
        return -999; // Underflow
    else
    {
        int temp = SecondQueue[SecondFront];
        SecondFront++;

        if(SecondFront > SecondRear)
            resetSecondQueue();

        return temp;
        
    }
}

bool isFullSecondQueue()
{
    if(SecondRear == length-1)
        return true;
    else
        return false;
}

bool isEmptySecondQueue()
{
    if(SecondFront > SecondRear)
        return true;
    else
        return false;
}

void push(int theElement)
{
    if(isEmptySecondQueue())
        FirstEnqueue(theElement);
    else // FirstQueue is empty
        SecondEnqueue(theElement);
}

int pop()
{
    if(isEmptySecondQueue())
    {
        while(FirstFront != FirstRear)
        {
            int temp = FirstDequeue();
            if(temp == -999)
                return temp;
            SecondEnqueue(temp);
        }
        return FirstDequeue();
    }
    else
    {
        while(SecondFront != SecondRear)
        {
            int temp = SecondDequeue();
            if(temp == -999)
                return temp;
            FirstEnqueue(temp);
        }
        return SecondDequeue();
    }
}

int main(void)
{
    push(5);
    push(4);
    push(8);
    push(6);
    push(9);

    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());
    printf("%d\n", pop());

}