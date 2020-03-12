#include <stdio.h>
#include <inttypes.h>
#include "map.h"


int mp_data(char * user_name, uint8_t * user_pin)
{
    typedef map_t(unsigned char *) uint_map_t;
    uint_map_t usr_data;
    map_init(&usr_data);

    printf("%c",(*user_name));
    printf("%x\n",*user_pin);
    /*
    map_set(&usr_data, *user_name, *user_pin);
    printf("pass\n");
    /*
    uint_map_t shared_data[2];
    map_init(&shared_data);

    map_set(&shared_data, "user_id", 0x25);
    
    uint8_t *val = map_get(&usr_data, user_name);

    if (val) {
    printf("value: %x\n", *val);
    } else {
    printf("value not found\n");

    }
    */
    //map_deinit(&shared_data);
    map_deinit(&usr_data);
}



int main()
{
   char user_name [] = "solomon";
   uint8_t user_pin = 0x23; 
   mp_data(user_name, user_pin);

   return 0;
}