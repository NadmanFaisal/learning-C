#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define PORT 8088

int main(int argc, char *argv[]) {
    
    // create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    // failsafety
    if (network_socket < 0) {
        printf("Unable to create socket\n");
        return -1;
    }

    // specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(network_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        printf("Unable to connect.\n");
        return -1;
    }

    char client_message[256];
    printf("Enter message: ");
    fgets(client_message, sizeof(client_message), stdin);
    if(send(network_socket, client_message, strlen(client_message), 0) < 0) {
        printf("Unable to send message\n");
        return -1;
    }

    // receive data from the serverr
    char server_response[256];
    if(recv(network_socket, server_response, sizeof(server_response), 0) < 0) {
        printf("Error while receiving data from the server.\n");
        return -1;
    }

    printf("The server sent the data: %s\n", server_response);
    close(socket);
    return 0;
}