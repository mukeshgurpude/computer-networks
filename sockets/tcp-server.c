#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#define MAX 80    // Max message size
#define PORT 8080 // Socket port number
#define SA struct sockaddr

void run(int sockfd) {
	char buff[MAX];
	int n;

	while(1) {
		bzero(buff, MAX);

		// read the message from client and copy it in buffer
		read(sockfd, buff, sizeof(buff));
		
    // print buffer which contains the client contents
		printf("From client: %s\t To client : ", buff);
		bzero(buff, MAX);
		n = 0;
		// copy server message in the buffer
		while ((buff[n++] = getchar()) != '\n');

		// send the buffer to client
		write(sockfd, buff, sizeof(buff));

		// if msg contains "Exit" then server exit and chat ended.
		if (strncmp("exit", buff, 4) == 0) {
			printf("Server Exit...\n");
			break;
		}
	}
}

int main(void) {
	int sockfd, connfd, len;
	struct sockaddr_in servaddr, cli;

	// Create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd == -1) {
		printf("socket creation failed...\n");
		exit(0);
	}
  printf("Socket successfully created..\n");
	bzero(&servaddr, sizeof(servaddr));

	// assign IP, PORT
	servaddr.sin_family = AF_INET;  // IPv4
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY); // Bound to any interface
	servaddr.sin_port = htons(PORT);  // Port number

	// Bind socket to given IP and port
	if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) {
		printf("socket bind failed...\n");
		exit(0);
	}
  printf("Socket successfully binded..\n");

	// Now server is ready to listen and verification
	if (listen(sockfd, 5) != 0) {
		printf("Listen failed...\n");
		exit(0);
	}
  printf("Server listening..\n");
	len = sizeof(cli);

	// Accept the data packet from client and verification
	connfd = accept(sockfd, (SA*)&cli, &len);
	if (connfd < 0) {
		printf("server accept failed...\n");
		exit(0);
	}
  printf("server accept the client...\n");

	// Function for chatting between client and server
	run(connfd);

	close(sockfd);
}
