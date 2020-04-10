// use to run code:
// gcc copyfunc.c aes_encrypt.h aes_decrypt.h sha256.c sha256.h utils.c constantsA.h -o copytest
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "sha256.h"
#include "constantsA.h"
#include <inttypes.h>
#include "aes_decrypt.h"
#include "aes_encrypt.h"

#define NUM_OF_NIST_KEYS 48

int main()
{

	char input[16] = "2510000001110000";
    char priv[48] = "0123456789ABCDEF0123456789ABCDEF0123456789ABCDEF";
	//Create digest key and encrypt
	uint8_t digest[32];
	struct tc_sha256_state_struct s;	
	(void)tc_sha256_init(&s);
	tc_sha256_update(&s, input, strlen(input));
	(void)tc_sha256_final(digest, &s);
	
	struct tc_aes_key_sched_struct sk;
	uint8_t ciphertext[NUM_OF_NIST_KEYS];
	uint8_t private[48];
	memcpy(private, &priv, sizeof(priv));
	(void)tc_aes128_set_encrypt_key(&sk, digest);
	tc_aes_encrypt(ciphertext, private, &sk);
	//-------------------------
	printf("private: ");
	for (int i = 0; i < 48; i++){
		printf("%02x", private[i]);
	}
	printf("\n");
	//-------------------------
	

	//Decryption---------------
	//uint8_t digest[32];
	//struct tc_sha256_state_struct s;	
	(void)tc_sha256_init(&s);
	tc_sha256_update(&s, input, strlen(input));
	(void)tc_sha256_final(digest, &s);
	//struct tc_aes_key_sched_struct sk;
	(void)tc_aes128_set_decrypt_key(&sk, digest);

	uint8_t decrypted[NUM_OF_NIST_KEYS];
	tc_aes_decrypt(decrypted, ciphertext, &sk); //Ciphertext comes from user struct
	//-------------------------	
	//for loop to compare input and output
	printf("decrypted: ");
	for (int i = 0; i < 48; i++){
		printf("%02x", decrypted[i]);
	}
	printf("\n");

	return 0;
}