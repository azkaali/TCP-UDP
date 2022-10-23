// Server side implementation of UDP client-server model
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT	 8080
#define MAXLINE 1024

// Driver code
int main() {
	srand(time(NULL));
	int sockfd;
	int amount;
	int withd;
	char w[MAXLINE];
	char buffer[MAXLINE];
	char buffer2[MAXLINE];
	char buffer3[MAXLINE];
	char hello[MAXLINE]; //= "Hello from server";
	struct sockaddr_in servaddr, cliaddr[3];
	
	// Creating socket file descriptor
	if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
		perror("socket creation failed");
		exit(EXIT_FAILURE);
	}
	
	//memset(&servaddr, 0, sizeof(servaddr));
	//memset(&cliaddr, 0, sizeof(cliaddr));
	
	// Filling server information
	servaddr.sin_family = AF_INET; // IPv4
	servaddr.sin_addr.s_addr = INADDR_ANY;
	servaddr.sin_port = htons(PORT);
	
	// Bind the socket with the server address
	if ( bind(sockfd, (const struct sockaddr *)&servaddr,
			sizeof(servaddr)) < 0 )
	{
		perror("bind failed");
		exit(EXIT_FAILURE);
	}
	
	

	//HELLO HI

	int len1,len2,len3, n1,n2,n3;
	len1 = sizeof(cliaddr[0]); //len is value/resuslt
	len2 = sizeof(cliaddr[1]); //len is value/resuslt
	len3 = sizeof(cliaddr[2]); //len is value/resuslt

	n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
	puts(buffer);	
	n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);
	puts(buffer2);	
	n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
	puts(buffer3);
	
	
	
	//TASK ASSIGNMENT

	int task1=(rand()%(3-1+1))+1;
	sprintf(buffer, "%d", task1);
	puts("Asssigning task to client1:");
	puts(buffer);
	sendto(sockfd, (const char *)buffer, strlen(buffer),0, (const struct sockaddr *) &cliaddr[0],len1);
//	n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
	
	int task2;
	while(1){
	task2=(rand()%(3-1+1))+1;
	if(task1==task2)
	task2=(rand()%(3-1+1))+1;
	if(task1!=task2)
	break;
	}
	sprintf(buffer2, "%d", task2);	
	puts("Asssigning task to client2:");
	puts(buffer2);
	sendto(sockfd, (const char *)buffer2, strlen(buffer2),0, (const struct sockaddr *) &cliaddr[1],len2);
//	n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);

	
	int task3;
	while(1){
	task3=(rand()%(3-1+1))+1;	
	if(task1==task3||task2==task3)
	task3=(rand()%(3-1+1))+1;
	if(task3!=task1&&task3!=task2)
	break;
	}
	sprintf(buffer3, "%d", task3);
	puts("Asssigning task to client3:");
	puts(buffer3);
	sendto(sockfd, (const char *)buffer3, strlen(buffer3),0, (const struct sockaddr *) &cliaddr[2],len3);
//	n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
	

	
	//MENU
