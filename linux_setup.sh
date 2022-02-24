#!/bin/bash

printf "> Installing CVenom..."

mkdir ~/.CVenom &> /dev/null
cp * ~/.CVenom -r

printf " Done\n"
printf "> Installing cvg++ (NEED ROOT ACCESS)\n"

sudo cp ~/.CVenom/Compiler/cvg++ /bin

if [ ! -f "/bin/cvg++" ];then
	printf "ERROR: Compiler Not Installed, Cause: Permission Denied\n"
else printf "> Compiler Installed\n\n"
fi

printf "CVenom MDK Was \033[0;92mSuccessfully\033[0;97m Installed.\n"
