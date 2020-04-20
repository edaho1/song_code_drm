#include <stdio.h>
#include <inttypes.h>
#include "map.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "aes.h"
#include "utils.h"
/*#include <stdint.h>
#include <stddef.h>*/


uint8_t region_key[16] = {
0x65,0x37,0x36,0x30,0x03,0x53,0x13,0x40,
0x12,0x43,0x23,0x06,0x54,0xc6,0xff,0x9f};



int region_map(char * song_name, char * song_region)
{

    map_str_t region_data;
    map_init(&region_data);
    map_set(&region_data, song_name, song_region);

    //printf("%s\n", song_region);
    
    char ** sample = map_get(&region_data, song_name);
    printf("map store val: %s\n", *sample);


    size_t write;

    FILE * file;
    file = fopen("region_data.bin", "wb");
    
    write = fwrite(song_region, sizeof(char)*16,1, file);
    
    fclose(file);
     
    read_file();

}
int read_file()
{
    FILE * file;
    unsigned char data[16];
    size_t read = 0;
    size_t write;

    file = fopen("region_data.txt", "rb");
    if (file != NULL)
    {
        read = fread(data, sizeof(char)*16, 1, file);
        printf("%s\r\n", data);
        printf("read data: ");
        for (int i = 0;i < 16; i++){
            printf("%c", data[i]);
        }
        printf("\r\n");

        fclose(file);
    }

}
int main()
{
    char song_region[16];
    char song_region_name[] = "Japan";
    struct tc_aes_key_sched_struct s;
    tc_aes128_set_encrypt_key(&s, region_key);
    tc_aes_encrypt(song_region, song_region_name, &s);
    song_region[16] ='\0';
    printf("%s\r\n", song_region);

    //hash the regions
    char song_name [] = "Billy_Jean";
    region_map(song_name, song_region);
    return 0;
}