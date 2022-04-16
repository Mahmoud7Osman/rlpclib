#include "../CVenom.h"
#include "../RuntimeTools.h"


THREAD_ENTRY Fuck(THREAD){
	printf("Emak A7be A7be");
	system("thunar");
}

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	RuntimeTools	Runner;

	Runner.DetachThread(Fuck);

	printf("5ara\n");

	cvexit(MALWARE_EXIT);
}
