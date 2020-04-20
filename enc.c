#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "aes.h"
//#include "ecdh.h"
#include "utils.h"
//#include "constantsA.h"
#include "song.h"

#define KEYS 16


unsigned char buffer16[16] = {0};

int main(int argc, char **argv)
{
    FILE * inFile, *inFile2;
    FILE * outFile;
    int inputLength;
    char * filename,*filename2, *filename3;

    static uint8_t master_key[KEYS] = {
        0x65,0x37,0x36,0x30,0x03,0x53,0x13,0x40,
        0x12,0x43,0x23,0x06,0x54,0xc6,0xff,0x9f
    };

    filename = (char*) malloc(sizeof(char) * 1024);
    filename2 = (char*) malloc(sizeof(char) * 1024);
    filename3 = (char*) malloc(sizeof(char) * 1024);

    if (filename == NULL) {
    printf("Error in malloc\r\n");
    exit(1);
    }

    if (filename2 == NULL){
        printf("Error in malloc\r\n");
        exit(1);
    }
    if (filename3 == NULL){
        printf("Error in malloc\r\n");
        exit(1);
    }

    // get file path
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
    
        strcpy(filename, cwd);
        strcpy(filename2,cwd);
        strcpy(filename3,cwd);

        // get filename from command line
        if (argc < 2) {
        printf("No wave file specified\r\n");
        return;
        }
        if (argc < 3){
            printf("no output file specified\r\n");
            return;
        }
        if (argc < 4){
            printf("no output file specified\r\n");
            return;
        }

        strcat(filename, "/");
        strcat(filename2,"/");
        strcat(filename3,"/");
        strcat(filename, argv[1]);
        strcat(filename2,argv[2]);
        strcat(filename3,argv[3]);
        printf("%s\r\n", filename);
        printf("%s\r\n", filename2);
        printf("%s\r\n", filename3);
    }

    // open file
    //printf("Opening  file..\n");
    inFile = fopen(filename, "rb");
    if (inFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(inFile, 0, SEEK_END);
    inputLength = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    outFile = fopen(filename2,"wb");
     if (outFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    inFile2 = fopen(filename3, "rb");
    if (inFile2 == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    //printf("input length: %d\n", inputLength);
    

    /*
     * encrypt song and store in buffer
     * can read it 16 byte at a time and encrypt it
     * then store it in buffer that dynamically increases
     * 
     */ 


    unsigned char encode [7463454]; //[7463438]; This is the value before Peter touched it
    unsigned char tmp[16];
    size_t read = 0;
    size_t write; 
    int k=0,i = 0;
    char * p = encode;

    while ((read = fread(&buffer16,sizeof(char)*16,1,inFile))> 0)
    {
        if( read != 7463438/16){
            for (k = 0; k < 16; k++){
                tmp[k] = buffer16[k];
            }
            encrypt_song(master_key,tmp, p);
            p+=16;
        }
    }
    //This is Peter adding 16bytes for region
    //encode + 16 = 7463454
    // FILE * fptr;
    // fptr = fopen("region_data.txt","rb");
    unsigned char reg_buffer[16];
    // read = fread (&reg_buffer, sizeof(char)*16, 1, fptr);
    // enc_and_region = strcat(reg_buffer, encode);
    read = fread(&reg_buffer,sizeof(char)*16,1,inFile2);
    unsigned char storage[7463438+16];
    strcpy(storage,reg_buffer);
    strcat(storage, encode);

    //7463454
    // writing output to file
    write = fwrite(storage, sizeof(char)*7463454,1, outFile);
    //write = fwrite(encode, sizeof(char)*7463438,1, outFile);

    free(filename);
    free(filename2);
    fclose(inFile);
    fclose(outFile);
    return 0;
}