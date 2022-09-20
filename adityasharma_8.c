#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

Node *List = NULL;

void enqueue(int theElement)
{
    // Create a list if not created before
    if(List == NULL)
    {
        List = (Node *)malloc(sizeof(Node));
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
        puts("Overflow");
        return;
    }

    tempList->next = tempNode;
    tempList = tempList->next;

    tempList->element = theElement;
    tempList->next = NULL;
}


int dequeue()
{
    if(List == NULL)
    {
        puts("UNDERFLOW!");
        return -999;
    }

    int queueHead = List->element;
    Node *tempNode = List;
    List = List->next;

    free(tempNode);

    return queueHead;
}


int main(void)
{
    enqueue(51);
    enqueue(52);
    enqueue(53);
    enqueue(54);
    enqueue(55);

    int temp;

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);

    enqueue(55);

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);

    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);
    
    temp = dequeue();
    if(temp!=-999)
        printf("%d\n", temp);


}