/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

//Trie structure
typedef struct node
{
    bool isWord;
    struct node* children [27];
} node;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char* spell = malloc(sizeof(word));
    for (int i = 0, n = strlen(spell); i < n; i++)
    {
        *(spell + i) = tolower(*(spell + i));
    }
    
    
    
    free(spell);
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    
    // open dictionary file for reading.
    FILE* dfp = fopen(dictionary, "r");
    
    // check if it opened
    if (dfp == NULL)
    {
        return false;
    }
    
    while(true)
    {
        // get each word and save it
        char dWord [45];
        
        // untill EOF reached perform loading
        while (fscanf(dfp,"%s\n", dWord) != EOF)
        {
            
            return true;
        }
    }
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    // TODO
    return 0;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}
