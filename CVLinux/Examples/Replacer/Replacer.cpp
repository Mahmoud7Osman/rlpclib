#include "../../CVenom.h"
#include "../../RuntimeTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	RuntimeTools  Runner;

	printf ("Name: %s\nPID: %d\n", Current.name, Runner.Pid());
	Runner.Restart(CHANGE_PID);
	printf ("PID: %d\n", Runner.Pid());

	cvexit(0);
}
