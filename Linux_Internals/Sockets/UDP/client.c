#include <stdio.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <stdlib.h>

int main() {
    // Create UDP socket
    int client_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (client_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    // Address
    struct sockaddr_in addr;
    addr.sin_family = inet_addr("127.0.0.1");
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY;

    // Binding is optional in case of client
    // if (bind(client_fd, (struct sockaddr*) &addr, sizeof(struct sockaddr)) ==  -1)
    // {
    //     perror("bind");
    //     exit(EXIT_FAILURE);
    // }

    // Mo listen
    // No accept

    // Since UDP is not connection oriented, we will specify address 
    // which says to which address we are sending
    char buf[100];struct sockaddr_in client_addr;
    socklen_t len = sizeof(struct sockaddr);

    
    len = sendto(client_fd, "From client", 100, 0, (struct sockaddr*) &addr, &(len));

    printf("Received  message is : %s and whose length : %d\n", buf, len);
}