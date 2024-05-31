#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

int main() {

    int clientSocket;
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(0);
    }
    

    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port = htons(9000);
    addr.sin_addr.s_addr = INADDR_ANY; // loop back address
    // memcpy((void*)addr.sin_addr, "127.0.0.1", 10);

    // if (bind(serverSocket, (struct sockaddr*) &addr, sizeof(struct sockaddr)) == -1) {
    //     perror("bind");
    //     exit(0);
    // }

    // listen(serverSocket, 2);
    // perror("listen");
// while(1) {
    connect(clientSocket, (struct sockaddr*) &addr, sizeof(struct sockaddr));
    perror("connect");
//     sleep(1);
// }
    // socklen_t size = sizeof(struct sockaddr);
    // int newSocket = accept(serverSocket, (struct sockaddr*) &addr, &size);
    // cout << "retval: " << retval << endl;
    // if (retval == 1) {
    //     printf("Process\n");
    // }

    int send_len = send(clientSocket, "12345", 6, 0);

    if (send_len <= 0) {
        cout << "Send failed \n";
    }

    




    
    

}