/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if (value < 0)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value)
            return true;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // Using bubble sort to implemnt sorting
    for (int i = 0; n - 1; i++)
    {
        bool key = false;
        for (int k = 0; k < (n - (1 + i)); k++)
        {
            if (values[k] > values[k + 1])
            {
                // Swapping...
                
                int temp = values[k];
                values[k] = values[k + 1];
                values[k + 1] = temp;
                key = true;
            }
        }
        if (!key)
            break;
    }       
    return;
}