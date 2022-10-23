#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
int main() {
	
	char request[256] = "Hello I am Client are you there";
	char buf[256];
	char str1[256];
	char str2[256];
	char c[256];
	// create the socket
	int sock;
	sock = socket(AF_INET, SOCK_STREAM, 0);
	
	//setup an address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = INADDR_ANY;
	server_address.sin_port = htons(3001);

	connect(sock, (struct sockaddr *) &server_address, sizeof(server_address));
	int condition=0;	
	
	puts("Select an option:");
	puts("1.Concatenate two strings");
	puts("2.Find the first occurrence of a character in a string");
	puts("3.Compare two strings");
	puts("4.Checks whether string is palindrome or not");
	puts("5.String Number Addition");
	puts("6.Exit");
	
	
        	puts("Client give input: ");
		gets(request);
		send(sock, request, sizeof(request), 0);
		if(strcmp(request,"1")==0)
		{
		puts("Enter string 1");
		gets(str1);
		send(sock, str1, sizeof(str1), 0);
		puts("Enter string 2");
		gets(str2);
		send(sock, str2, sizeof(str2), 0);
                recv(sock, &buf, sizeof(buf), 0);
		printf("\n %s \n", buf);
		
		}
		
		if(strcmp(request,"2")==0)
		{
		puts("Enter string: ");
		gets(str1);
		send(sock, str1, sizeof(str1), 0);
		puts("Enter character to be found the first occurence of");
		gets(c);
		send(sock, c, sizeof(c), 0);
                recv(sock, &buf, sizeof(buf), 0);
		printf("\n %s \n", buf);
		
		}
		
		if(strcmp(request,"3")==0)
		{
		puts("Enter string 1");
		gets(str1);
		send(sock, str1, sizeof(str1), 0);
		puts("Enter string 2");
		gets(str2);
		send(sock, str2, sizeof(str2), 0);
		recv(sock, &buf, sizeof(buf), 0);
		puts(buf);
		}
		
		
		if(strcmp(request,"4")==0)
		{
		puts("Enter string:");
		gets(str1);
		send(sock, str1, sizeof(str1), 0);
		recv(sock, &buf, sizeof(buf), 0);
		puts(buf);

		}
		
		
		
		if(strcmp(request,"5")==0)
		{
		puts("Enter number 1");
		gets(str1);
		send(sock, str1, sizeof(str1), 0);
		puts("Enter number 2");
		gets(str2);
		send(sock, str2, sizeof(str2), 0);
		puts("Number after sum:");
		recv(sock, &buf, sizeof(buf), 0);
		puts(buf);
		
		}
		
		//send(sock, request, sizeof(request), 0);
		if(strcmp(request,"6")==0)
		{
			condition=0;
			return;
			//break;
		}
		//else
		//{
		//	recv(sock, &buf, sizeof(buf), 0);
		//	if(!(strcmp(buf,"exit")))
		//	{
		//		condition=0;
		//	}
		//	printf("\n %s \n", buf);
		//}
		//puts("Received from server:");

		//printf("\n %s \n", buf);	
	
	close(sock);

	return 0;
}

