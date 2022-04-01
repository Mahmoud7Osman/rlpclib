#include "../CVenom.h"
#include "../NetworkTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	NetworkTools	Router;

	printf("%s\n", Router.GetHostByName("127.0.0.1"));

	cvexit(MALWARE_EXIT);
}
