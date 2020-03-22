#include <stdio.h>
#include <inttypes.h>
#include "map.h"
//Function passes in the user_name and user_id
int mp_data(char * user_name, uint8_t key[])
{
    //Create a map with name as string and value as uint8_t pointer
    typedef map_t(uint8_t *) uint_map_t;
    uint_map_t usr_data;
    map_init(&usr_data);

    //test to see that the pointer is pointing where it should be
    uint8_t * ptr = key;
    printf("%ld\n",sizeof(ptr));
    for (int i=0; i<3; i++)
    {
    printf("%x\n", ptr[i]);
    }
    //test end

    //put name and value in map
    map_set(&usr_data, user_name, * ptr);
 
    //test to see what is in the map
    uint8_t * val = map_get(&usr_data, user_name);

    /*
     * This guy only prints out the first value 
    */
    printf("%x\n",  * val);

    //Only the pointer is saved. But because arrays in C are set to consecutive memory locations i access as below
    //check if array can be accessed
    uint8_t arr[3];
    arr[0] = * val;
    for (int i=0; i<3; i++)
    {
        /* I don't think this one is reading from the memory location.
         * take a look at the output and the memory location itself
         * its not printing what you expect to be printed */ 
        arr[i] = *val + i * sizeof(uint8_t);
        printf("%x",  arr[i]);
    }
    printf("\n");
    //test ended
    // We shall also include name and values of the shared pin
    //map_deinit(&shared_data);
    map_deinit(&usr_data);//I think we do not deinintialize in our case. Dunno fr fr
}

int main()//This would change from main to be used in program
{
   char user_name [] = "James";
   uint8_t user_pin [] = {0x23, 0x25, 0x27};//The size of this array is the size of the pin and should be universal valued

   mp_data(&user_name, user_pin);//This would also take in shared pin values for second map
   return 0;
}