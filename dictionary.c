/**
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "dictionary.h"

typedef struct node
{
    struct node *letters_array[27];
    bool exist;
}
node;

node *first = NULL;
int words_count = 0;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    // TODO
    int letter_index = 0;
    char current_letter = word[letter_index];
    node *tptr = first;
    while (current_letter != '\0')
    {
        if ((current_letter >= 'A') && (current_letter <= 'Z'))
        {
            current_letter += 32;
        }
        if (current_letter == '\'')
        {
            current_letter = 123;
        }
        int corresponding_index = current_letter - 97;
        if (tptr -> letters_array[corresponding_index] == NULL)
        {
            return false;
        }
        tptr = tptr -> letters_array[corresponding_index];
        letter_index ++;
        current_letter = word[letter_index];
    }
    if (tptr -> exist == true)
    {
        return true;
    }
    return false;
}

/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    // TODO
    FILE *fptr = fopen(dictionary, "r");
    if (fptr == NULL)
    {
        fprintf (stderr, "Error opening the file.");
        return false;
    }
    unsigned int each_character_int = fgetc(fptr);
    first = (node*)malloc(sizeof(node));
    if (first == NULL)
    {
        fprintf (stderr, "Error memory allocation.");
        return 1;
    }
    memset(first, 0, sizeof(node));
    
    node *next_Node = first;
    for (char c = each_character_int; c != EOF; c = fgetc(fptr))
    {
        if ((c >= 'a' && c <= 'z') || (c == '\''))
        {
            if (c == '\'')
            {
                c = 123;
            }
            int where_in_array = c - 97;
            if (next_Node -> letters_array[where_in_array] == NULL)
            {
                next_Node -> letters_array[where_in_array] = (node *)malloc(sizeof(node));
                memset(next_Node -> letters_array[where_in_array], 0, sizeof(node));
                if (next_Node -> letters_array[where_in_array] == NULL)
                {
                    fprintf (stderr, "Error allocating the memory.");
                    return false;
                }
            }
            next_Node = next_Node -> letters_array[where_in_array];
        }
        if (c == '\n')
        {
            next_Node -> exist = true;
            words_count ++;
            next_Node = first;
        }
    }
    fclose(fptr);
    return true;
    
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return words_count;
}

void clear(node *ptr)
{
    for (int i = 0; i < 27; i ++)
    {
        if (ptr -> letters_array[i] != NULL)
        {
            clear(ptr -> letters_array[i]);
        }
    }
    free (ptr);
}
/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    clear(first);
    return true;
}
