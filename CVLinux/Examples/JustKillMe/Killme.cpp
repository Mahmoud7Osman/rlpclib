#include "../../CVenom.hpp"
#include "../../EvasionTools.h"
#include "../../RuntimeTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	EvasionTools  Malware;
	RuntimeTools  Program;

	Malware.HandleAllSignals( Malware.ChangePID );
	while (1){
		printf("Kill Me If You Can HAHAHAHAHAHAHA!!!\n");
		Program.Sleep(1);
	}
}
