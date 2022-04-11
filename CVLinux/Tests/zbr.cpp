#include "../CVenom.h"
#include "../SystemTools.h"

int main( MALWARE_ENTRY ){
	cvinit(MALWARE_INIT);

	SystemTools	System;
	printf("%s\n", System.CUHome());

	cvexit(MALWARE_EXIT);
}
