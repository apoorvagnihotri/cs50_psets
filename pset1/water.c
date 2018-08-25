#include <cs50.h>
#include <stdio.h>

//to calculate number of equivalent bottles used to shower for 'x' minutes
int main (void)
{
    //getting minutes user shower
    printf ("minutes: ");
    int minutes = get_int();
    
    //calculating number of equivalent bottles, printing the result
    int bottles = 12*minutes;
    printf ("bottles: %i\n", bottles);
}