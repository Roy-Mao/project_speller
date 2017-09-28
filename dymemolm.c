//12:23
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    char *ptr;
    int count = 0;
    ptr = malloc(sizeof(char));
    while (ptr)
    {
        count ++;
        ptr = malloc(sizeof(char));
        printf ("%d\n", count);
    }
    printf("finished");
    return 0;
}