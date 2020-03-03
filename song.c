#include <stdio.h>
#include "aes.h"
#include "ecdh.h"
#include "utils.h"
#include "constantsA.h"
#include "song.h"
#include "map.h"


int encrypt_song (uint8_t* key, uint8_t* raw_song, uint8_t* enc_song)
{
    const TCAesKeySched_t s;
    int tc_aes128_set_encrypt_key(s, key);
    int tc_aes_encrypt(enc_song, raw_song, s);
    return tc_aes_encrypt(enc_song, raw_song, s);
};


int key_gen(uint8_t * pub_key, uint8_t * priv_key)
{
    // this program generates keys
    ecdh_generate_keys(pub_key, priv_key);
    return ecdh_generate_keys(pub_key, priv_key);
};

int keyshared(const uint8_t* private_key, const uint8_t* others_pub, uint8_t* sharedkey)
{
    int ecdh_shared_secret(private_key,others_pub,sharedkey);
    return ecdh_shared_secret(private_key,others_pub,sharedkey);
    
};

int write_mapping(char key, int val)
{
    map_int_t m;
    map_init(&m);
    map_set(&m, key,val);
    map_deinit(&m);

    return;
};

int read_mapping(char key)
{
    map_int_t m;
    map_init(&m);
    int *val = map_get(&m,key);
    if(val)
    {
        printf("value: %d\n", *val);
    }else{
        printf("value not found\n");
    }
    map_deinit(&m);
};