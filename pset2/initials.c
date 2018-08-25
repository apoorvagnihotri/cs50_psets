#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    string s = get_string();
    
    // printing the first character of the name in capatials.
    printf ("%c", toupper(s[0]));
    
    // to check whether s contains a string or not
    if (s != NULL)
    {    
        // for loop in to check each i'th character for a 'space'.
        for (int i = 0, n = strlen (s); i < n; i++)
        {
            if (s[i] == ' ')
            {
                // if space found, capatalizing the next character.
                s[i + 1]=toupper(s[i + 1]);
                printf ("%c", s[i + 1]);   
            }
        }
        printf ("\n");
        return 0;
    }
    else
    return 1;
}