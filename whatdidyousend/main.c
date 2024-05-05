#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 9090

int main() {
    struct sockaddr_in server_addr;
    int sockfd, addr_len, bytes_sent;
    
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
        perror("Errore nella creazione del socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_aton(SERVER_IP, &server_addr.sin_addr) == 0) {
        perror("Indirizzo IP non valido");
        exit(EXIT_FAILURE);
    }

    char messaggio[] = {"BnedWhobhBUGzrdoe^l2^5oxui0of^x1t^v5ou|"}; 

    for(int i = 0; i < strlen(messaggio); i++) 
        messaggio[i] ^= 1; 

    addr_len = sizeof(server_addr);
    bytes_sent = sendto(sockfd, messaggio, strlen(messaggio), 0, (struct sockaddr *)&server_addr, addr_len);
    if (bytes_sent == -1) {
        perror("Errore nell'invio del messaggio");
        exit(EXIT_FAILURE);
    }

    printf("Messaggio inviato con successo\n");

    close(sockfd);

    return 0;
}
