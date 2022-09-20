#include <stdio.h>
#include <memory.h>
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

void insertBegining(int theElement)
{
    Node *tempNode = (Node *)malloc(sizeof(Node));
    tempNode->element = theElement;
    tempNode->next = List;
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
    tempList = tempList->next;

    tempList->element = theElement;
    tempList->next = NULL;
}

// Insert at an index(Assuming index starts from "0")
void insertInBetween(int theElement, unsigned int insertionIndex)
{
    // Check for empty list
    if(List == NULL)
    {
        printf("Create List before inserting inbetween\n");
        return;
    }

    // Insert in the beigning
    if(insertionIndex == 0)
    {
        insertBegining(theElement);
        return;
    }

    Node *tempList = List;
    for(unsigned int i = 0; i < insertionIndex-1; i++)
    {
        if(tempList == NULL)
        {
            printf("Wrong insertionIndex, %d not inserted\n", theElement);
            return;
        }
        tempList = tempList->next;
    }

    Node *tempNode = (Node *)malloc(sizeof(Node));
    tempNode->element = theElement;
    tempNode->next = tempList->next;

    tempList->next = tempNode;
}

void deleteBegining()
{
    Node *tempNode = List;
    List = List->next;
    free(tempNode);
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

void deleteInBetween(unsigned int deletionIndex)
{
    // Check for empty list
    if(List == NULL)
    {
        printf("No List to delete from\n");
        return;
    }

    // Deleting in the beigning
    if(deletionIndex == 0)
    {
        deleteBegining();
        return;
    }

    Node *tempList = List;
    for(unsigned int i = 0; i < deletionIndex-1; i++)
    {
        if(tempList == NULL)
        {
            printf("Wrong deletionIndex, no element deleted\n");
            return;
        }
        tempList = tempList->next;
    }
    //
    Node *tempNode = tempList->next;
    
    tempList->next = tempNode->next;

    free(tempNode); 
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