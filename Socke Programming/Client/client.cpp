#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

#define PORT 9000

using namespace std;
int clientSocket;
sockaddr_in client;


int main() {
    // client socket to interact with server
    


    // Configuring client address
    
    int ch;

    
    while(1){
    clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket < 0) {
        cout << "client socket is not opened\n";
        exit(0);
    }
    else {
        cout << "Client socket opened\n";
    }


    client.sin_addr.s_addr = inet_addr("127.0.0.2");
    client.sin_family = AF_INET;
    client.sin_port = htons(PORT);
    memset(&client.sin_zero, 0, 8);
    int ret=0;;// = connect(clientSocket, (struct sockaddr*) &client, sizeof(client));
    // connect() makes attempt to make a connection on socket
    // int ret2 = connect(clientSocket, (struct sockaddr*) &client, sizeof(client));
    if (ret < 0) 
    {
        cout << "failed to connect " << ret << "\n";
        exit(0);
    }
    cout << "connect successful (connected to server)..." << ret << "........\n";


    // char buffer[255];
    // recv(clientSocket, buffer, 30, 0);
    // // recv() is also a blocking call until it reads something on the port

    // cout << "Press any character to see received message : \n";
    // cin >> ch;

    // cout << "buffer :  " << buffer << endl;

    // cout << "Now send your messages to the server\n";
    

    
    while (1) {
        ret = connect(clientSocket, (struct sockaddr*) &client, sizeof(client));

        char buffer[255];
        recv(clientSocket, buffer, 30, 0);
    // recv() is also a blocking call until it reads something on the port

    cout << "Press any character to see received message : \n";
    cin >> ch;

    cout << "buffer :  " << buffer << endl;

    cout << "Now send your messages to the server\n";
    

        char buff[256] = { 0};
        cin >> buff ;

        send(clientSocket, buff, 255, 0);

        cout << "Press 1 to get the response from the server :: \n";

        cin >> ch;
        

        recv(clientSocket, buff, 255, 0);

        cout << "Received message : " << buff << endl;

        cout << "Send another message\n";

    }

    }

}       