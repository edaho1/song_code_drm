#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

#define AES_BLOCK_SIZE 16

int fileRead(FILE * inFile);

int main(int argc, char **argv)
{
    FILE *  inFile = NULL;
    //FILE *outFile = NULL;
    uint8_t *filename;
    //uint8_t *outfilename,ch;
    filename = (uint8_t) malloc(sizeof(uint8_t) * 1024);
    //outfilename = (char*) malloc(sizeof(char) * 1024);
    //this next is for testing
    //int numAscii;

    if (filename == NULL) {
    printf("Error in malloc\n");
    exit(1);
    }
    // if (outfilename == NULL) {
    // printf("Error in malloc\n");
    // exit(1);
    // }

    // get file path
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
    
        strcpy(filename, cwd);

        // get filename from command line
        if (argc < 2) {
        printf("No wave file specified\n");
        return;
        }
        
        strcat(filename, "/");
        strcat(filename, argv[1]);
        printf("%s\n", filename);
    }

    // if (getcwd(cwd, sizeof(cwd)) != NULL) 
    // {

    //  strcpy(outfilename, cwd);

    // // get filename from command line
    //     if (argc < 2) 
    //     {
    //         printf("No wave file specified\n");
    //         return;
    //     }
    
    //     strcat(outfilename, "/");
    //     strcat(outfilename, argv[2]);
    //     printf("%s\n", outfilename);
    // }

    // open file
    printf("Opening  file..\n");
    inFile = fopen(filename, "rb");
    if (inFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    //int status;
    fileRead(inFile);

    fclose(inFile);
    // cleanup before quitting
    free(filename);
    //free(outfilename);
    return 0;
}


int fileRead(FILE * inFile)
{
    //performing file stream on audio file
    //FILE * inFile;
    
    uint8_t *   input = 0;
    int     i = 0;
    int     ret = 0;
    int     inputLength;
    int     length;
    int     padCounter = 0;

    fseek(inFile, 0, SEEK_END);
    inputLength = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    length = inputLength;
    /* pads the length until it evenly matches a block / increases pad number*/
    while (length % AES_BLOCK_SIZE != 0) {
        length++;
        padCounter++;
    }


    /* reads from inFile and writes whatever is there to the input array */
    ret = fread(input, 1, inputLength, inFile);

    if (ret == 0) {
        printf("Input file does not exist.\n");
        return -1010;
    }
    for (i = inputLength; i < length; i++) {
        /* pads the added characters with the number of pads */
        input[i] = padCounter;
        printf("%c", input[i]);
    }

    

    /* closes the opened files and frees the memory*/
    memset(input, 0, length);
    free(input);
    //fclose(inFile);
    return ret;
};