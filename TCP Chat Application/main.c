// Project: TCP Chat Application (Server and Client)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Function to handle client communication
void handleClient(int clientSocket, struct sockaddr_in clientAddr) {
    char buffer[BUFFER_SIZE];
    char clientIP[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIP, INET_ADDRSTRLEN);
    printf("Connected to client %s:%d\n", clientIP, ntohs(clientAddr.sin_port));

    while (1) {
        int bytesReceived = recv(clientSocket, buffer, BUFFER_SIZE, 0);
        if (bytesReceived <= 0) {
            printf("Client %s:%d disconnected.\n", clientIP, ntohs(clientAddr.sin_port));
            close(clientSocket);
            break;
        }

        buffer[bytesReceived] = '\0';
        printf("Client %s:%d: %s\n", clientIP, ntohs(clientAddr.sin_port), buffer);

        // Broadcast the message to all other clients
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (i != clientSocket) {
                send(i, buffer, strlen(buffer), 0);
            }
        }
    }
}

int main() {
    int serverSocket, newClientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t clientAddrLen = sizeof(clientAddr);
    int opt = 1;
    char buffer[BUFFER_SIZE];

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set socket options
    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to a port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Socket binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started, waiting for connections...\n");

    while (1) {
        // Accept new client connection
        newClientSocket = accept(serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (newClientSocket == -1) {
            perror("Accept failed");
            continue;
        }

        // Fork a new process to handle the client communication
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            close(serverSocket);
            handleClient(newClientSocket, clientAddr);
            exit(EXIT_SUCCESS);
        } else if (pid > 0) {
            // Parent process
            close(newClientSocket);
        } else {
            perror("Fork failed");
        }
    }

    close(serverSocket);
    return 0;
}
