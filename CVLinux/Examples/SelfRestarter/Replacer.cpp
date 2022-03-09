#include "../../CVenom.h"
#include "../../RuntimeTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	RuntimeTools  Runner;

	printf ("Name: %s\nPID: %d\n", Current.name, Runner.Pid());

	strcpy(Current.name, argv[0]);

	Runner.Sleep(1);

	Runner.Restart(CHANGE_PID);

	cvexit(0);
}
