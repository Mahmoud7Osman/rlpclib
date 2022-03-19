#include "../../CVenom.h"
#include "../../UITools.h"

UITools		x;

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);
	x.AskUser("Are YOU", "Bitch?");

	x.MessageUser("s", "s");
	x.AlertUser("Emak","a7be");
	x.ErrorUser("But", "Your Mother is a bitch!");
	x.Notification("Bitch", "Detected");
	cvexit(MALWARE_EXIT);
}
