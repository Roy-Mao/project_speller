//12:02
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>

const int SIZE = 1000;

typedef struct node
{
    int data;
    struct node *next;
}
node;

node *head = NULL;

int insert_sorted(int random_num)
{
    node *new_node = malloc(sizeof(node));
    if (new_node == NULL)
    {
        fprintf(stderr, "no space allocated in heap.");
        exit(1);
    }
    new_node -> data = random_num;
    new_node -> next = NULL;
    node *cur_ptr = NULL;
    node *pre_ptr = NULL;
    for (cur_ptr = head; cur_ptr != NULL; cur_ptr = cur_ptr -> next)
    {
        if (cur_ptr -> data > random_num)
        {
            break;
        }
        else
        {
            pre_ptr = cur_ptr;
        }
    }
    if (pre_ptr == NULL)
    {
        new_node -> next = head;
        head = new_node;
    }
    else
    {
        new_node -> next = cur_ptr;
        pre_ptr -> next = new_node;
    }
    return 0;
}


int main(int argc, char *argv[])
{
    for (int i = 0; i < 10; i++)
    {
        int random_num;
        random_num = rand() % SIZE;
        insert_sorted(random_num);
    }
    node *traverse_ptr = head;
    while (traverse_ptr != NULL)
    {
        printf("%d --->", traverse_ptr -> data);
        traverse_ptr = traverse_ptr -> next;
    }
    printf ("NULL\n");
    return 0;
}
