// Some Macros.
#define RAW 0
#define HEX 1
#define DEC 2
#define BIN 3
#define TCP 4
#define UDP 5
#define PAMAX 4096

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
	char   	     name[256];
	char*        path;

	size_t       size;
	pid_t	     pid;
};

// Global Data For Some CVEnome's Functionalities.
char** 			_argv__;
int    			_argc__;


struct c_malware_stats__t	Current;

// Some Functions For Initializing The Library.
void cvinit(int argc=0x00, char** argv=NULL){
	struct stat currentstat;

	_argv__=           argv;
	_argc__=           argc;
	Current.path=(char*)malloc(PAMAX);

	stat(_argv__[0], &currentstat);
	strncpy(Current.name, _argv__[0], 256);
	Current.size=currentstat.st_size;
	Current.path=getcwd(Current.path, 4000);
	Current.pid=getpid();
	return;
}
void cvexit(int x){
	if (Current.path)
		free(Current.path);
	exit(x);
}
