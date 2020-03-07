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
    tc_aes128_set_encrypt_key(s, key);
    tc_aes_encrypt(enc_song, raw_song, s);
    return tc_aes_encrypt(enc_song, raw_song, s);
};


int key_gen(uint8_t * pub_key, uint8_t * priv_key)
{
    // this program generates keys
    int status;
    status = ecdh_generate_keys(pub_key, priv_key);
    return status;
};

int keyshared(const uint8_t* private_key, const uint8_t* others_pub, uint8_t* sharedkey)
{
    int status;
    status = ecdh_shared_secret(private_key,others_pub,sharedkey);
    return status;
};
