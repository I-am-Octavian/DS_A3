#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

Node *List = NULL;

void push(int theElement)
{
    if(List == NULL)
    {
        List = (Node*) malloc(sizeof(Node));
        List->element = theElement;
        List->next = NULL;
        return;
    }

    Node *tempList = List;

    while(tempList->next != NULL)
    {
        tempList = tempList->next;
    }

    Node* tempNode = (Node *)malloc(sizeof(Node));
    if(tempNode == NULL)
    {
        //System out of memory
        printf("Overflow");
        return;
    }

    tempList->next = tempNode;
    tempList = tempList->next;

    tempList->element = theElement;
    tempList->next = NULL;
}

int pop()
{
    if(List == NULL)
    {
        return -999;
    }

    if(List->next == NULL)
    {
        int tempNodeElement = List->element;
        free(List);
        List = NULL;
        return tempNodeElement;
    }

    Node *tempList = List;

    while((tempList->next)->next != NULL)
    {
        tempList = tempList->next;
    }

    // Now tempList points to second last node
    int tempNodeElement = (tempList->next)->element;
    free(tempList->next);
    tempList->next = NULL;

    return tempNodeElement;
}

int top()
{
    if(List == NULL)
    {
        return -999;
    }

    if(List->next == NULL)
    {
        return List->element;
    }

    Node* tempNode = List;
    while(tempNode->next != NULL)
    {
        tempNode = tempNode->next;
    }

    return tempNode->element;
}

int size()
{
    int stackSize = 0;

    Node* tempNode = List;
    while (tempNode != NULL)
    {
        stackSize++;
        tempNode = tempNode->next;
    }

    return stackSize;

}

int isEmptyStack()
{
    if(size() == 0)
        return true;
    else
        return false;
}

int isFullStack()
{
    Node* newNode = (Node *)malloc(sizeof(Node));

    if(newNode == NULL) // If new node is not created then stack(Linked List) is full
        return true;
    else
    {
        free(newNode);
        return false;
    }

}

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