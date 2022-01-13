// Some Macros.
#define RAW 0
#define HEX 1
#define DEC 2
#define BIN 3
#define TCP 4
#define UDP 5

// Headers To Include.
#include <cstring>
#include <string>
#include <fstream>
#include <thread>

#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <netdb.h>
#include <cstdlib>
#include <unistd.h>
#include <errno.h>

// Accessing Some Functions From Different Namespaces.
using		std::thread;
using		std::string;
using		   ::getpid;

// Global Data For Some CVEnome's Functionalities.
char** 		_argv__;
int    		_argc__;

// Some Functions For Initializing The Library.
void cvinit(int argc, char** argv){
	_argv__=argv;
	_argc__=argc;

	return;
}
