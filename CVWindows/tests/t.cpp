#include "../CVenom.h"
#include "../RuntimeTools.h"

THREAD_ENTRY Fuck(THREAD){
	system("pause");
	printf("emak a7be");
}

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	RuntimeTools	Runner;
	Runner.DetachThread(Fuck);
	printf("w ayr");



	system("pause");

	cvexit(MALWARE_EXIT);
}
