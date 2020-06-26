
//Susmitha Shailesh
//I pledge my honor that I have abided by the Stevens Honor System.

/*
 * You are required to implement a function
 * 	int udp_msg_client(char *ip, int port, char * message, char *buf, int *buflen);
 *	
 *	In this function, you will need to create a socket for UDP communication with a remote server
 *		IP address of the server is specified in argument "ip"; hint regarding how to convert a string IP to an integer IP is given
 *		PORT number of the server is given in argument "port"
 *		The message to send to the server is specified in the argument "message"; length of the message equals to the size of the string in "message"
 *		After you send data to the server, you will need to receive a reply from the server, and you are required to keep that piece of data in the argument buffer "buf"; Original size of the buffer is specified in the integer pointed to by "buflen" (to get the size, you need to dereference the pointer); You can assume "buf" is large enough to keep the data from the server;
 *		Note that you have to init "buf" with all zeros before you read data from the server to "buf"
 *
 *		After you receive the data from the server, you need to update the integer in "buflen" with the number of bytes being received.
 *
 * 		In UDP communication, you do not need to connect to the server; instead, you can simply send data to the server and then wait for reply. Hints regarding this is given as comments below
 *
 *Note all the header files have been provided. You do not need to add more. But if you want, that's fine
 */


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<unistd.h>

#define SERVER "127.0.0.1"
#define BUFLEN 512	//Max length of buffer
#define PORT 1025	//The port on which to send data


//Please implement your code below
int udp_msg_client(char *ip, int port, char * message, char *buf, int *buflen){

	/*data structure to keep address of the server*/
	struct sockaddr_in si_other;

	/*create a socket for UDP communication */
	int s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);


	//si_other
	memset(&si_other, 0, sizeof(si_other)); //clear struct
	si_other.sin_family = AF_INET; //Internet/IP 
	si_other.sin_addr.s_addr = inet_addr(ip); //IP address
	si_other.sin_port = htons(port); //server port


	/*convert IP address and save the result in si_other*/
	inet_aton(ip, &si_other.sin_addr); 

	//do sendto
	//send data
	int messagelen = strlen(message);
	sendto(s, message, messagelen, 0, (struct sockaddr *)&si_other, (size_t)sizeof(si_other)); 

	//init buf with all zeros

	for(int i = 0; i < *buflen; i++){
		buf[i] = 0;
	}

	//do recvfrom
	//recieve data
	//update buflen with return value of recvfrom
	buflen = recvfrom(s, buf, *buflen, 0, (struct sockaddr *)&si_other, (size_t)sizeof(si_other));

	//close the socket of the client
	close(s);

	return 0;
}


int main(void)
{
	char buf[BUFLEN];
	int bufsz = BUFLEN;

	printf("Test case 1:\n");
	printf("The data you send is ==== %s\n", "First test case for udp server");

	udp_msg_client(SERVER, PORT, "First test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "First test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");

	bufsz = BUFLEN;
	printf("Test case 2:\n");
	printf("The data you send is ==== %s\n", "Second test case for udp server");

	udp_msg_client(SERVER, PORT, "Second test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Second test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");

	bufsz = BUFLEN;
	printf("Test case 3:\n");
	printf("The data you send is ==== %s\n", "Third test case for udp server");

	udp_msg_client(SERVER, PORT, "Third test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Third test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");


	bufsz = BUFLEN;
	printf("Test case 4:\n");
	printf("The data you send is ==== %s\n", "Fourth test case for udp server");

	udp_msg_client(SERVER, PORT, "Fourth test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Fourth test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");


	bufsz = BUFLEN;
	printf("Test case 5:\n");
	printf("The data you send is ==== %s\n", "Fifth test case for udp server");

	udp_msg_client(SERVER, PORT, "Fifth test case for udp server", buf, &bufsz);
	printf("The data received is ==== %s\n", buf);

	if(strcmp(buf, "Fifth test case for udp server") == 0)
		printf("Result: ==== passed\n\n");
	else 
		printf("Result: ==== failed\n\n");



	udp_msg_client(SERVER, PORT, "exit", buf, &bufsz);

	return 0;
}
