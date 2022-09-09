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

    tempList->next = List;
}

void display()
{
    Node *LinkedList = List;
    while (LinkedList->next != List)
    {
        printf("%d ", LinkedList->element);
        LinkedList = (Node *)LinkedList->next;
    }
    printf("%d\n", LinkedList->element);
}

int main(void)
{
    puts("Enter Number of Nodes 'n'");
    int n;
    scanf("%d", &n);

    createList(10);
    display();
}