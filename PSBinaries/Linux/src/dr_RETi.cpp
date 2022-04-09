
/*
 *	This Program Will Return Random Values From urandom
 *	Random Values Are Stored in Different Executable's Sections To
 *      Change it's Hash Value (.bss, .text, .rodata, .data ...).
 */

#include <cstdio>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

int main(void){
	unsigned int bytes=99999999;

	int fd  = open(
                         "/dev/urandom",
                          O_RDONLY         );

	read(
               fd,
               &bytes,
               3              );

	printf(
                 "%u",
                 bytes        );
}
