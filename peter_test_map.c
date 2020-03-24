#include <stdio.h>
#include <inttypes.h>
#include "map.h"

char ConvertToString(uint8_t key[],char usr_pin_str[])
{
    uint8_t * ptr= &key[0];
    int n = 3; //n would be the number of terms in user_pin a fixed value

    for (int i = 0; i < n; i++)
    {
        usr_pin_str[i] = (char* ) *(ptr + (i * sizeof(key[0])));
    //This takes advantage of consecutive values of an array
    }

    printf("\n");
    printf("%s\n", usr_pin_str);
    //return usr_pin_str;
}


//Function passes in the user_name and user_id
int mp_data(char * user_name, char * user_str)
{
    //Create a map with name as string and value as uint8_t pointer
    //typedef map_t(uint8_t *) uint_map_t;
    //uint_map_t usr_data;

  //  char * test = user_str;
  //  printf("%s\n", user_str);

    map_str_t usr_data;
    map_init(&usr_data);

//    uint8_t * ptr = key;


    //put name and value in map
    map_set(&usr_data, user_name, user_str);
 
    //test to see what is in the map
 //  uint8_t * val = map_get(&usr_data, user_name);

<<<<<<< HEAD
    char * val = map_get(&usr_data, user_name);
    while (*val !='\0')
    {
    printf ("%c", *val++);
    }
    printf("\n");
   // char * val[] = 
/*
=======
    /*
     * This guy only prints out the first value 
    */
>>>>>>> 9049fb19be1dd281190f5652212a745961dc5a7a
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
    printf("\n");*/
    //test ended
    // We shall also include name and values of the shared pin
    //map_deinit(&shared_data);
    map_deinit(&usr_data);//I think we do not deinintialize in our case. Dunno fr fr
}

int main()//This would change from main to be used in program
{
   char user_name [] = "James";
   uint8_t user_pin [] = {0x23, 0x25, 0x27};//The size of this array is the size of the pin and should be universal valued
   int n = 3;
   char user_str [3];
   user_str[n] = '\0';
   ConvertToString(user_pin, user_str);

   mp_data(&user_name, &user_str);//This would also take in shared pin values for second map
   return 0;
}