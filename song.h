#include "aes.h"
#include "ecdh.h"
#include "utils.h"
#include "constantsA.h"

/* This code attempt to solve the drm problem of song encryption and decryption */

/* structure for song protection */
 struct mvpdata{
 	uint8_t * enc_song[16];
    uint8_t * master_pub_key[ECC_PUB_KEY_SIZE];
 };


struct user{
    uint8_t priv_key[ECC_PRV_KEY_SIZE];
    uint8_t pub_key[ECC_PUB_KEY_SIZE];
    uint8_t username[15];
};


int encrypt_song (uint8_t* key, uint8_t* raw_song, uint8_t* enc_song);

//int return_public_key(uint8_t* public_key);

int key_gen(uint8_t * pub_key, uint8_t * priv_key);

//int decrypt_song(const TCAesKeySched_t s, uint8_t* priv_key, uint8_t* public_key);

int keyshared(const uint8_t* private_key, const uint8_t* others_pub, uint8_t* sharedkey);
int write_mapping(char key, int val);
int read_mapping(char key);

