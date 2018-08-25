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
    //implementing binary search
    int start = 0;
    int end = n;
    int mid = n / 2;
    while ((end - start) > 0)
    {
        mid = ((start + end) / 2);
        if (values[mid] == value)
            return true;
        
        else if (values[mid] < value)
            start = mid + 1;
        
        else
            end = mid;
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
        // setting a flag to optimize the sorting a little bit
        bool flag = false;
        for (int k = 0; k < (n - (1 + i)); k++)
        {
            // looking for unsorted pair
            if (values[k] > values[k + 1])
            {
                // Swapping...
                int temp = values[k];
                values[k] = values[k + 1];
                values[k + 1] = temp;
                flag = true;
            }
        }
        if (!flag)
            break;
    }       
    return;
}