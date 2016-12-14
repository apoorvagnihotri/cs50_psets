#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main (void)
{
    BYTE* inptr = malloc(sizeof(BYTE) * 512);
    char* filename = "000.jpg";
    int counter = 0;
    bool found = false;
    FILE* infile = fopen("card.raw", "r");
    if(infile == NULL) 
    {
        printf("Error in opening file");
        return(-1);
    }
    
    FILE* outfile = fopen(filename, "w");
    if(outfile == NULL) 
    {
        printf("Error in creating file");
        return(-1);
    }
    
    
    while (true)
    {
        fread(inptr, sizeof(inptr), 1, infile);
        if (((inptr[0] == 0xff) && (inptr[1] == 0xd8)) && (inptr[2] == 0xff))
        {            
            if (found)
            {
                fclose(outfile);
                counter++;
                sprintf(filename, "%3d.jpg", counter);
                fopen(filename, "w");   
            }
            found = true;   
        }
        if (found)
        {
            fwrite(inptr, sizeof(inptr), 1, outfile);
        }
        if (feof(infile))
        {
            fclose(outfile);
            fclose(infile);
            break;
        }
    }
}