
printf "> Installing CVenom..."

export WINHOME=$(wslpath $(cmd.exe /C "echo %USERPROFILE%" | sed -e "s/\r$//g;s/\x0b//g"))

if [ ! -d "Compiler" ];then
	cd ../..
fi


mkdir $WINHOME/.CVenom &> /dev/null
cp * $WINHOME/.CVenom -r

printf " Done\n"
printf "> Installing cvg++ (NEED ROOT ACCESS)\n"

sudo cp $WINHOME/.CVenom/Compiler/Windows/cvg++ /bin
sudo cp $WINHOME/.CVenom/Setup/Windows/cvenom /bin
sudo chmod +x /bin/cvg++
sudo chmod +x /bin/cvenom
sudo chmod +x $WINHOME/.CVenom/PSBinaries/Linux/dr_RETi

if [ ! -f "/bin/cvg++" ];then
	printf "> ERROR: Compiler Not Installed, Cause: Permission Denied\n"
else
	printf "> Compiler Installed\n\n"
fi

printf "> CVenom MDK Was \033[0;92mSuccessfully\033[0;97m Installed For \033[0;92m$(whoami)\033[0;97m.\n"
sleep 1

#sudo apt install gcc-mingw-w64-x86-64 g++-mingw-w64-x86-64 gcc-mingw-w64 g++-mingw-w64 clang gcc g++ -y

printf "PROFESSIONAL MALWARE DEVELOPERS USES CVENOM - WANNA BE A PROFESSIONAL MALWARE DEVELOPER?\n\n"

printf "Warning: Please Do Not Use This MDK For Illegal Actions\n"
sleep 1
printf "Learn CVenom By Reading Documentations Right There: https://github.com/Mahmoud7Osman/CVenom#documentation\nLearn CVenom By Watching 4 Minutes Videos Right There: https://youtube.com/c/TheDoctorMLT\n"
