#include <stdlib.h>
#include <stdio.h>

int main()
{
    typedef struct {
        char song_name[20];
        //include metadata information in struct
        char user_name [20];
        char artiste [20];
        int user_pin[64];
    } user_song;
    int num_of_songs = 2; //variable
    user_song songs_arr;

    songs_arr.song_name = 'Billy_Jean';

    printf('%s', songs_arr.song_name);
    return 0;
}