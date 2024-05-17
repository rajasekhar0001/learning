#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdlib.h>
#include <arpa/inet.h>

int main() {
    int read_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (read_fd == -1) {
        perror("socket");
        exit(0);
    }
    // bind optional

    // Listen not required in case of client

    //addr

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;


    // Connect to server

    if (connect(read_fd,(struct sockaddr*) &addr, sizeof(struct sockaddr)) == -1) {
        perror("connect");
        exit(0);
    }

    printf("Connected successfully to server\n");

    send(read_fd, "First client socket", 40, 0);

    printf("Done successfully\n");
    while (1);

}