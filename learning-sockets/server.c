#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8088

int main(int argc, char *argv[]) {
    
    char server_message[256] = "You have reached the server!";

    // create the server socket
    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if(server_socket == 0) {
        printf("Error. Could not create socket.\n");
        exit(1);
    }

    // Attaching the socket to our address
    int opt = 1;
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
    {
        printf("Error: Could not attach. Exiting...\n");
        exit(1);
    }

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the specified IP and port
    if(bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Error binding.\n");
        exit(1);
    }

    if(listen(server_socket, 1) < 0) {
        printf("Error binding.\n");
        exit(1);
    }

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    // for fail-safe program, we check if the socket is actually created and the connection is accepted
    if (client_socket < 0)
    {
        printf("Error: Could not accept a connection. Exiting...\n");
        exit(1);
    }

    // after the accepted connection we can start the communication
    // this part is based on the fact that we wait for the message from the 

    char strReadBuffer[256];
    if (recv(client_socket, strReadBuffer, sizeof(strReadBuffer), 0) < 0) {
        printf("Error receiving the message from the client. Exiting..\n");
        // exit(1);
    }

    printf("Message received: %s\n", strReadBuffer);

    if(send(client_socket, server_message, sizeof(server_message), 0) < 0) {
        printf("Error sending message to the client.\n");
        exit(1);
    }

    close(server_socket);
    
    return 0;
}