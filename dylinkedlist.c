#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

const int SIZE = 10;
int found_at;
typedef struct node
{
    int data;
    struct node *next;
}
node;

node *head = NULL;

int length(void)
{
    node *ptr;
    ptr = head;
    int count = 0;
    while (ptr -> next != NULL)
    {
        count++;
        ptr = ptr -> next;
    }
    count++;
    return count;
}



bool contains(int user_int)
{
    node *traverse_ptr = NULL;
    traverse_ptr = head;
    int count = 0;
    if (traverse_ptr == NULL)
    {
        fprintf(stderr, "The traverse pointer is null.");
        exit (1);
    }
    while (traverse_ptr != NULL)
    {
        if (traverse_ptr -> data == user_int)
        {
            found_at = count;
            return true;
        }
        count ++;
        traverse_ptr = traverse_ptr -> next;
    }
    return false;
}





int main(int argc, char *argv[])
{
    for (int i = 0; i < SIZE; i++)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            exit (1);
        }
        new_node -> data = i;
        new_node -> next = head;
        head = new_node;
    }
    printf ("Making sure the linked list is size: %d\n", SIZE);
    
    
    
    
    assert(length() == SIZE);
    printf ("well done!\n");
    
    
    
    
    node *traverse_ptr = NULL;
    traverse_ptr = head;
    if (traverse_ptr == NULL)
    {
        fprintf(stderr, "traverse_ptr is null.");
        exit(2);
    }
    while (traverse_ptr != NULL)
    {
        printf("%d --->", traverse_ptr -> data);
        traverse_ptr = traverse_ptr -> next;
    }
    printf ("NULL\n");
    
    
    
    printf("What value are you looking for?\n");
    int user_int = GetInt();
    if (contains(user_int))
    {
        printf("We found this value. At location: %d\n", found_at);
    }
    else
    {
        printf ("Sorry! This value is not in the linked list.\n");
    }
    
    
    
    return 0;
}