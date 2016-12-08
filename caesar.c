#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (int argc, string argv[])
{
    // checking number of arguments passed by the user. 
    if (argc != 2)
    {
        printf ("Please comply by giving one int key!\n");
        return 1;
    }

    /*extracting the key from the input of the 
     *user & and calculating the effective key by 
     *finding the remainder upon dicvision by 26.
    */
    int key = atoi (argv[1]);
    key = key % 26;
    
    //getting plaintext
    string s = get_string();
    
    //initiating a for-loop to scan over the i'th character of the string inputed by the user.
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        //if else_if else funtion to differentiate and run individual conversion codes. 
        if ((s[i]>='A') && (s[i]<='Z'))
        {
            //printing the converted character (A-Z)
            int j = s[i]-65;
            j = j + key;
            j = j % 26;
            printf ("%c", j + 65);
        }
        else if ((s[i]>='a') && (s[i]<='z'))
        {
            //printing the converted character (a-z)
            int k = s[i] - 97;
            k = k + key;
            k = k % 26;
            printf ("%c", k + 97);
        }
        else
            //printing the non alphabetical character
            printf ("%c", s[i]);
    }
    printf ("\n");
}
