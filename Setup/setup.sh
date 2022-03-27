#!/bin/bash

printf "> Installing CVenom..."

if [ ! -d "Compiler" ];
	cd ..
fi


mkdir ~/.CVenom &> /dev/null
cp * ~/.CVenom -r

printf " Done\n"
printf "> Installing cvg++ (NEED ROOT ACCESS)\n"

sudo cp ~/.CVenom/Compiler/cvg++ /bin
sudo cp Setup/cvenom /bin/cvenom
sudo chmod +x /bin/cvg++
sudo chmod +x /bin/cvenom

if [ ! -f "/bin/cvg++" ];then
	printf "> ERROR: Compiler Not Installed, Cause: Permission Denied\n"
else
	printf "> Compiler Installed\n\n"
fi

printf "> CVenom MDK Was \033[0;92mSuccessfully\033[0;97m Installed For \033[0;92m$(whoami)\033[0;97m.\n"
sleep 1
printf "> Preparing To Install Windows And Linux Compilers And Stripers...\n"
sleep 1
printf "> Press Enter To Start The Installation ! "
read
printf "> Starting The Installation Please Do Not Interrupt It Will Take a While To Finish\n"
sleep 1
sudo apt install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 gcc-mingw-w64 g++-mingw-w64 clang gcc g++ -y
printf "> Compilers And Stripers Successfully Installed\n"
sleep 5
clear
printf "PROFESSIONAL MALWARE DEVELOPERS USES CVENOM - WANNA BE A PROFESSIONAL MALWARE DEVELOPER?\n\n"

printf "Warning: Please Do Not Use This MDK For Illegal Actions, We Are Not Responsible\n"
sleep 1
printf "Learn CVenom By Reading Documentations Right There: https://github.com/Mahmoud7Osman/CVenom#documentation\nLearn CVenom By Watching 4 Minutes Videos Right There: https://youtube.com/c/TheDoctorMLT\n"

