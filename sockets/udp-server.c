#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024


int main() {
	int sockfd;
	char buffer[MAXLINE];
	char *hello = "Hello from server";
	struct sockaddr_in servaddr, cliaddr;
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	memset(&servaddr, 0, sizeof(servaddr));
	memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	int len, n;

	len = sizeof(cliaddr);
  printf("Server ready for connection\n");
  while (1) {
    n = recvfrom(sockfd, (char *)buffer, MAXLINE,
      MSG_WAITALL, ( struct sockaddr *) &cliaddr,
      &len);
    buffer[n] = '\0';
    printf("\tClient : %s", buffer);
    bzero(buffer, MAXLINE);
    n = 0;
    printf("\tServer: ");
    while ((buffer[n++] = getchar()) != '\n');
    sendto(sockfd, (const char *)buffer, strlen(buffer),
      MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
        len);
    printf("message sent.\n");
    if (strncmp(buffer, "exit", 4) == 0) {
      break;
    }
  }
  close(sockfd);
	return 0;
}
