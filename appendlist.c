#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

const int SIZE = 10;

typedef struct node
{
    int data;
    struct node *next;
}
node;

node *head = NULL;



int append(int i)
{
    node *traverse_ptr = NULL;
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf (stderr, "malloc returns null.");
        exit(1);
    }
    new_node -> data = i;
    new_node -> next = NULL;
    if (head == NULL)
    {
        head = new_node;
        return 0;
    }
    traverse_ptr = head;
    while (traverse_ptr -> next != NULL)
    {
        traverse_ptr = traverse_ptr -> next;
    }
    traverse_ptr -> next = new_node;
    return 0;
    
    
    
}





int main(int argc, char *argv[])
{
    for (int i = 0; i < SIZE; i++)
    {
        append(i);
    }
    for (node *ptr = head; ptr != NULL; ptr = ptr -> next)
    {
        printf("%d ---> ", ptr -> data);
    }
    printf ("NULL\n");
    return 0;
}