#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main (void)
{
    BYTE* inptr = malloc(sizeof(BYTE) * 512);
    char* filename[4];
    int counter = 0;
    bool found = false;
    FILE* infile = fopen("card.raw", "r");
    if(infile == NULL) 
    {
        printf("Error in opening file");
        return(-1);
    }
    
    FILE* outfile = fopen(000.jpg, "w");
    if(outfile == NULL) 
    {
        printf("Error in creating file");
        return(-1);
    }
    
    
    while (true)
    {
        fread(inptr, sizeof(inptr), 1, infile);
        if (((inptr[0] == ) && (inptr[1] == )) && (inptr[2] == ))
        {            
            if (found)
            {
                fclose(outfile)
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
        if (feof)
        {
            fclose(outfile);
            fclose(infile);
            break;
        }
    }
}