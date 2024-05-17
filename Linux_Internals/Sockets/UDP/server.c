#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>

int main() {
    // Create UDP socket
    int server_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    // Address
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    if (bind(server_fd, (struct sockaddr*) &addr, sizeof(struct sockaddr)) ==  -1)
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // Mo listen
    // No accept

    // Since UDP is not connection oriented, we will specify address 
    // which says to which address we are sending
    struct sockaddr_in client_addr;

    char buf[100];
    int len = recvfrom(server_fd, buf, 100, 0, (struct sockaddr*) &client_addr, sizeof(struct sockaddr));

    printf("Sent message from Server whose length : %d\n", len);
    printf("dat is : %s\n", buf);


    while (1);
}