/*
 ============================================================================
 Name        : hashfunct.c
 Author      : damelino
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Spongent.h"

uint8_t* hex_decode(char *in, int len, BitSequence *out);

int main(int argc, char* argv[]) {

   int i = 0;
   DataLength size = 2816;
   HashReturn res;
   //BitSequence PUF [352] = {0xa0,0x78,0xb4,0x7b,0x8d,0xa3,0xdd,0xa9,0x26,0xc3,0x39,0x0a,0x3c,0x01,0xf5,0x73,0x22,0x2e,0x34,0x54,0xec,0x6b,0x27,0xbe,0x0b,0x7a,0x65,0x4d,0xe8,0xe8,0x32,0x23,0xfe,0x41,0xe3,0x05,0xd7,0x55,0x53,0xe9,0xb3,0xa0,0xe9,0xe2,0xee,0xd0,0x54,0xd4,0x6f,0xbe,0x2e,0x4a,0x0c,0x3c,0x7d,0xec,0x10,0x28,0x1f,0xb1,0xa2,0x82,0x21,0xb8,0xc8,0x3f,0x00,0x9a,0x50,0xf9,0xdd,0x16,0x0b,0x93,0xc9,0x1b,0xb7,0xf2,0xdb,0x7d,0x72,0x20,0xcf,0x11,0xe6,0x1d,0x4e,0x6b,0x06,0x72,0x79,0x2c,0x0b,0x10,0x24,0x17,0x67,0x71,0xe8,0x05,0xeb,0x51,0x73,0x74,0x51,0x4c,0xa4,0x0c,0x2d,0x77,0x9e,0x8a,0xf6,0x08,0xbc,0x72,0xae,0xd6,0x23,0x7f,0xb0,0xa6,0xdd,0x38,0xb7,0x02,0x9e,0x66,0x4d,0x12,0x30,0xbc,0xa9,0x70,0x7d,0x18,0x97,0x90,0x4e,0xae,0x3a,0xc6,0x6b,0xef,0x8b,0xf9,0xbc,0xa9,0xea,0xc2,0x47,0x65,0x59,0xaa,0x67,0xf6,0x1e,0x11,0x6f,0xb3,0xf1,0x6d,0x43,0x5d,0x3f,0x23,0xc7,0x37,0xc3,0x00,0xf1,0xa0,0xad,0xee,0x9d,0x1f,0x6b,0x4d,0x30,0x78,0x0b,0x57,0x31,0xff,0x02,0x05,0x6c,0x1c,0x84,0xa2,0xf3,0x72,0xd4,0x22,0x94,0xf6,0xd0,0xda,0x55,0xf5,0x3e,0x0c,0xc4,0x03,0x3c,0x14,0xf9,0x5f,0xb9,0x35,0xbc,0x40,0x80,0xc1,0x51,0x56,0x86,0x3a,0x7f,0x91,0xd6,0x3a,0x57,0x86,0x52,0x3b,0x50,0x1f,0x9c,0xc6,0x57,0x55,0xe4,0x60,0x01,0xb3,0xf6,0x7e,0x7f,0x7f,0x69,0xf8,0x20,0x3f,0x6a,0xf5,0x59,0xe6,0xba,0x90,0xb3,0x33,0x31,0xd6,0x8d,0xf0,0x9c,0x8b,0x93,0xc0,0xf5,0x1b,0x1d,0xe5,0x28,0x5a,0xc1,0x47,0xf5,0xef,0x1e,0xe5,0x50,0x05,0x4c,0x28,0xcd,0x78,0xf4,0x43,0x0c,0x74,0x79,0x60,0xa0,0x3e,0xb4,0x96,0x20,0x08,0x92,0x5c,0x8c,0xc7,0x07,0x7d,0xe6,0x4b,0x7b,0xc7,0x71,0x39,0xdd,0xea,0x5d,0xf0,0x66,0x25,0xe5,0x4d,0x28,0xce,0x7e,0x69,0x26,0x4b,0x23,0x85,0x2b,0xdc,0xab,0x46,0xd2,0x54,0xf7,0xce,0x9b,0xf7,0x4e,0x1c,0x26,0x14,0xb7,0xc5,0x25,0xa3,0x97,0xd9,0xfd,0x81,0xec,0x52,0x32,0xf9,0x70,0x52,0x99,0xec,0x64,0xd4,0xc4,0x7b};
   BitSequence input[352];

   BitSequence key [16];
   for(i=0;i<16;i++) key[i] = 0;

   hex_decode(argv[1],704,input);
   //for(i=0;i<352;i++) printf("%d->%x\n",i,input[i]);

   //printf("\n");

   res = SpongentHash(input, size, key);


   for(i=0;i<16;i++) printf("%x",key[i]);

   printf("\n");

   //res = SpongentHash(PUF, size, key);

   //for(i=0;i<16;i++) printf("%x ",key[i]);
	return EXIT_SUCCESS;
}

uint8_t* hex_decode(char *in, int len, BitSequence *out)
{
    unsigned int i, t, hn, ln;

    for (t = 0,i = 0; i < len; i+=2,++t) {

            hn = in[i] > '9' ? (in[i]|32) - 'a' + 10 : in[i] - '0';
            ln = in[i+1] > '9' ? (in[i+1]|32) - 'a' + 10 : in[i+1] - '0';

            out[t] = (hn << 4 ) | ln;
            //printf("%c",out[t]);
    }
    return out;
}
