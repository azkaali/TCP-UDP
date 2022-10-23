#include <stdio.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <sys/types.h>
#include<string.h>
#include <netinet/in.h>

int main() {

	char server_message[256] = "Hi, Yes you have reached the server!";
	char buf[256];
	char alphabets[9][6]={"one","two","three","four","five","six","seven","eight","nine"};
	int num=0;
	char buf2[256];
	char buf3[256];
	char response[256]="Element not found";
	// create the server socket
	int server_socket;
	server_socket = socket(AF_INET, SOCK_STREAM, 0);

	
	// define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(3001);
	server_address.sin_addr.s_addr = INADDR_ANY;

	// bind the socket to our specified IP and port
	bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address));
	listen(server_socket, 5);
	int client_socket;
	//client_socket = accept(server_socket, NULL, NULL);
	
	
	int condition=1;
	int status = 0;
	pid_t new_pid;
	
	
	puts("Select an option:");
	puts("1.Concatenate two strings");
	puts("2.Find the first occurrence of a character in a string");
	puts("3.Compare two strings");
	puts("4.Checks whether string is palindrome or not");
	puts("5.String Number Addition");
	puts("6.Exit");
	// send the message
	while(condition==1)
	{
		client_socket = accept(server_socket, NULL, NULL);
		new_pid = fork();
		
		switch(new_pid)
		{
			case 0:
			{	//CHILD
			
				while(1){
				
				//STRCONCATENATE
				recv(client_socket, &buf, sizeof(buf), 0);
				
				if(buf[0]=='1')
				{
				
				puts("\nString 1 from Client:");
				recv(client_socket, &buf, sizeof(buf), 0);
				printf("\n %s \n", buf);
				recv(client_socket, &buf2, sizeof(buf2), 0);
				puts("\nString 2 from Client:");
				printf("\n %s \n", buf2);
				strcat(buf,buf2);
				puts("Server reply to the client");
				puts(buf);
				send(client_socket, buf, sizeof(buf), 0);
				}
				
				
				if(buf[0]=='2')
				{
				puts("\nclient2");
				recv(client_socket, &buf, sizeof(buf), 0);
				recv(client_socket, &buf2, sizeof(buf2), 0);
				int i;
				int num;
				for(i=0;buf[i]!=NULL;i++)
				{
					if(buf[i]==buf2[0])
					{
					    printf("the position is:%d",i);
					    num = i;
					   // break;
					}
				}
				//int num = i-1;
				char snum[5];
				sprintf(snum, "%d", num);
				char reply[256]="Found the string at position";
				strcat(reply," ");
				strcat(reply,snum);
				send(client_socket, reply, sizeof(reply), 0);
				
				}
				

				 
 				//STRCMP
				if(buf[0]=='3')
				{					

				recv(client_socket, &buf, sizeof(buf), 0);
				puts("\nString 1 from Client:");
				printf("\n %s \n", buf);
				recv(client_socket, &buf2, sizeof(buf2), 0);
				puts("\nString 2 from Client:");
				printf("\n %s \n", buf2);
				if(strcmp(buf,buf2)==0)
				{
				char server_msg[256]="Strings are equal";
				puts(server_msg);
				send(client_socket, server_msg, sizeof(server_msg), 0);
				}
				else if(strcmp(buf,buf2)>0){
				char server_msg[256]="String 1 is greater than string 2";
				puts(server_msg);
				send(client_socket, server_msg, sizeof(server_msg), 0);

				}
				else if(strcmp(buf,buf2)<0)
				{
				char server_msg[256]="String 2 is greater than string 1";
				puts(server_msg);
				send(client_socket, server_msg, sizeof(server_msg), 0);
				}
				
				}
				
				
				
				//PALINDROME
				if(buf[0]=='4')
				{
				recv(client_socket, &buf, sizeof(buf), 0);
				puts("\nString from Client:");
				printf("\n %s \n", buf);
				int l = 0;
    				int h = strlen(buf) - 1;
				while (h > l)
				{
				if (buf[l++] != buf[h--])
					{
					    char server_msg[256]="String is not a palindrome";
					    send(client_socket, server_msg, sizeof(server_msg), 0);	
					    //return;
					}
				}
				char server_msg[256]="String is a palindrome";
				send(client_socket, server_msg, sizeof(server_msg), 0);	
				printf("\n %s \n", buf);
				
				}
				
						
				//ADD NUMBERS
				

				if(buf[0]=='5')
				{
				char server_msg[256];
				puts("Number 1 from Client:");
				recv(client_socket, &buf, sizeof(buf), 0);
				puts(buf);
				recv(client_socket, &buf3, sizeof(buf), 0);
			   	puts("Number 2 from Client:");
			   	puts(buf3);
			   	
			   	/*int num1,num2,j=0;
			   	for (int i =0;i<9;i++)
				{ 
					if(strcmp(buf,alphabets[i])==0)
					{
					num1 = i+1;
					printf("\n%d\n",num1);
					}
				}
				for (int i =0;i<9;i++)
				{ 
					if(strcmp(buf3,alphabets[i])==0)
					{
					num2 = i+1;
					printf("\n%d\n",num2);
					}
				}
				
				int sum=num1+num2;
				printf("\n%d\n",sum);
				
				char summ[256];
				for (int i =0;i<9;i++)
				{ 
				puts("im in loop");
					if(sum==i)
					{
					puts("im in if");
					summ[i]=alphabets[i-1];
					printf("\n%d\n",summ[i]);
					}
				}
				*/
				
				if(strcmp(buf,"one")==0)
					{
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="three";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="four";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="five";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="six";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="seven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
					}
					
				if(strcmp(buf,"two")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="three";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="four";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="five";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="six";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="seven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					if(strcmp(buf,"three")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="four";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="five";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="six";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="seven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					
				if(strcmp(buf,"four")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="five";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="six";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="seven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					
					if(strcmp(buf,"five")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="six";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="seven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="fifteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					
					if(strcmp(buf,"six")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="seven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="fifteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="sixteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					if(strcmp(buf,"seven")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="eight";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="fifteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="sixteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="seventeen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					
					if(strcmp(buf,"two")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="nine";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="fifteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="sixteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="seventeen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="eighteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					
					if(strcmp(buf,"nine")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="ten";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="fifteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="sixteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="seventeen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="eighteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="ninteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}
					
					if(strcmp(buf,"ten")==0)
					{
						if(strcmp(buf3,"one")==0)
						{
						char sum[256]="eleven";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"two")==0)
						{
						char sum[256]="twelve";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"three")==0)
						{
						char sum[256]="thirteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"four")==0)
						{
						char sum[256]="forteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"five")==0)
						{
						char sum[256]="fifteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"six")==0)
						{
						char sum[256]="sixteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"seven")==0)
						{
						char sum[256]="seventeen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"eight")==0)
						{
						char sum[256]="eighteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"nine")==0)
						{
						char sum[256]="ninteen";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						if(strcmp(buf3,"ten")==0)
						{
						char sum[256]="twenty";
						send(client_socket, sum, sizeof(sum), 0);	
						}
						
						
					}


					
	
			    	}
			    	
				}
				exit(status);
			}
			
			case -1:
			{
				puts("ERROR");
			}
			
			default:
			{	//PARENT
				    	
			
				close(client_socket);
			}
		
		}
	}
	close(server_socket);
	
	return 0;
}

