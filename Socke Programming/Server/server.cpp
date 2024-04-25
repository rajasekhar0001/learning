#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>
#define PORT 9000


using namespace std;

sockaddr_in srv; //
fd_set fr, fw, fe;  // this is the socket descriptor set
/**
 * fr -> read 
 * fw -> write
 * fe -> exception sockets
*/

int nMaxFd; // maximum number 
int serverSocket;
int readSocketDescripto[5];


void processNewMessage(int clientServerSocket) {
    cout << "Processing the new message from client socket:  " << clientServerSocket << endl;
    char buf[256] = {0};
    
    int ret = recv(clientServerSocket, buf, 256, 0);
    cout << "Acknledgement from client: " << buf << endl;
    if (ret < 0 )
    {

        cout << "Something happened. closing the connection from client\n";
        close(clientServerSocket);
        for (int i=0;i<5;i++ ){
            if (readSocketDescripto[i] == clientServerSocket) {
                readSocketDescripto[i] = 0;  break;
            }
        }
        
    }
    else {

    // cout << "Press any key t see response from client\n";
    // getchar();

        cout << buf << endl;

        ret = send(clientServerSocket,"Processed your request", 50, 0);
        if (ret < 0)
            cout << "Failed to send response to client \n";  
        cout << "........................................................." << endl;
    }
}

void processNewRequest() {
    
    if (FD_ISSET(serverSocket, &fr)) {
        // write code to accept client request
        socklen_t len =  sizeof(struct sockaddr);
        // when we accept a client request using accept call it returns new client server socket id to communicate with client
        int clientServerSocket = accept (serverSocket, NULL,&len);  // clientServerSocket file descriptor
        int ind;

        if (clientServerSocket > 0) {
            for (ind=0;ind <5;ind++) {
                if (readSocketDescripto[ind]==0) {                
                    readSocketDescripto[ind] = clientServerSocket;
                    send(clientServerSocket, "connection done successfully", 35, 0);
                    processNewMessage(clientServerSocket);
                    break;
                }
            }
            if (ind >= 5)
                cout << "No space for new connection" << endl;
        
        }
        else {
            for (int i=0;i< 5;i++) {
               if (FD_ISSET(readSocketDescripto[i], &fr) ){
                    processNewMessage(readSocketDescripto[i]);
                    break;
               }
            }
        }

        // Need to add clientServerSocket to array

        


        // for (int i=0;i< 5;i++) {
        //     if (readSocketDescripto[i] != 0) {
        //         processNewMessage(readSocketDescripto[i]);
        //         readSocketDescripto[i] = 0;
        //     }
        // }

        // processNewMessage(clientServerSocket);


        

        
    }
}

//	void processNewRequest() {
//	    if (FD_ISSET(serverSocket, &fr)) {
//	        // write code to accept client request
//	        socklen_t len =  sizeof(struct sockaddr);
        //	
//	        int clientSocket = accept (serverSocket, NULL,&len);

//	    }
//	}

int main() {

    // Initialize the Socket
    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // return value is socket descripter
    /**
        0. AF_INET for UDP or TCP and IPv4
        1. Connection oriented (TCP based)
        2. -> 0 -> for internet protocol / underlying system protocol i.e., HTTP
              IPPROTO_TCP -> for TCP protocol
    */

    if (serverSocket < 0) {
        cout << "Socket is not opened\n";
        exit(0);
    }
    else {
        cout << "Socket is opened\n";
    }

    //  Initialize the environment for the sockaddr structure

    srv.sin_family = AF_INET;  
    srv.sin_port = htons(PORT);  // byte order conversion happens here
    // htons -> Host to network start
     // this is for network byte order
    // * network byte order defines the bit order of the network addresses
    //   as they pass through the network
    /**
        * TCP-IP byte order is -> Big Endian
        * UDP-IP 
    */
    srv.sin_addr.s_addr = INADDR_ANY;  // means Assigning our own system IP address
    inet_addr("127.0.5.65"); // -> for custom IP 
    memset (srv.sin_zero, 0, 8);  // size of sin_zero member of srv

    // setsockopt  -> it should be done before bind()
    //  used to set the socket options
    int nOptVal = 0;
    int sizeNOptVal = sizeof(nOptVal);
    int ret = setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, (const char *)&nOptVal, sizeNOptVal);
    if (ret == 0)
        cout << "The setsockopt call successful\n";
    else 
        cout << "The setsockopt call failed : " <<ret << " \n";

    // Bind the socket to the local port
    /**
        * IP addresses enable messages to go to and from specific devices,
         port numbers allow targeting of specific services or applications
          within those devices.
        * choose port apart from 0 to 256 because they are reserved
    */
    int bind_status = bind(serverSocket, (sockaddr*)&srv, sizeof(sockaddr));
    if (bind_status < 0) {
        cout << "Failed to bind to local port\n";
        exit(0);
    }
    else {
        cout << "SUccessfully bind to local port :  " << bind_status << endl;;
    }


    // listen the request from client (queues the requests)
    int listen_status = listen(serverSocket, 5); /* second argument is backlog 
    that means how many requests ( will be active QUeue)  that server can pull at a time, more than 5 need to wait in the Queue
    */
    if (listen_status < 0) {
        cout << "Failed to start listening to local port\n";
        exit(0);
    }
    else {
        cout << "Started listening to local port:  " << listen_status << endl;
    }
                                            

    // Keep waiting for new requests and proceed as per the request
    nMaxFd = serverSocket;
    struct timeval tv; // time to wait 
    tv.tv_sec = 1;
    tv.tv_usec  =0;
    // Keep waiting for the new requests  and proceed as per the request
   
    while(1) {
        FD_ZERO(&fr);
        FD_ZERO(&fw);
        FD_ZERO(&fe);
        FD_SET(serverSocket, &fr);
        FD_SET(serverSocket, &fe);
        cout << "Before select call : "  << endl;
    
        int nRet = select (nMaxFd + 1 , &fr, &fw, &fe, &tv); 
        // select call unsets all the socket descripters
        /**
         * The select() call monitors activity on a set of sockets looking for sockets ready for reading,
           writing, or with an exception condition pending
        */


        if (nRet > 0) {
            // When some one connects or communicates with a message over
            // a dedicated connection
            cout << "Data on port processiong now ... ..\n";
            processNewRequest();
        }
        else if (nRet == 0) {
            // No connection or any communication request made
            // or you can say none of the socket descriptors are ready
            cout << "Nothing on port : " << PORT << endl;
        }
        else {
            // it failed and your application should show some useful message
            cout << "failed to connect :  " << nRet << "\n";
            exit(0);
        }
        cout << "After select call \n";
        sleep(2);

    }
    
}