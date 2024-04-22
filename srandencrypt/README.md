# Srandencrypt

This challenge use a srad function from stdlib for generate random number
for crypt the flag, but the first 4 block is the seed (key), you can read
the first 4 charater for read the key and set the seed to decrypt message

# Solution
```C

#include <stdio.h>
#include <stdlib.h>
#define len(var) (sizeof(var)/sizeof(var[0]))
typedef unsigned char byte;

byte text[] = {
0xCF, 0xBD, 0x8C, 0xFA, 0xBB, 0xD4, 0xA3, 0x85, 0x54, 0x37, 0x05, 0x00, 0xA9, 0x1D, 0xF5, 0x7D, 0x8E, 0x5D, 0xF1, 0x31, 0xC7, 0x17, 0x60, 0x2F, 0x5C, 0xC5, 0xA8, 0xB8, 0x53, 0x4D, 0xF7, 0xDE, 0xF5, 0x36, 0xA5, 0xEB, 0x21, 0x13, 0x07, 0x7E, 0xA5, 0xA1, 0xA5, 0xC5, 0x71, 0x61, 0xD5, 0xFC, 0x10, 0xFC
};

int main( int argc, char ** argv )
{
    unsigned int key = 0;

    for ( int i = 0 ; i < 4 ; i++ ) {
        key = ( key << 8 ) + ( text[i] ^ "Code"[i] );
    }

    srand(key);

    for ( int i = 0 ; i < len(text) ; i++ ) {

        byte block = (byte)rand();

        if ( i < 4 ) {
            block = (byte)( key >> ( ( 3 - i ) * 8 ) );
        }

        printf("%c", text[i] ^ block );
    }

    return 0;
}

```

# Author

`sDibuon`
