#ifndef __SONG_H__
#define __SONG_H__

#include "aes.h"
#include "ecdh.h"
#include "utils.h"
#include "constantsA.h"

/* TC_ here stands for 'Test Case' not 'TinyCrypt' */
#define TC_PASS 0
#define TC_FAIL 1

#define PRINT_DATA(fmt, ...) printf(fmt, ##__VA_ARGS__)

#define PRINT_LINE                                                     \
	PRINT_DATA(                                                        \
		"============================================================" \
		"=======\n")


#define FAIL "FAIL"
#define PASS "PASS"
#define FMT_ERROR "%s - %s@%d. "

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

int schedule (uint8_t* key,const TCAesKeySched_t s);
int encrypt_song (uint8_t* key, uint8_t* raw_song, uint8_t* enc_song,uint8_t * expected);

//int return_public_key(uint8_t* public_key);

int key_gen(uint8_t * pub_key, uint8_t * priv_key);

//int decrypt_song(const TCAesKeySched_t s, uint8_t* priv_key, uint8_t* public_key);

int keyshared(const uint8_t* private_key, const uint8_t* others_pub, uint8_t* sharedkey);
int write_mapping(char key, int val);
int read_mapping(char key);

#endif /* __SONG_H__ */