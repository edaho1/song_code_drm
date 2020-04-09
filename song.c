#include <stdio.h>
/*#include "aes.h"
#include "ecdh.h"
#include "utils.h"
#include "constantsA.h"*/
#include "song.h"
//#include "map.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>


int encrypt_song (uint8_t* key, uint8_t* raw_song, uint8_t* enc_song)
{
    /*
    * raw song and enc song is of size 16 bytes while
    * key is of size 16-bytes
    */

    int result = TC_PASS;
    struct tc_aes_key_sched_struct s;
    tc_aes128_set_encrypt_key(&s, key);
    tc_aes_encrypt(enc_song, raw_song, &s);

};


int decrypt_song(uint8_t* key, uint8_t* raw_song, uint8_t* enc_song)
{
    /* 
    * Decryption of raw song
    * takes encode song as input along with the key
    * returns the raw song
    */
    
    int result = TC_PASS;
     struct tc_aes_key_sched_struct s;
     tc_aes128_set_decrypt_key(&s, key);
     tc_aes_decrypt(raw_song,enc_song,&s);
     		if (tc_aes_decrypt(raw_song, enc_song, &s) == 0) {
			TC_ERROR("aes_decrypt failed\n");
			result = TC_FAIL;
		}
};

// int key_gen(uint8_t * pub_key, uint8_t * priv_key)
// {
//     // this program generates keys
//     int status;
//     status = ecdh_generate_keys(pub_key, priv_key);
//     return status;
// };

// int keyshared(const uint8_t* private_key, const uint8_t* others_pub, uint8_t* sharedkey)
// {
//     int status;
//     status = ecdh_shared_secret(private_key,others_pub,sharedkey);
//     return status;
// };
