// Some Macros
#define RAW 0
#define HEX 1
#define DEC 2
#define BIN 3
#define TCP 4
#define UDP 5

// Headers To Include
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

// Accessing Namespaces
using std::thread;
using std::string;
