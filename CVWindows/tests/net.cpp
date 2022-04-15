#include "../CVenom.h"
#include "../NetworkTools.h"
#include "../MemoryTools.h"
#include "../KeyboardTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);


	NetworkTools	Network;
	MemoryTools	Memory;
	KeyboardTools	Keyboard;

	MemoryBuffer Data=Memory.HeapAllocate(100);

	printf("%d\n", ERROR);
	if (Network.UDPSetEndpoint("192.168.1.150", 4445) == 1)
		printf("errororo\n");

	Network.UDPSend("asd");
	Network.UDPReceive(Data);

	printf("%s\n", Data.data);
	Memory.FreeMemory(Data);

	cvexit(MALWARE_EXIT);
}
