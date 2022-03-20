// Some Macros.
#define RAW 0x06
#define HEX 0x01
#define DEC 0x02
#define BIN 0x03
#define TCP 0x04
#define UDP 0x05

#define SUCCEED  0
#define PROBLEM  1
#define OK	 0
#define DONE     0
#define FAILED   1

#define FUNCTION_EVADE int x

#define MALWARE_ENTRY  int argc, char** argv
#define MALWARE_INIT   argc, argv

#define MALWARE_EXIT	0x00

#define PAMAX      4096

#define ON	0x01
#define OFF	0x00

#define KEEP_PID   0x00
#define CHANGE_PID 0x99

#define INPUT	   0x00
#define OUTPUT     0x01
#define ERROR      0x03


#define FILE_EXIST	 0x01
#define FILE_NOT_FOUND   0x00

// Headers To Include.
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <string>
#include <fstream>
#include <thread>

#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>

// Accessing Some Functions From Different Namespaces.
using		std::thread;
using		std::string;
using		   ::getpid;
// Custom Data Types And Typedefs
typedef void (*function)(int);

struct  c_malware_stats__t{
	char   	     name[PAMAX];
	char	     fakename[155];
	char*	     fakedescription = NULL;

	size_t       size;
};

// Global Data For Some CVEnome's Functionalities.
char** 			_argv__;
int    			_argc__;


struct c_malware_stats__t	Current;
struct c_malware_stats__t*	MALWARE;

// Some Functions For Initializing The Library.
void cvinit(int argc=0x00, char** argv=NULL){
	struct stat currentstat;

	_argv__=           argv;
	_argc__=           argc;
	MALWARE=&Current;

	stat(_argv__[0], &currentstat);
	readlink("/proc/self/exe", Current.name, PAMAX);
	Current.size=currentstat.st_size;

	return;
}
void SetMalwareMode(int mode){
	return;
}
void SetMalwareFakeService(const char* name){
	strncpy(Current.fakename, name, 155);
}

void SetMalwareFakeDescription(const char* desc){
	if (Current.fakedescription){
		free(Current.fakedescription);
		Current.fakedescription=NULL;
	}

	Current.fakedescription=(char*)malloc(strlen(desc));
	strcpy(Current.fakedescription, desc);
}

void cvexit(int x){
	if (Current.fakedescription)
		free(Current.fakedescription);
	exit(x);
}
