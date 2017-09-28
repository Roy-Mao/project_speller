
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    char my_array[27];
    bool exist;
}
node;

void iterate(const char *aptr)
{
    int i = 0;
    char current_char = aptr[i];
    while (current_char != '\0')
    {
        printf ("%c", current_char);
        i++;
        current_char = aptr[i];
    }
}

int main(void)
{
    char str1[10];
    FILE *fptr = fopen("roy.txt", "r");
    if (fptr == NULL)
    {
        fprintf (stderr, "Error opening the file.");
        return 1;
    }
    for (int i = 0; i < 12; i++)
    {
        fscanf(fptr, "%s", str1);
        printf ("str1 is : %s\n", str1);
    }
    
    fclose(fptr);
    printf ("------------------\n");
    return 0;
}