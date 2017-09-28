#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

typedef struct node
{
    char* my_string;
    struct node* next;
}
node;

int printNode_a(node anode)
{
    while (anode.next != NULL)
    {
        printf ("%s ->", anode.my_string);
        anode = *anode.next;
    }
    printf (" NULL\n");
    
    return 0;
}

int printNode_b(node* node_ptr)
{
    while((*node_ptr).next != NULL)
    {
        printf("%s ->", (*node_ptr).my_string);
        node_ptr = (*node_ptr).next;
    }
    printf (" NULL\n");
    return 0;
}

int printNode_c(node* node_ptr)
{
    while (node_ptr -> next != NULL)
    {
        printf ("%s ->", node_ptr -> my_string);
        node_ptr = node_ptr -> next;
    }
    printf (" NULL\n");
    return 0;
}

int main(void)
{
    node node1, node2, node3, node4, node5;
    node1.my_string = "abc";
    node2.my_string = "def";
    node3.my_string = "ghi";
    node4.my_string = "jkl";
    node5.my_string = "mno";
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4;
    node4.next = &node5;
    node5.next = NULL;
    printNode_a (node1);
    node* head;
    head = &node1;
    printNode_b (head);
    printNode_c (head);
    return 0;
}

