#include <stdio.h>


#include "ecdh.h"
#include <string.h>
#include <stdlib.h>
#include "song.h"

int main ()
{

	char input[] = "c775e7b757ede630cd0aa1113bd102661ab38829ca52a6422ab782862f268646";
	char input2[] = "7e071fd9b023ed8f18458a73613a0834f6220bd5cc50357ba3493c6040a9ea8c";

	//Generate ecdh pub keys	
	static uint8_t pub[ECC_PUB_KEY_SIZE];
  	static uint8_t prv[ECC_PRV_KEY_SIZE];
    static uint8_t sharedkey[ECC_PUB_KEY_SIZE];
    static uint8_t sharedkey1[ECC_PUB_KEY_SIZE];
	memcpy(prv, input, ECC_PRV_KEY_SIZE);
	ecdh_generate_keys(pub, prv);

	static uint8_t pub2[ECC_PUB_KEY_SIZE];
  	static uint8_t prv2[ECC_PRV_KEY_SIZE];
	memcpy(prv2, input2, ECC_PRV_KEY_SIZE);
	ecdh_generate_keys(pub2, prv2);
    printf("pub1: ");
    for (int i = 0; i < ECC_PUB_KEY_SIZE;i++){
        printf("%02x",pub[i]);
    }
    printf("\n");

    printf("pub2: ");
    for (int i = 0; i < ECC_PUB_KEY_SIZE;i++){
        printf("%02x",pub2[i]);
    }
    printf("\n");


	//Start ecdh shared secret section
    ecdh_shared_secret(prv2,pub,sharedkey);
    printf("shared (prv2->pub1): ");
    for (int i = 0; i < ECC_PUB_KEY_SIZE;i++){
        printf("%02x",sharedkey[i]);
    }
    printf("\n");

	//Start ecdh shared secret section
    ecdh_shared_secret(prv,pub2,sharedkey1);
    printf("shared (prv1->pub2): ");
    for (int i = 0; i < ECC_PUB_KEY_SIZE;i++){
        printf("%02x",sharedkey[i]);
    }
    printf("\n");
    int status;
    status = strcmp(sharedkey,sharedkey1);
    printf("%d\n",status);
    
	return 0;
}