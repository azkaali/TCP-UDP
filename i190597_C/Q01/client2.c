// Client side implementation of UDP client-server model
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

// Driver code
int main() {
	//char *gets(char *str)
	int sockfd;
	char buffer[MAXLINE];
	char buffer2[MAXLINE];
	char hello[MAXLINE]="Hello im client 2";
	struct sockaddr_in	 servaddr;

	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}

	//memset(&servaddr, 0, sizeof(servaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(PORT);
	servaddr.sin_addr.s_addr = INADDR_ANY;   //removing inaddr_any, add inet_addr("172.17.47.10");
	
	int n, len,n2,len2;
	
	//HELLO HI
	sendto(sockfd, (const char *)hello, strlen(hello),
		0, (const struct sockaddr *) &servaddr,
			sizeof(servaddr));		

	//RECEIVING TASK WHICH HAS TO BE PERFROMED
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
				0, (struct sockaddr *) &servaddr,
				&len);

	int task = atoi(buffer);
	printf("The task assigned to me is: %d \n", task);
	
	if(task==1)
	{
		if(task!=0)
		{
		puts("Card reading successful\n");
		char reply[MAXLINE]="Card reading successful";
		sendto(sockfd, (const char *)reply, strlen(reply),
			0, (const struct sockaddr *) &servaddr,
				sizeof(servaddr));	
		}	
	}
	if(task==2)
	{
		puts("Pin verification");
		n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
		
		
		puts(buffer);
		buffer[n] = '\0';
			if(strlen(buffer)==4)
			{
			puts("Pin verified");
			char reply[MAXLINE]="Pin verification successful";
			sendto(sockfd, (const char *)reply, strlen(reply),
				0, (const struct sockaddr *) &servaddr,
					sizeof(servaddr));	
			
			}
			
			else
			{
			//puts("Pin verified");
			char reply[MAXLINE]="Pin verification failed";
			sendto(sockfd, (const char *)reply, strlen(reply),
				0, (const struct sockaddr *) &servaddr,
					sizeof(servaddr));	
			
			}		
	
	}
	if(task==3)
	{
	puts("Cash withdrawal");
	
	//BALANCE RECEPTION
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
	buffer[n] = '\0';
	puts(buffer);
	char reply[MAXLINE]="Amount received";
	//puts(buffer);
		sendto(sockfd, (const char *)reply, strlen(reply),
				0, (const struct sockaddr *) &servaddr,
					sizeof(servaddr));	
	int amount=atoi(buffer);



	//WITHDRAWAL AMOUNT RECEPTION
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
	buffer[n] = '\0';
	puts(buffer);
	char r[MAXLINE]="Withdrawal amount received";
	//puts(buffer);
		sendto(sockfd, (const char *)r, strlen(r),
				0, (const struct sockaddr *) &servaddr,
					sizeof(servaddr));	
	
	int withd=atoi(buffer);
	
	
	//REMANANT
	n = recvfrom(sockfd, (char *)buffer, MAXLINE,
					0, (struct sockaddr *) &servaddr,
					&len);
	buffer[n] = '\0';
	
	char bal[MAXLINE];
	amount-=withd;
	printf("\n%d\n",amount);
	
	sprintf(bal,"%d",amount);
	sendto(sockfd, (const char *)bal, strlen(bal),
				0, (const struct sockaddr *) &servaddr,
					sizeof(servaddr));	
	
	
	
	
	}
	



	close(sockfd);
	return 0;
}
