#include "../CVenom.h"
#include "../ObfuscationTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	ObfuscationTools	Obfuscator;
	Obfuscator.ObfuscateExecution();
	printf("%d\n", __DATE__);
	cvexit(MALWARE_EXIT);
}
