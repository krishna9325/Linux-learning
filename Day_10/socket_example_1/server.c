#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/socket.h>
#include<linux/in.h>
#include<unistd.h>

typedef struct {
	int sock;
	struct sockaddr address;
	int addr_len;
} connection_t;

void * process(void *ptr) {
	char *buffer;
	int len;
	connection_t *conn;
	long addr = 0;
	if(!ptr) pthread_exit(0);
	
	conn = (connection_t *) ptr;
	
	/*read len of messgae */
	read(conn->sock, &len, sizeof(int));
	
	if(len > 0) {
		addr = (long)((struct sockaddr_in *)& conn -> address) -> sin_addr.s_addr;
		buffer = (char *) malloc((len + 1) * sizeof(char));
		
		buffer[len] = 0;
		/* read the message */
		read(conn->sock, buffer, len);
		
		/* print message */
		
		printf("%d.%d.%d.%d : %s\n", 
			(int) ((addr      ) & 0xff), 
			(int) ((addr >> 8 ) & 0xff),
			(int) ((addr >> 16) & 0xff),
			(int) ((addr >> 24) & 0xff),
			buffer);
		
		free(buffer);
	}
	
	/* close socket and clean up */
	
	close(conn -> sock);
	free(conn);
	pthread_exit(0);
	
}


int main(int argc, char **argv) {

	int sock = -1;
	struct sockaddr_in address;
	int port;
	
	connection_t *connection;
	pthread_t thread;
	
	/*check for comment line arguments */
	if(argc != 2) {
		fprintf(stderr, "usage: %s port \n", argv[0]);
		return -1;
	}
	
	/* obtain port number */
	if(sscanf(argv[1], "%d", &port) <= 0) {
		fprintf(stderr, "%s error: wrong parameter: port \n", argv[0]);
		return -2;
		
	}
	
	/* create a socket */
	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(sock <= 0) {
		fprintf(stderr, "%s: error: cannot create socket \n", argv[0]);
		return -3;
		
	} 
	
	/* bind the socket */
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(port);
	
	//forecfully attaching the socket to port 8080
	if(bind(sock, (struct sockaddr*)&address, sizeof(struct sockaddr_in)) < 0) {
		fprintf(stderr, "%s: error: cannot bind socket to port %d\n", argv[0], port);
		return -4;
	}
	
	if(listen(sock, 5) < 0) {
		fprintf(stderr, "%s: error: cannot listen on port %d\n", argv[0], port);
		return -5;
	}
	
	printf("%s: Ready and listening", argv[0]);
	
	while(1) {
		/* accept the connection */
		connection = (connection_t *) malloc(sizeof(connection_t));
		connection->sock = accept(sock, &connection-> address, &connection->addr_len);
		if(connection -> sock <= 0) {
			free(connection);
		}
		
		else {
			pthread_create(&thread, 0, process, (void *) connection);
			pthread_detach(thread);
		}
			
	}
	
	return 0;
}
