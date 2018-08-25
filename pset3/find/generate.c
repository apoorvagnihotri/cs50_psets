/**
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Checking if number of arguments provided by the user is neither 2 nor 3, but something else.
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // conversion of the 2nd argument to an int from a string.
    int n = atoi(argv[1]);

    /** if number of arguments is exactly 3, srand48 is called with the second argument as srand48's argument.
     * if the number of arguments is exactly 2, srand48 is called with time() as it's agument
     * in both cases srand48 is called upon with some argument to be used to seed drand48()
     */
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    /** Looping over the number of required random numbers we need to find.
     * Printing ints that actually have been formed from type casting floats, produced by drand48().
     */
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", (int)(drand48() * LIMIT));
    }

    // success
    return 0;
}