while(1)
{
	puts("-----------MENU-------------\n1 - Correspond to Card Reading\n2 - Pin Verification\n3 - Cash Withdraw\n0 - Exit");
	
	char in[256];
	gets(in);
	int choice=atoi(in);
		if(choice==1)
		{
		
		puts("--Card reading selected--");
		if(task1==1)
		{
		sendto(sockfd, (const char *)buffer, strlen(buffer),0, (const struct sockaddr *) &cliaddr[0],len1);
		n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
		puts("Status of card reading:");
		puts(buffer);
		}
		
		else if(task2==1)
		{
		sendto(sockfd, (const char *)buffer2, strlen(buffer2),0, (const struct sockaddr *) &cliaddr[1],len2);
		n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);
		puts("Status of card reading:");
		puts(buffer2);
		}
		
		else if(task3==1)
		{
		sendto(sockfd, (const char *)buffer3, strlen(buffer3),0, (const struct sockaddr *) &cliaddr[2],len3);
		n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
		puts("Status of card reading:");
		puts(buffer3);
		}
				
		
		

		
		}
		if(choice==2)
		{
		
		char pin[MAXLINE];
		puts("--Pin verification selected--");
		puts("Enter your pin:");
		gets(pin);
		
		
		if(task1==2)
		{
		sendto(sockfd, (const char *)pin, strlen(pin),0, (const struct sockaddr *) &cliaddr[0],len1);
		n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
		puts("Status of pin verification:");
		buffer[MAXLINE] = '\0';
		puts(buffer);
		}
		
		else if(task2==2)
		{
		sendto(sockfd, (const char *)pin, strlen(pin),0, (const struct sockaddr *) &cliaddr[1],len2);
		n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);
		puts("Status of pin verification:");
		buffer2[MAXLINE] = '\0';
		puts(buffer2);
		}
		
		else if(task3==2)
		{
		sendto(sockfd, (const char *)pin, strlen(pin),0, (const struct sockaddr *) &cliaddr[2],len3);
		n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
		puts("Status of pin verification:");
		buffer3[MAXLINE] = '\0';
		puts(buffer3);
		}
				
		}
		if(choice==3)
		{
		puts("--Cash withdrawal selected--");
		int len = 50000-0+1,i , r , temp;
		int num[len];
		    for( temp=0,i=0; temp<len; i++,temp++ )
			num[temp] = i;
		    	srand( time(NULL) );
		    for( i=len-1; i>0; i-- )
		    	    {
				r = rand()%i;  
				temp = num[i];
				num[i] = num[r];
				num[r] = temp;
			    }
		    	amount=num[r];
		    	puts("The amount in your account is:");
			printf("\n %d\n",amount);
			
			//SENDING AMOUNT TO THE DESTINED CLIENT
			if(task1==3)
				{
				sprintf(buffer,"%d",amount);
				sendto(sockfd, (const char *)buffer, strlen(buffer),0, (const struct sockaddr *) &cliaddr[0],len1);
				n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
				puts("Status of amount reception:");
				buffer[MAXLINE] = '\0';
				puts(buffer);
				}
				
				else if(task2==3)
				{
				sprintf(buffer2,"%d",amount);
				sendto(sockfd, (const char *)buffer2, strlen(buffer2),0, (const struct sockaddr *) &cliaddr[1],len2);
				n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);
				puts("Status of amount reception:");
				buffer2[MAXLINE] = '\0';
				puts(buffer2);
				}
				
				else if(task3==3)
				{
				sprintf(buffer3,"%d",amount);
				sendto(sockfd, (const char *)buffer3, strlen(buffer3),0, (const struct sockaddr *) &cliaddr[2],len3);
				n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
				puts("Status of amount reception:");
				buffer3[MAXLINE] = '\0';
				puts(buffer3);
				}
			
			puts("How much amount do u wish to withdraw?");
			gets(w);
			withd = atoi(w);
			printf("The amount to be withdrawn is %d \n", withd);
			
			if(amount>withd&&withd<=25000)
			{
			puts("Withdrawal possible");
			
			if(task1==3)
				{
				sendto(sockfd, (const char *)w, strlen(w),0, (const struct sockaddr *) &cliaddr[0],len1);
				n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
				puts("Status of withdrawal amount reception:");
				buffer[MAXLINE] = '\0';
				puts(buffer);
				}
				
				else if(task2==3)
				{
				sendto(sockfd, (const char *)w, strlen(w),0, (const struct sockaddr *) &cliaddr[1],len2);
				n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);
				puts("Status of withdrawal amount reception:");
				buffer2[MAXLINE] = '\0';
				puts(buffer2);
				}
				
				else if(task3==3)
				{
				sendto(sockfd, (const char *)w, strlen(w),0, (const struct sockaddr *) &cliaddr[2],len3);
				n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
				puts("Status of withdrawal amount reception:");
				buffer3[MAXLINE] = '\0';
				puts(buffer3);
				}
			
			//REMAINING AMOUNT
			char q[MAXLINE]="Remaining amount:";
			if(task1==3)
				{
				sendto(sockfd, (const char *)q, strlen(q),0, (const struct sockaddr *) &cliaddr[0],len1);
				n1 = recvfrom(sockfd, (char *)buffer, MAXLINE,0, ( struct sockaddr *) &cliaddr[0],&len1);
				puts("Remaining amount:");
				buffer[MAXLINE] = '\0';
				puts(buffer);
				}
				
				else if(task2==3)
				{
				sendto(sockfd, (const char *)q, strlen(q),0, (const struct sockaddr *) &cliaddr[1],len2);
				n2 = recvfrom(sockfd, (char *)buffer2, MAXLINE,0, ( struct sockaddr *) &cliaddr[1],&len2);
				puts("Remaining amount:");
				buffer2[MAXLINE] = '\0';
				puts(buffer2);
				}
				
				else if(task3==3)
				{
				sendto(sockfd, (const char *)q, strlen(w),0, (const struct sockaddr *) &cliaddr[2],len3);
				n3 = recvfrom(sockfd, (char *)buffer3, MAXLINE,0, ( struct sockaddr *) &cliaddr[2],&len3);
				puts("Remaining amount:");
				buffer3[MAXLINE] = '\0';
				puts(buffer3);
				}
			
			
			}
			else if(amount<withd)
			{
			puts("Balance insufficient");
			}
			else if(withd>25000)
			{
			puts("Withdrawal limit exceeded");
			}
		
		}
		if(choice==0)
		{
		puts("Exit");
		break;
		}
}
	//puts("im printing IP");
	//servaddr.sin_addr.s_addr = INADDR_ANY;
	//printf("\n%d\n",servaddr.sin_addr.s_addr);
	
	printf("IP of client 1 is: %s\n", inet_ntoa(cliaddr->sin_addr));
	printf("IP of client 2 is: %s\n", inet_ntoa(cliaddr->sin_addr));
	printf("IP of client 3 is: %s\n", inet_ntoa(cliaddr->sin_addr));
	return 0;
}
