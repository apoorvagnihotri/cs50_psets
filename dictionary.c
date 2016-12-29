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
    
    while (true)
    {
        // get each char and save it
        char c = fgetc(dfp);
        
        // check if end of file reached
        if (feof(dfp))
        {
            return true;
        }
        
        // 
        c = tolower(c);
        loader(c, &node);
        
    }
    return false;
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

void loader(char c, *node)
{
    
}