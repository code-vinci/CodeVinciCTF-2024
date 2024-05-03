#include <stdio.h>
#include <stdlib.h>

void buffering() {
    setvbuf(stdin, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
}

void ret2win(){
    puts(getenv("FLAG")); 
}

void selezione(){
    puts("[1] male"); 
    puts("[2] poteva andare meglio"); 
    puts("[3] bene"); 
    puts("[4] BENISSIMO"); 
    puts("[5] flag"); 
}

void questafunzione1(){
    puts("tu lo sai cosa sta succedendo???"); 
}

void questafunzione(){
    puts("spesso credo che le storie....."); 
    questafunzione1();
}

void doubleprintf(){
    printf("FINALMENTE LA MIA FUNZIONE PREFERITA"); 
}

void printfprintf(){
    puts("questa e' una doppia printf"); 
    puts("forse dovrei chiamare double printf"); 
}

void soluzioneeeee(){
    char storia[32]; 
    puts("ti pregro dimmi che sei riuscito a capire la storia... era cosi' semplice...."); 
    scanf("%s", storia); 
}

int main(){
    buffering();

    puts("la vulnerabilita' di questa sfida e''''''''''''''''''''''................................................"); 

    do
    {   
        printf("bo, @Greva ha scoperto che in realtà la terra e' piatta................................................"); 
        do
        {
            while (1)
            {
                for (size_t i = 0; i < 5; i++)
                {
                    printf("come sta andando questa CTF: \n"); 
                    selezione(); 
                    int selezione; 
                    scanf("%d", &selezione); 

                    switch (selezione){
                        case 1 : {
                            questafunzione();
                            puts("ho una grande confusione in testaaaaa"); 
                            break;
                        }
                        case 2 : {
                            printf("allora per fare il docker di questa challeng, bisogna...."); 
                            printfprintf(); 
                            break;
                        }
                        case 3 : {
                            printf("questa funzione sembra impari:\n"); 
                            soluzioneeeee(); 
                            break;
                        }
                        case 4 : {
                            printf("okok, va bene ora facciamo le cose serieeeee"); 
                            break;
                        }
                        case 5 : {
                            printf("se ciao, va bene, ci sentiamo per la prossima CTF, ti lascio il mio numero nel caso 351345...\n"); 
                            break;
                        }
                        default: {
                            printf("ah non lo so io......."); 
                            break;
                        }
                    }
                }
            } 
        } while (1);
    } while (1);
    

    return 0; 
}