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

// declaring varibales and structs
node* root;
int dSize;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char* currWord = malloc(sizeof(word));
    strncpy(currWord, word);
    for (int i = 0, n = strlen(currWord); i < n; i++)
    {
        *(currWord + i) = tolower(*(currWord + i));
        
    }
    
    
    
    free(currWord);
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
    
    root = malloc(sizeof(node));
    
    // get each word and save it
    char dWord [45];
    
    // set dictionary current size to 0
    dSize = 0;
    
    // untill EOF reached perform loading
    while (fscanf(dfp,"%s\n", dWord) != EOF)
    {
        loader(dWord);
        dSize++;
    }
    fclose(dfp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dSize;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    // TODO
    return false;
}

// loads a word given to it
void loader(char* dWord)
{
    // defined a crawler with initially pointing to root
    node* crawler = root;
    
    // used to access diff chars of the word
    int i = 0;
    
    // loop till end of string is reached
    while (dWord[i] != '\0')
    {
        // defining and setting key to access children nodes.
        int key = dWord[i] - 'a';
        if (dWord[i] == '\'')
        {
            key = 26;
        }
        
        // condition to malloc new storage if not a perticular childern exists for a node
        if (crawler -> children[key] == NULL)
        {
            crawler -> children[key] = malloc(sizeof(node));
            crawler = crawler -> children[key];
        }
        else
        {
            crawler = crawler -> children[key];
        }
        
        i++;
    }
    
    // end of word reached, thus setting bool isWord to true.
    crawler -> isWord = true;
}
