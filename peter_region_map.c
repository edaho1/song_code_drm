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
    //map_set(&region_data, song_name, song_region);
    printf("%s\n", song_region);
    
    char ** sample = map_get(&region_data, song_name);
    printf("map store val: %s\n", *sample);

    //regions should be incorporated
   //struct map_t * s_ptr = malloc(sizeof(map_t));
    //s_ptr = region_data;
    FILE * file;
    file = fopen("song_regions", "w");
    if (file != NULL)
    {
        fwrite(&region_data, sizeof(map_str_t), 1, file);
    }
    read_file();
    fclose (file);
   // free(s_ptr);
    return;
}
int read_file()
{
    FILE * file;
    map_str_t file_data;
    map_init(&file_data);

    file = fopen("song_regions", "r");
    if (file != NULL)
    {
    fread(&file_data, sizeof(map_str_t), 1, file);

    int * sample = map_get(&file_data, "Billy_Jean");
    printf("This is what is in file: %ls\n", sample); 
    }
    else
    {
    printf("Why me");}
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

    char song_name [] = "Billy_Jean";
    region_map(song_name, song_region);
    return 0;
}