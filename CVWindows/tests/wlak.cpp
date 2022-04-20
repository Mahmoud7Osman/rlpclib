#include "../CVenom.h"
#include "../ObfuscationTools.h"


int main(int argc, char** argv)
{
	cvinit(argc, argv);

	ObfuscationTools	Obf;

	Obf.ObfuscateExecution();

	cvexit(0);
}
