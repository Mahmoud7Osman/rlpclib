#include <CVenom.h>
#include <ObfuscationTools.h>


int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	ObfuscationTools	Obf;
	Obf.EnableMultiformMalware();
	Obf.ObfuscateExecution();
	JunkCodeExecution;

	cvexit(MALWARE_EXIT);
}
