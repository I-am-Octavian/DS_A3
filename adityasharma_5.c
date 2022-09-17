#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define length 100

int stack[length];
int topIndex = -1;
 
void push(int element)
{
    if(topIndex < length-1)
        stack[++topIndex] = element;
    else
        printf("Stack Overflow, Use bigger stack");
}
 
int pop()
{
    if(topIndex == -1)
        return -999; // Underflow
    else
        return stack[topIndex--];
}

int top()
{
    if(topIndex == -1)
        return -999; // Underflow
    else
        return stack[topIndex];
}

int size()
{
    return topIndex+1;
}

int isFullStack()
{
    if(topIndex < length - 1)
        return 0;
    else
        return 1;
}

int isEmptyStack()
{
    if(topIndex < 0)
        return 1;
    else
        return 0;
}

// CHECK boundaries(overflow and underflow)
int main(void)
{
    printf("%d\n", isFullStack());
    printf("%d\n", isEmptyStack());

    push(51);
    push(74);
    push(10);
    push(47);

    printf("%d\n", isEmptyStack());

    printf("%d\n", size());
    printf("%d\n", top());

    int temp;

    temp = pop();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    temp = pop();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    temp = pop();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    temp = top();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    temp = pop();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    temp = pop();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    temp = top();
    if(temp != -999)
        printf("%d\n", temp);
    else
        puts("Underflow");

    printf("%d\n", size());

}