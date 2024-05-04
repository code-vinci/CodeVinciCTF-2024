#include <stdio.h>
#include <stdlib.h>

void buffering() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void menu(){
    puts("questa e' programma magico..."); 
    puts("dimmi un ordine e lo faro'!!!"); 
    puts("completamente gratis $$$$$$$$$$$$"); 
}

void win(){
    puts(getenv("FLAG"));
}

void printLOGO(){
    FILE *file;
    char carattere;

    file = fopen("logo.txt", "r");

    if (file == NULL) {
        printf("Impossibile aprire il file.\n");
        exit(1); 
    }

    while ((carattere = fgetc(file)) != EOF) {
        printf("%c", carattere);
    }

    fclose(file);
}

void clearBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main(){
    buffering();
    printLOGO(); 
    menu(); 

    char nome[32]; 
    char cognome[32]; 

    puts("però prima dimmi il tuo nome: "); 
    scanf("%32s", nome); 

    clearBuffer();     

    printf("ciao "); 
    printf(nome); 

    puts("\nva be dai in tanto che ci sei dimmi anche il cognome: "); 
    gets(cognome); 

    printf("grazie mille e alla prossima CodeVinciCTF{......................}\n"); 

    return 0; 
}   