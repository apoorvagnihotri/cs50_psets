#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main (void)
{
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
    
    BYTE* buffer = malloc(sizeof(BYTE) * 512);
    
    
    while (true)
    {
        fread(buffer, sizeof(buffer), 1, infile);

        if ((((buffer[0] == 0xff) && (buffer[1] == 0xd8)) && (buffer[2] == 0xff)) && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
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
            fwrite(buffer, sizeof(buffer), 1, outfile);
        }
        
        if (feof(infile))
        {
            fclose(outfile);
            fclose(infile);
            break;
        }
    }
    
    free(buffer);
    return 0;
}