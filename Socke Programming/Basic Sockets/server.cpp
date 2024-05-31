#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main() {

    int serverSocket;
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(0);
    }
    int option;
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option)) == -1) {
        perror("setsockopt");
        exit(0);
    }

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    // addr.sin_addr.s_addr = INADDR_ANY; // loop back address
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    // memcpy((void*)addr.sin_addr, "127.0.0.1", 10);

    if (bind(serverSocket, (struct sockaddr*) &addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        exit(0);
    }

    listen(serverSocket, 2);
    perror("listen");
    // Which to use first accept or select

    fd_set readfd;
    fd_set writefd;

    FD_SET(serverSocket, &readfd);
    FD_SET(serverSocket, &writefd);

    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    int ret = select(serverSocket, &readfd, &writefd, NULL, &tv);
    if (ret == -1) {
        perror("select");
    }

    socklen_t size = sizeof(struct sockaddr);
    int newSocket = accept(serverSocket, (struct sockaddr*) &addr, &size);
    if (newSocket <  0) {
        printf("Failed to acept\n");
    }

    printf("Connected successfully\n"); 
    
    while(1) {
        char buf[1024];
        int recv_len = recv(newSocket, buf, 1024, 0);

        if (recv_len <= 0) {
            printf("failed to receive\n");
        }

        printf("%s  ->  %d\n", buf, recv_len);
        memset(buf, '\0', sizeof(buf));

        cout << "Type text that you want to sent to Client: " ;
        fgets(buf, 1024, stdin);
        int send_len = send(newSocket, buf, 1024, 0);
        if (send_len <= 0) {
            printf("Failed to acknoledge\n");
        }
        buf[0] ='\0';
    }

    // int rv = select()
}