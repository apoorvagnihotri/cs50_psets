#include <stdio.h>
#include <stdint.h>
#include <cs50.h>

typedef uint8_t BYTE;

int main (void)
{
    char jpgout = "000.jpg";
    int counter = 0;
    
    //found is used to see if first jpg reached or not
    bool found = false;

    FILE* inptr = fopen("card.raw", "r");
    if(inptr == NULL) 
    {
        printf("Error in opening file");
        return(-1);
    }
    
    FILE* outptr = fopen(jpgout, "w");
    if(outptr == NULL) 
    {
        printf("Error in creating file");
        return(-1);
    }
    
    BYTE* buffer = malloc(sizeof(BYTE) * 512);
    while (true)
    {
        fread(buffer, sizeof(buffer), 1, inptr);

        if ((((buffer[0] == 0xff) && (buffer[1] == 0xd8)) && (buffer[2] == 0xff)) && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if (found)
            {
                fclose(outptr);
                counter++;
                sprintf(jpgout, "%3d.jpg", counter);
                outptr = fopen(jpgout, "w");
            }
            found = true;   
        }
        
        if (found)
        {
            fwrite(buffer, sizeof(buffer), 1, outptr);
        }
        
        if (feof(inptr))
        {
            fclose(outptr);
            fclose(inptr);
            break;
        }
    }
    
    free(buffer);
    return 0;
}