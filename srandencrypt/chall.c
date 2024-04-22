#include <stdio.h>
#include <stdlib.h>

void encrypt( char* secret, unsigned int key )
{
    srand( key );

    for ( int i = 0 ; secret[i] ; i++ ) {

        unsigned char block = rand();

        if ( i < 4 )    block = key>>((3-i)*8);

        printf("%s0x%02X", (i==0)?"":", ", secret[i] ^ block );

    }
}


int main( int argc, char** argv )
{
    char* flag = "CodeVinciCTF{I_h4v3_cr3473d_An_1nd3c1ph3ra6le_k3y}";
    unsigned int key = 2362632351;

    encrypt( flag, key );
    puts("");

    return 0;
}
