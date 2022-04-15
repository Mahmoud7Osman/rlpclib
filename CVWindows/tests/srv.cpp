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

	Network.UDPServer("192.168.1.150", 4444);

	Network.UDPSetEndpoint("192.168.1.150", 4444);

	Network.UDPReceive(Data);

	Network.UDPSend(Data);

	Memory.FreeMemory(Data);

	cvexit(MALWARE_EXIT);
}
