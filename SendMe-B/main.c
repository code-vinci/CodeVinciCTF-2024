#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu();
void buffering();
void fakeStampaFlag(); 
void nonFacevaRidere();
void firmaMucca(); 

int main(){
    buffering(); 

    int scelta = 0; 

    while (1){
        printf("Cosa fa una mucca con una macchina da scrivere????????\n"); 

        do{
            menu();
            scanf("%d", &scelta); 
        }while(scelta < 1 || scelta > 3); 

        switch (scelta)
        {
            case 1:
                fakeStampaFlag(); 
                break;
            case 2:
                nonFacevaRidere(); 
                break;
            case 3:
                printf("non troverai mai la mia flag"); 
                break;
            case 4: 
                printf("bella questa opzione 4, mi chiedo a cosa serva..."); 
            default:
                printf("pussa via.............."); 
                break;
        }
    }
    
    return 0; 
}

void buffering() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void menu(){
    puts("1) stampa la flag");
    puts("2) produce lattoscrizioni"); 
    puts("3) scrive: 'la divina commedia'"); 
    puts("3) produce latte"); 
}

void fakeStampaFlag(){
    printf("EH NO CARO MIO, questa flag te la dovrai guadagnare!!!!!!!\n");
}

void firmaMucca(){
    puts("             /( ,,,,, )\\");
    puts("            _\\,;;;;;;;,/_");
    puts("         .-\"; ;;;;;;;;; ;\"-.");
    puts("         '.__/`_ / \\ _`\\__.'");
    puts("            | (')| |(') |");
    puts("            | .--' '--. |");
    puts("            |/ o     o \\|");
    puts("            |           |");
    puts("           / \\ _..=.._ / \\");
    puts("          /:. '._____.'   \\");
    puts("         ;::'    / \\      .;");
    puts("         |     _|_ _|_   ::|");
    puts("       .-|     '==o=='    '|-.");
    puts("      /  |  . /       \\    |  \\");
    puts("      |  | ::|         |   | .|");
    puts("      |  (  ')         (.  )::|");
    puts("      |: |   |; U U U ;|:: | `|");
    puts("      |' |   | \\ U U / |'  |  |");
    puts("      ##V|   |_/`\"\"\"`\\_|   |V##");
    puts("           ##V##         ##V##");
}

void nonFacevaRidere(){
    char frase[20]; 
    char lettera = 'A'; 

    puts("SI MA STAI CALMO"); 
    puts("ora se vuoi la flag mi dovrai dire la parola magica"); 
    puts("quale?"); 

    scanf("%s", frase); 

    if(lettera == 'B'){
        puts("O K QUESTA VOLTA HAI VINTO TU"); 
        puts("la prossima volta non sarà così facile"); 
        firmaMucca();  
        puts(getenv("FLAG"));
        exit(0); 
    }

    puts("AHAHAHAHAAHAHHAHAHAHAHAHHAHAHHA"); 
}