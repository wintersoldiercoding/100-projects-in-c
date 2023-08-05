// Project: Simple Email Client (Sending Emails)
// Repository link: https://github.com/wintersoldiercoding/100-projects-in-c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

// Function to send an email using SMTP protocol
void sendEmail(const char* sender, const char* receiver, const char* subject, const char* body) {
    int sockfd;
    struct sockaddr_in serverAddr;
    struct hostent* host;

    // Replace "smtp.example.com" with your SMTP server address
    const char* smtpServer = "smtp.example.com";
    const int smtpPort = 25;

    host = gethostbyname(smtpServer);
    if (!host) {
        perror("Could not resolve SMTP server address");
        return;
    }

    // Create a socket to connect to the SMTP server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(smtpPort);
    memcpy(&serverAddr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to the SMTP server
    if (connect(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Connection to SMTP server failed");
        close(sockfd);
        return;
    }

    char buffer[BUFFER_SIZE];

    // Read the SMTP server greeting
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    // Send the HELO command
    snprintf(buffer, sizeof(buffer), "HELO localhost\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    // Send the MAIL FROM command
    snprintf(buffer, sizeof(buffer), "MAIL FROM:<%s>\r\n", sender);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    // Send the RCPT TO command
    snprintf(buffer, sizeof(buffer), "RCPT TO:<%s>\r\n", receiver);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    // Send the DATA command
    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    // Send the email content
    snprintf(buffer, sizeof(buffer), "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n%s\r\n.\r\n", sender, receiver, subject, body);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    // Send the QUIT command
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, sizeof(buffer), 0);
    printf("SMTP Server: %s", buffer);

    close(sockfd);
}

int main() {
    char sender[100];
    char receiver[100];
    char subject[100];
    char body[BUFFER_SIZE];

    printf("Welcome to the Simple Email Client!\n");
    printf("Enter sender email address: ");
    scanf("%s", sender);

    printf("Enter receiver email address: ");
    scanf("%s", receiver);

    printf("Enter email subject: ");
    scanf("%s", subject);

    printf("Enter email body:\n");
    getchar(); // Clear the newline character from the input buffer
    fgets(body, sizeof(body), stdin);

    // Remove the newline character from the body
    body[strcspn(body, "\n")] = '\0';

    sendEmail(sender, receiver, subject, body);

    return 0;
}
