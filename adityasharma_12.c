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
    hashValue %= length;
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
        while (iteratorNode->next != NULL)
        {
            iteratorNode = iteratorNode->next;
        }

        Node* tempNode = (Node* ) malloc(sizeof(Node));
        tempNode->element = word;
        tempNode->next = NULL;

        iteratorNode->next = tempNode;        
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

void makeTable()
{
    FILE* file;
    file = fopen("filename.txt", "r");

    char ch;
    do
    {
        ch = fgetc(file);
        char* word = (char*) malloc(sizeof(char));
        int i = 0;
        while (ch != '\n' && ch != EOF)
        {
            word[i] = ch;
            i++;
            ch = fgetc(file);
        }
        word[i] = '\0';
        insert(word, i);
    }while (ch != EOF);
    fclose(file);
}

int main(void)
{
    init();
    makeTable();
    printf("%d\n", countOccurences("word1", 5));
}
