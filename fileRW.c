#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

int main()
{
    //performing file stream on audio file
    FILE * file;
    /*long fsize;
    char buff[32];
    char* file_content = (char*)malloc(fsize);
    */
    file = fopen("./test.bin","rb");
    /*size_t fsize = fread(buff, sizeof(char),32, file);
    if (file != NULL)
    {
        if (fsize > 0)
        {
            for (int i = 0; i < sizeof(buff) - 1; i++)
            {
                printf("%c",buff[i]);
            }
            printf("\n");
        }
    }*/
    

    fclose(file);

}