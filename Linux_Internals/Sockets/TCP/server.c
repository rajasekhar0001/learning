#include <sys/socket.h>
#include <stdio.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <arpa/inet.h>


#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

int main() {
    int socket_fd = socket (AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("socket");
        exit(0);

    }
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;
    if (bind(socket_fd, (struct sockaddr *) &addr, sizeof(struct sockaddr)) == -1) {
        perror("bind");
        printf("errno: %d\n", errno);
        exit(0);
    }

    if (listen(socket_fd, 5)==-1) {
        perror("listen");
    }
    printf("Waiting for connection\n");
    while (1)  {
    int file_d = accept(socket_fd, NULL, NULL);
    if (file_d == -1) {
        perror("accept");
        exit(0);
    }

    printf("Connection done successfully\n");
    char buf[100];
    recv(file_d, buf, 100, 0);

    printf("Received data :  %s\n", buf);
    
    }
    
}
    