#include <stdio.h>
#include <inttypes.h>
#include "map.h"
#include <string.h>

char ConvertToString(uint8_t val[],char * user_str)
{
    uint8_t * ptr= &val[0];
    int n = 3; //n would be the number of terms in user_pin a fixed value
    for (int i = 0; i < n; i++)
    {
        user_str[i] = (char* ) *(ptr + (i * sizeof(val[0])));
    //This takes advantage of consecutive values of an array
    }
    printf("%s\n", user_str);
}

//Function passes in the user_name and user_id
int mp_data(char * user_name, char * user_str)
{
    //uint_map_t usr_data;
    map_str_t user_data;
    map_init(&user_data);
    
    char * user_pin = user_str;

    map_set(&user_data, user_name, user_pin);
    char ** sample = map_get(&user_data, user_name);
    printf("%s\n", *sample);

    map_deinit(&user_data);//I think we do not deinintialize in our case. Dunno fr fr
}

int main()//This would change from main to be used in program
{
   char user_name [] = "James";
   
   uint8_t user_pin [3] = {0x42, 0x21, 0x27};//The size of this array is the size of the pin and should be universal valued
   int n = 3;
   char user_str [n];
   user_str[n] = '\0';

   ConvertToString(user_pin, user_str);
  
   mp_data(&user_name, &user_str);//This would also take in shared pin values for second map
   return 0;
}