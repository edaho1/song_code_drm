#include <stdio.h>
#include <inttypes.h>
#include "map.h"


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

int mp_data(char * user_name, uint8_t user_pin[])
{
    typedef map_t(unsigned char *) uint_map_t;
    map_str_t usr_data;
    map_init(&usr_data);
    printf("I am here\n");
 //   printf("%s\t",user_name);
    for(int i=0;i<3;i++)
    {
    printf("%x", user_pin [i]);
    }

    printf("\n");
    map_set(&usr_data, user_name, user_pin);

    

    // uint_map_t shared_data;
    // map_init(&shared_data);

    // map_set(&shared_data, user_name, 0x25);
   
    uint8_t *val = map_get(&usr_data, user_name);

    if (val) {
    printf("value: %x\n", *val);
    } else {
    printf("value not found\n");
    }

    //map_deinit(&shared_data);
    map_deinit(&usr_data);
}



int main()
{
   char user_name [] = "James";
   const uint8_t user_pin [3] = {0x23, 0x46, 0x25};
   char user_str [3];
   user_str[3] = '\0';
  // int n = 3; 

   for (int i=0;i<3;i++)
   {
   printf("%x",user_pin[i]);
   }
   printf("\n");
 /*  
    ConvertToString(user_pin, user_str);
    printf("size of str: %d\n",strlen(user_str));
    printf("%s\n", user_str);
*/
    printf("Done\r\n");
   mp_data(&user_name, user_pin);
   return 0;
}