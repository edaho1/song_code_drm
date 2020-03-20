#include <stdio.h>
#include <inttypes.h>
#include "map.h"

/*
char ConvertToString(uint8_t key[],char usr_pin_str[])
{
    uint8_t * ptr= key;
    int n = 3; //n would be the number of terms in user_pin a fixed value
    
    printf("%s", usr_pin_str);
    for (int i = 0; i < n; i++)
    {
        usr_pin_str[i] = (char* ) (ptr[i]);
    }
    printf("\n");
    printf("%s\n", usr_pin_str);
    //return usr_pin_str;
}

int ConvertToUint8() //after the characterstring is stored when required to print, we convert back to uint8_t
{

}
*/
int mp_data(char * user_name, uint8_t key[])
{
    typedef map_t(uint8_t *) uint_map_t;
    uint_map_t usr_data;
    map_init(&usr_data);

    uint8_t * ptr = key;
    printf("%ld\n",sizeof(ptr));
    for (int i=0; i<3; i++)
    {
    printf("%x\n", ptr[i]);
    }

    map_set(&usr_data, user_name, ptr);
 
    uint8_t val = map_get(&usr_data, user_name);

    for (int i=0; i<3; i++)
    {
        printf("%x", val);
    }
    printf("\n");
/*  }
    if (val) {
    printf("value: %s\n", &*val);
    } else {
    printf("value not found\n");
    }
    
*/
    //map_deinit(&shared_data);
    map_deinit(&usr_data);
}

int main()
{
   char user_name [] = "James";
   uint8_t user_pin [] = {0x23, 0x25, 0x27};
/*
   for (int i=0; i<3; i++)
   {
   printf("%x", user_pin[i]);
   }
   */
   mp_data(&user_name, user_pin);
   return 0;
}