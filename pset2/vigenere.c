#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void numb_key (string key);

int main (int argc, string argv[])
{
    // checking number of arguments passed by the user. 
    if (argc != 2)
    {
        printf ("Please comply by giving one argument\n");
        return 1;
    }
    
    // declaring variables
    string key = argv[1];
    int key_len = strlen(key);
    int num[key_len];
    int loop = 0;
    
    //converting the alphabetic key to an array of int to be used in future & also checking if non alphabetic key was entered
    for (int i = 0; i < key_len; i++)
        {
            if ((key[i] >= 'A') && (key[i] <= 'Z'))
                num[i] = (int)(key[i]) - 65;
        
            else if ((key[i] >= 'a') && (key[i] <= 'z'))
                num[i] = (int)(key[i]) - 97;
            
            else
            {
                printf ("Enter alphabetical key\n");
                return 1;
            }
        }

    //getting plaintext
    string p = get_string();

    //initiating a for-loop to scan over the i'th character of the string inputed by the user.
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        //if else_if else funtion to differentiate and run individual conversion codes. 
        if ((p[i] >= 'A') && (p[i] <= 'Z'))
        {
            //printing the converted character (A-Z)
            int j = p[i] - 65;
            j = j + num[loop];
            j = j % 26;
            printf ("%c", j + 65);
            loop++;
            loop = loop % key_len;
            
        }
        else if ((p[i] >= 'a') && (p[i] <= 'z'))
        {
            //printing the converted character (a-z)
            int j = p[i] - 97;
            j = j + num[loop];
            j = j % 26;
            printf ("%c", j + 97);
            loop++;
            loop = loop % key_len;
        }
        else
            //printing the non alphabetical character
            printf ("%c", p[i]);
    }
    printf ("\n");
}