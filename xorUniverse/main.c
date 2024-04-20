#include <stdio.h>
#include <string.h>

int main(){

    char flag[] = {"CodeVinciCTF{...}"};
    char key[54] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZA"};   

    printf("my password encrypted: ");

    for(int i = 0; i < strlen(flag); i++){
        printf("%02x ", flag[i] ^ key[i]); 
    }  

    return 0; 
}