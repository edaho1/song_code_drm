#include <stdio.h>
#include "aes.h"
#include "ecdh.h"
#include "utils.h"
#include "constantsA.h"
#include "song.h"





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