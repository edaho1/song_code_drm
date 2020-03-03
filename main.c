#include <stdio.h>
#include <inttypes.h>
#include "aes.h"
#include "ecdh.h"
#include "utils.h"
#include "constantsA.h"
#include "song.h"
#include "map.h"

int main(){

    /*87 407C DF6E DDEB 8E8B C1D3 3AA3 */
    static uint8_t * pub_key[ECC_PUB_KEY_SIZE]; //output from keygen
    static uint8_t * priv_key[ECC_PRV_KEY_SIZE]; // input to key gen (user must provide)
    static uint8_t * mpriv_key[ECC_PRV_KEY_SIZE] = {0x55,0xff,0x72,0x56,0x3e,0x87,0x3c,0xc3,0xbe,0x29,0x7e,0xd3,0x32,0x52,0x87,0x74,0x37,0xa9,0x9f,0x81,0xb8,0x7d,0x09,0x54,0x57,0xd2,0x93,0x56};
    int status,status1;

    uint8_t* raw_song[16] ={0x00,0x01, 0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09,0x0A,0X0B,0X0C,0X0D,0X0E,0X0F};
    uint8_t* enc_song[16];
     uint8_t* sharedkey[6*ECC_PUB_KEY_SIZE];

    struct user *master = {mpriv_key, pub_key}; //handling master key for encryption 
    struct mvpdata *map = {enc_song, master -> pub_key};
    struct user *user = {priv_key, pub_key};
    status  = key_gen(master -> pub_key, master -> priv_key);

    //printing results
    printf("Priv: ");
    for (int i = 0; i <ECC_PRV_KEY_SIZE; i++)
    {
        printf("%" PRIu8,master ->priv_key[i]);
    }
    printf("\n");
    printf("Pub: ");
    for (int i = 0; i <ECC_PUB_KEY_SIZE; i++)
    {
        printf("%" PRIu8,master -> pub_key[i]);
    }
    printf("\n");

    printf("status : %d\n",status);
    //encrypting song with master private key
    status1 = encrypt_song (master -> priv_key, raw_song, map -> enc_song);
    printf("song enc status: %" PRIu8 "\n",status1);
    printf("raw_song: ");
    for (int i = 0; i<16; i++)
    {
        printf("%" PRIu8,raw_song[i]);
    }
    printf("\n");
    
    printf("enc_song: ");
    for (int i = 0;i <16; i++)
    {
        printf("%" PRIu8,map -> enc_song[i]);
    }
    printf("\n");

    status = keyshared( master ->  priv_key, user -> pub_key, sharedkey);
    printf("keyshared status: %" PRIu8 "\n", status);
    printf("sharedkey: ");
    for (int i = 0; i < 6*ECC_PUB_KEY_SIZE; i++)
    {
        printf("%" PRIu8,sharedkey[i]);
    }
    printf("\n");

    key_gen(master -> pub_key, priv_key);
}
