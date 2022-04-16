#include "../CVenom.h"
#include "../RuntimeTools.h"

DWORD WINAPI Fuck(LPVOID ayre){
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
