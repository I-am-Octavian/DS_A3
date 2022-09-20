#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <memory.h>

typedef struct Node
{
    int element;
    struct Node *prev;
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
    tempList->prev = NULL;
    for(unsigned int i = 1; i < n; i++)
    {
        tempList->next = (Node *)malloc(sizeof(Node));

        (tempList->next)->prev = tempList;
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

void insertBegining(int theElement)
{
    Node *tempNode = (Node *)malloc(sizeof(Node));

    tempNode->element = theElement;
    tempNode->next = List;
    tempNode->prev = NULL;
    List->prev = tempNode;

    List = tempNode;
}

void insertEnd(int theElement)
{
    Node *tempList = List;
    
    while(tempList->next != NULL)
    {
        tempList = tempList->next;
    }

    tempList->next = (Node *)malloc(sizeof(Node));
    (tempList->next)->prev = tempList;
    tempList = tempList->next;

    tempList->element = theElement;
    tempList->next = NULL;
}


void deleteBegining()
{
    Node *tempNode = List;
    List = List->next;
    free(tempNode);
    List->prev = NULL; // As List now points to the second node
}

void deleteEnd()
{
    Node *tempList = List;
    
    while((tempList->next)->next != NULL)
    {
        tempList = tempList->next;
    }
    
    // Now tempList points to second last node
    free(tempList->next);
    tempList->next = NULL;
}

void insertBetween(int theElement, unsigned int insertionIndex)
{
    //
}

void deleteBetween(int theElement, unsigned int deletionIndex)
{
    //
}

int main(void)
{
    puts("Enter Number of Nodes 'n'");
    int n;
    scanf("%d", &n);

    createList(10);
    display();

    insertBegining(20);
    display();

    insertEnd(87);
    display();

    deleteBegining();
    display();

    deleteEnd();
    display();
}