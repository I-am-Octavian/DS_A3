#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define length 100

typedef struct Node
{
    int element;
    struct Node *next;
} Node;

Node* hashTableSC[length];

void init()
{
    for(int i = 0; i < length; i++)
    {
        hashTableSC[i] = NULL;
    }
}
// Probably implement a better hash function
int hash(int theElement)
{
    return theElement % length;
}

bool searchSC(int theElement)
{
    int key = hash(theElement);
    Node* tempNode = hashTableSC[key];

    while (tempNode != NULL)
    {
        if(tempNode->element == theElement)
            return true;    
        tempNode = tempNode->next;
    }

    return false;
}

void insertSC(int theElement)
{
    int key = hash(theElement);
    
    if(hashTableSC[key] == NULL)
    {
        hashTableSC[key] = (Node *)malloc(sizeof(Node));

        Node *tempList = hashTableSC[key];
        tempList->element = theElement;
        tempList->next = NULL;
    }
    else // Seperate Chaining
    {
        Node *tempList = hashTableSC[key];
    
        while(tempList->next != NULL)
        {
            tempList = tempList->next;
        }

        tempList->next = (Node *)malloc(sizeof(Node));
        tempList = tempList->next;

        tempList->element = theElement;
        tempList->next = NULL;
    }
}


void deleteSC(int theElement)
{
    int key = hash(theElement);

    if(hashTableSC[key] == NULL)
    {
        printf("No matching element to delete\n");
        return;
    }

    if(hashTableSC[key]->element == theElement)
    {
        Node *tempNode = hashTableSC[key];
        hashTableSC[key] = hashTableSC[key]->next;
        free(tempNode);
    }
    else
    {
        Node *tempList = hashTableSC[key];

        while(tempList->next != NULL)
        {
            if(tempList->next->element == theElement)
            {
                Node* tempNode = tempList->next;
                tempList->next = tempNode->next;
                free(tempNode);
            }

            tempList = tempList->next;

        }
    }
}

void linearProbing(int theElement)
{
    //
}

int main(void)
{
    //
}