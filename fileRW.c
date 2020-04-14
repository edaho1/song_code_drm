// use this to run file: gcc song.c fileRW.c aes_encrypt.c aes_decrypt.c utils.c -o song_enc
// then run: ./song_enc <filename>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "song.h"

#define AES_BLOCK_SIZE 16
#define KEYS 16

unsigned char buffer4[4];
unsigned char buffer2[2];
unsigned char buffer16[16];
unsigned char buffer64[16000]; // first option using buffer
// unsigned char buffer[16][1000];
// unsigned char encode[16][1000];

unsigned char * readbuff;
unsigned char decode[KEYS];


// second option is using a structure to store the encoding/decoding



int fileRead(FILE * inFile);

FILE * inFile;
char * filename;
int     i = 0;
int     ret = 0;
int     inputLength;


 struct HEADER header;
int main(int argc, char **argv)
{
    filename = (char*) malloc(sizeof(char) * 1024);
    readbuff = (char*) malloc(sizeof(char)* 16000);
    if (filename == NULL) {
    printf("Error in malloc\n");
    exit(1);
    }
    // pass in chunk size encrypt
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

    // open file
    printf("Opening  file..\n");
    inFile = fopen(filename, "rb");
    if (inFile == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    fseek(inFile, 0, SEEK_END);
    inputLength = ftell(inFile);
    fseek(inFile, 0, SEEK_SET);

    printf("input length: %d\n", inputLength);

    const uint8_t master_key[KEYS] = {
        0x65,0x37,0x36,0x30,0x03,0x53,0x13,0x40,
        0x12,0x43,0x23,0x06,0x54,0xc6,0xff,0x9f
    };
<<<<<<< HEAD
=======
    /* reads from inFile and writes whatever is there to the input array */
    ret = fread(header.riff, sizeof(header.riff), 1, inFile);
    printf("(1-4): %s \n", header.riff); 
    
    ret = fread(buffer4, sizeof(buffer4), 1, inFile);
    printf("%u %u %u %u\n", buffer4[0], buffer4[1], buffer4[2], buffer4[3]);
 // convert little endian to big endian 4 byte int
    header.overall_size  = buffer4[0] | 
                            (buffer4[1]<<8) | 
                            (buffer4[2]<<16) | 
                            (buffer4[3]<<24);

    printf("(5-8) Overall size: bytes:%u, Kb:%u \n", header.overall_size,\
             header.overall_size/1024);

    ret = fread(header.wave, sizeof(header.wave), 1, inFile);
    printf("(9-12) Wave marker: %s\n", header.wave);

    ret = fread(header.fmt_chunk_marker, sizeof(header.fmt_chunk_marker), 1, inFile);
    printf("(13-16) Fmt marker: %s\n", header.fmt_chunk_marker);
    // create a cache that handle user request to play song
    // fill up buffer than read when request
    buffer16[0] = header.riff[0]; //byte 1
    buffer16[1] = header.riff[1]; //byte 2
    buffer16[2] = header.riff[2]; //bute 3
    buffer16[3] = header.riff[3]; //byte 4
    buffer16[4] = buffer4[0]; //byte 5
    buffer16[5] = buffer4[1]; //byte 6
    buffer16[6] = buffer4[2]; //byte 7
    buffer16[7] = buffer4[3]; //byte 8
    buffer16[8] = header.wave[0]; //byte 9
    buffer16[9] = header.wave[1]; //byte 10
    buffer16[10] = header.wave[2]; //byte 11
    buffer16[11] = header.wave[3]; //byte 12
    buffer16[12] = header.fmt_chunk_marker[0]; //byte 13
    buffer16[13] = header.fmt_chunk_marker[1]; //byte 14
    buffer16[14] = header.fmt_chunk_marker[2]; //byte 15
    buffer16[15] = header.fmt_chunk_marker[3]; //byte16

    printf("first 16 bytes: ");
    for(i = 0; i<16; i++)
    {
        printf("%c", buffer16[i]);
    }
    printf("\n");
>>>>>>> 6f6d8511fbc611acea0e53e1753226fbaa0a38a6

    ret = fread(buffer64, sizeof(buffer64), 1, inFile);
    // printf("(1-64): ");
    // for (int i = 0; i < 16000; i++){
        // printf("%s", buffer64[i]);
    // }
    // printf("\n");

    // Doesn't work
    unsigned char tmp [16][1000];
    int k = 0;
    for (int i = 0; i < 16000;i++){
        for (int j = 0; j <16; i++){

            tmp[i][j] = buffer16[k];
            printf("%c",tmp[i][j]);
            k++;
                
            
        }
    }
    // tmp[4][4] = '\0';
    // printf("%d",k);
    // //testing
    // printf("tmp test: ");
    // for (int i = 0; i < 4; i++){
    //     for (int j = 0; j < 4; j++){
    //         printf("%c",tmp[i][j]);
    //     }
    // }
    // printf("\n");



    //encrypt_song (master_key, buffer64, encode);

//     /* reads from inFile and writes whatever is there to the input array */
//     ret = fread(header.riff, sizeof(header.riff), 1, inFile);
//     printf("(1-4): %s \n", header.riff); 
    
//     ret = fread(buffer4, sizeof(buffer4), 1, inFile);
//     printf("%u %u %u %u\n", buffer4[0], buffer4[1], buffer4[2], buffer4[3]);
//  // convert little endian to big endian 4 byte int
//     header.overall_size  = buffer4[0] | 
//                             (buffer4[1]<<8) | 
//                             (buffer4[2]<<16) | 
//                             (buffer4[3]<<24);

//     printf("(5-8) Overall size: bytes:%u, Kb:%u \n", header.overall_size,\
//              header.overall_size/1024);

//     ret = fread(header.wave, sizeof(header.wave), 1, inFile);
//     printf("(9-12) Wave marker: %s\n", header.wave);

//     ret = fread(header.fmt_chunk_marker, sizeof(header.fmt_chunk_marker), 1, inFile);
//     printf("(13-16) Fmt marker: %s\n", header.fmt_chunk_marker);

//     buffer16[0] = header.riff[0]; //byte 1
//     buffer16[1] = header.riff[1]; //byte 2
//     buffer16[2] = header.riff[2]; //bute 3
//     buffer16[3] = header.riff[3]; //byte 4
//     buffer16[4] = buffer4[0]; //byte 5
//     buffer16[5] = buffer4[1]; //byte 6
//     buffer16[6] = buffer4[2]; //byte 7
//     buffer16[7] = buffer4[3]; //byte 8
//     buffer16[8] = header.wave[0]; //byte 9
//     buffer16[9] = header.wave[1]; //byte 10
//     buffer16[10] = header.wave[2]; //byte 11
//     buffer16[11] = header.wave[3]; //byte 12
//     buffer16[12] = header.fmt_chunk_marker[0]; //byte 13
//     buffer16[13] = header.fmt_chunk_marker[1]; //byte 14
//     buffer16[14] = header.fmt_chunk_marker[2]; //byte 15
//     buffer16[15] = header.fmt_chunk_marker[3]; //byte16

//     printf("first 16 bytes: ");
//     for(i = 0; i<16; i++)
//     {
//         printf("%c", buffer16[i]);
//     }
//     printf("\n");

//     encrypt_song (master_key, buffer16, encode);
//     printf("enc_song: ");
//     for (i = 0; i < 16; i++){
//         printf("%c",encode[i]);
//     }
//     printf("\n");

//     decrypt_song(master_key, decode, encode);
//     printf("Decrypted: ");
//     for( i = 0;i < 16;i++)
//     {
//         printf("%c",decode[i]);
//     }
//     printf("\n");

//     ret = fread(buffer4, sizeof(buffer4), 1, inFile);
//     printf("%u %u %u %u\n", buffer4[0], buffer4[1], buffer4[2], buffer4[3]);

    
    
    free(filename);
    fclose(inFile);
    return 0;
}
