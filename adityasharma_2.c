#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

Node *List = NULL;

// To create a list of n elements
void createList(unsigned int n)
{

    List = (Node *)malloc(sizeof(Node));

    Node *tempList = List;
    tempList->element = 0;
    tempList->next = NULL;
    for(unsigned int i = 1; i < n; i++)
    {
        tempList->next = (Node *)malloc(sizeof(Node));
        tempList = tempList->next;

        tempList->element = i;
        tempList->next = NULL;
    }
}

void display()
{
    Node *LinkedList = List;
    while (LinkedList->next != NULL)
    {
        printf("%d ", LinkedList->element);
        LinkedList = (Node *)LinkedList->next;
    }
    printf("%d\n", LinkedList->element);
}

void reverseLinkdedList()
{
    Node* lastNode = NULL;
    Node* nextNode = List;
    Node* tempNode = List;

    while(tempNode != NULL)
    {
        nextNode = tempNode->next;
        tempNode->next = lastNode;
        lastNode = tempNode;
        tempNode = nextNode;
    }
    List = lastNode;
}

int main(void)
{
    createList(10);
    display();
    reverseLinkdedList();
    display();
}