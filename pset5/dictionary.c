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

// Trie structure
// typedef struct node
// {
//     bool isWord;
//     struct node* children [27];
// } node;

// declaring varibales and structs
node* root;
int dSize;

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    // coping the word to be checked
    char* currWord = malloc(LENGTH + 1);
    int wordLen = strlen(word);
    strncpy(currWord, word, wordLen);
    currWord[wordLen] = '\0';
    
    // defined a builder pointer with initially pointing to root
    node* crawler = root;
    
    //getting to the correct location in trie, if error occurs, returns false
    for (int i = 0; i < wordLen; i++)
    {
        // making speller case-insensitive
        currWord[i] = tolower(currWord[i]);
        
        // defining and setting key to access children nodes.
        int key = currWord[i] - 'a';
        if (currWord[i] == '\'')
        {
            key = 26;
        }
        
        crawler = crawler -> children[key];
        
        if (crawler == NULL)
        {
            free(currWord);
            return false;
        }
        
    }
    
    // seeing if bool value for that word is true or not
    if (crawler -> isWord != true)
    {
        free(currWord);
        return false;
    }
    
    // freeing up allocated memory
    free(currWord);
    return true;
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
    
    //allocating size to store root
    root = malloc(sizeof(node));
    root -> isWord = false;
    
    // get each word and save it
    char dWord [LENGTH + 1];
    
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
    node* child = root;
    unloader(child);
    return true;
}

// loads a word given to it
void loader(char* dWord)
{
    // defined a builder pointer with initially pointing to root
    node* builder = root;
    
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
        
        // condition to malloc new storage if a perticular childern does not exist for a node
        if (builder -> children[key] == NULL)
        {
            builder -> children[key] = malloc(sizeof(node));
            builder = builder -> children[key];
            builder -> isWord = false;
        }
        
        // if the children exist, follow into the the node
        else
        {
            builder = builder -> children[key];
        }
        
        i++;
    }
    
    // end of word reached, thus setting bool isWord to true
    builder -> isWord = true;
}

// helper function to unload trie
void unloader(node* child)
{
    // loop over all the child in the array
    for (int i = 0; i < 27; i++)
    {
        if (child -> children[i] != NULL)
        {
            // pass in the new pointer to unloader
            unloader(child -> children[i]);
        }
    }
    
    // if pointer passed in the unloader funtion is not root dn free the pointer
    if (child != root)
    {
        free(child);
        return;
    }
    
    // free root
    free (root);
}
