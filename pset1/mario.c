#include <cs50.h>
#include <stdio.h>

//program to make mario's half pyramid
int main (void)
{
    int height;
    
    //do_while loop to get an int between 0 and 23, (including 0 and 23).
    do
    {
        printf ("height: ");
        height = get_int();
    }
    while (height < 0 || height > 23);
    
    //nested for_loops for making the pyramid.
    for (int i = 0 ; i < height ; i++)
    {
        //for loop for making the required blank spaces.
        for (int blank = height - i; blank > 1; blank--)
            printf (" ");
            
        //for loop for making the required numbe of hashes.    
        for (int hash = 0; hash < i+2; hash++)
            printf ("#");

        //going to a new line, after blank spaces and hashes had been printed.
        printf ("\n");
    }
}