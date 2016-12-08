#include <cs50.h>
#include <stdio.h>
#include <math.h>

int num (int sum, int denomination);
int rem (int sum, int denomination);

//program to calculate how many coins required to return the due.
int main (void)
{
    float due;
    
    //do_while loop to get a non-negative float.
    do
    {
        printf ("O hai! How much change is owed?\n");
        due = get_float();
    }
    while (due < 0);
    
    //converting due amount into int cents.
    due = due * 100;
    int due2 = round (due);

    //finding the number of coins required using custom made functions and printing it.
    int total = num(due2,25) + num(rem(due2,25),10) + num(rem(rem(due2,25),10),5) + num(rem(rem(rem(due2,25),10),5),1);
    printf("%i\n",total);
}

//function to calculate number of coins required. taking two parameters as due amount and denomination of coin.
int num(int due, int denomination)
{
    return (int) (due / denomination);
}

/*function to calculate remaining amount after coins of the bigger denomination is given. 
*taking two parameters (due amount, denomination of the bigger coin)*/
int rem(int due, int denomination)
{
    return due % denomination;
}