#include <stdio.h>
#include <inttypes.h>
#include <string.h>

#define KEYS 16

// prints string as hex
static void phex(uint8_t* str)
{
    unsigned char i;
    for (i = 0; i < 16; ++i)
        printf("%.2x", str[i]);
    printf("\n");
}


int main()
{
    uint8_t nist_input[KEYS] = {
		0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d,
		0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34
	};

    printf("Nist input: ");
    phex(nist_input);
    printf("\n");

}