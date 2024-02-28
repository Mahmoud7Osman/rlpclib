#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define MAX_ALLOC 524288000


struct bridge_t{
	int sfd; // Socket File Descriptor
	struct sockaddr_in address; // RLPC Server Address
	struct sockaddr_in client ; // RLPC Client Address
	socklen_t addrlen; // Address Length
};

void **pstore; // Array Of Heap Allocated Buffers
int16_t size;


struct bridge_t* init_bridge(char*, int, char*, int); // Creating The RLPC Bridge
char *function_call(struct bridge_t*, char*, char*); // Initiating a Function Call
char *fcall_receiver(struct bridge_t*); // Receiving A Function Call
void fcall_return(struct bridge_t*, void*, int32_t); // Returning a Function Call Returned Value To The Caller
void pstore_add(void*); // Adding Heap Allocated Addresses To `pstore` To Free it Later
void close_bridge(struct bridge_t*); // Closing The Bridge


struct bridge_t* init_bridge(char* ip, int port, char* eip, int eport){
	struct bridge_t* bridge = (struct bridge_t*)malloc(sizeof(struct bridge_t));

	size = 1;
	pstore = (void*) malloc(sizeof(void*));

	*pstore = bridge;
	
	bridge->sfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (bridge->sfd < 0)
		return NULL;
	
	bridge->address.sin_family = AF_INET;
	bridge->address.sin_port = htons(port);
	bridge->address.sin_addr.s_addr = inet_addr(ip);

	bridge->client.sin_family = AF_INET;
	bridge->client.sin_port = htons(eport);
	bridge->client.sin_addr.s_addr = inet_addr(eip);

	bridge->addrlen = sizeof(struct sockaddr);
	
	if (bind(bridge->sfd, (struct sockaddr*)&bridge->address, sizeof(struct sockaddr_in)) < 0 ){
		close(bridge->sfd);
		return NULL;
	}

	return bridge;
}

char* function_call(struct bridge_t* bridge, char* fname, char* args){
	if (!bridge || !args || !fname) return NULL;
	
	int32_t buffer_size,
	        fname_size = strlen(fname),
	        args_size = strlen(args);
	char* buffer;
	
	sendto(bridge->sfd, &fname_size, sizeof(int32_t), 0, (struct sockaddr*)&bridge->client, sizeof(struct sockaddr));
	sendto(bridge->sfd, fname, fname_size, 0, (struct sockaddr*)&bridge->client, sizeof(struct sockaddr));
	sendto(bridge->sfd, &args_size, sizeof(int32_t), 0, (struct sockaddr*)&bridge->client, sizeof(struct sockaddr));
	sendto(bridge->sfd, args, args_size, 0, (struct sockaddr*)&bridge->client, sizeof(struct sockaddr));
	recvfrom(bridge->sfd, &buffer_size, sizeof(int32_t), 0, (struct sockaddr*)&bridge->client, &bridge->addrlen);

	

	if (buffer_size > MAX_ALLOC)
		buffer_size = MAX_ALLOC;

	buffer = (char*) malloc(buffer_size);
	
	recvfrom(bridge->sfd, buffer, buffer_size, 0, (struct sockaddr*)&bridge->client, &bridge->addrlen);

	return buffer;
}

char* fcall_receiver(struct bridge_t* bridge){
	int32_t fname_size,
			args_size;
	char *fname, *args, *fcall;
			
	recvfrom(bridge->sfd, &fname_size, sizeof(int32_t),0,(struct sockaddr*)&bridge->client, &bridge->addrlen);
	fname = (char*) malloc(fname_size);
	recvfrom(bridge->sfd, fname, fname_size, 0, (struct sockaddr*)&bridge->client, &bridge->addrlen);
	recvfrom(bridge->sfd, &args_size, sizeof(int32_t),0,(struct sockaddr*)&bridge->client, &bridge->addrlen);
	args = (char*) malloc(args_size);
	recvfrom(bridge->sfd, args, args_size, 0, (struct sockaddr*)&bridge->client, &bridge->addrlen);

	fcall = (char*) malloc(fname_size + args_size + 1);
	memset(fcall, 0x00, fname_size + args_size + 1);

	strcat(fcall, fname);
	strcat(fcall, args);
	
	free(fname);
	free(args);
	
	return fcall;
}
void fcall_return(struct bridge_t *bridge, void* buffer, int32_t size){
	sendto(bridge->sfd, &size, sizeof(int32_t), 0, (struct sockaddr*)&bridge->client, sizeof(struct sockaddr));
	sendto(bridge->sfd, buffer, size, 0, (struct sockaddr*)&bridge->client, sizeof(struct sockaddr));
}

void pstore_add(void* ptr){
	pstore = realloc(pstore, ++size*sizeof(void*));
	*(pstore+size) = ptr;
}

void close_bridge(struct bridge_t* bridge){
	if (bridge == NULL) return;
	
	for (int ptr=1; ptr!=size;ptr++){
		free(pstore+size);
	}

	close(bridge->sfd);
	free(pstore);
	free(bridge);
}
