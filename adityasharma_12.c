#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define size 10000
// Specify size of element
typedef struct Node
{
    char* element;
    struct Node* next;
}Node;

Node* hashTable[size];

void init()
{
    for(int i = 0; i < size; i++)
    {
        hashTable[i] = NULL;
    }
}

int hash(char s[], int length)
{
    int hashValue = 0;
    for(int i = 0; i < length; i++)
    {
        hashValue += pow(31, i) * s[i];
    }
    return hashValue;
}

void insert(char word[], int length)
{
    int key = hash(word, length);

    if(hashTable[key] == NULL)
    {
        hashTable[key] = (Node*)malloc(sizeof(Node));
        hashTable[key]->element = word;
        hashTable[key]->next = NULL;
    }
    else
    {
        Node *iteratorNode = hashTable[key];
        while (iteratorNode != NULL)
        {
            iteratorNode = iteratorNode->next;
        }

        iteratorNode = (Node*) malloc(sizeof(Node));
        iteratorNode->element = word;
        iteratorNode->next = NULL;
        
    }
}

int countOccurences(char word[], int length)
{
    int key = hash(word, length);
    int counter = 0;
    Node* iteratorNode = hashTable[key];

    while(iteratorNode != NULL)
    {
        counter++;
        iteratorNode = iteratorNode->next;
    }

    return counter;
}

int main(void)
{
    //
}