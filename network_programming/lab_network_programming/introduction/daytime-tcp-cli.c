#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main(int argc, char **argv) {
    int sockfd; // socket file descriptor 
    int n; // number of bytes read
    char recvline[MAXLINE + 1];// buffer to store received data 
    struct sockaddr_in servaddr; // server address structure - IPv4
    if (argc != 2) 
        err_quit("usage: a.out <IPaddress>"); 

    if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) 
        err_sys("socket error"); 

    bzero(&servaddr, sizeof(servaddr)); // zero out the server address structure
    servaddr.sin_family = AF_INET; // IPv4
    servaddr.sin_port = htons(13); // daytime server port - port 13 is the one used for the Daytime Protocol

    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) // convert IP address from text to binary form
        err_quit("conversion failed: inet_pton error for %s", argv[1]);  

    if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0) // connect to the server
        err_sys("connection failed: connect error"); 

    while ( (n = read(sockfd, recvline, MAXLINE)) > 0) { 
        recvline[n] = 0;// null terminate the received data 
        if (fputs(recvline, stdout) == EOF) // output the received data to standard output
            err_sys("fputs error"); 
    }   
    if (n < 0) 
        err_sys("read error"); 
    exit(0); 
}