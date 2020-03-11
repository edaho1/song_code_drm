main: utils.c song.c main.c aes_encrypt.c aes_decrypt.c ecdh.c
	gcc -o -g test utils.c song.c main.c aes_encrypt.c aes_decrypt.c ecdh.c
