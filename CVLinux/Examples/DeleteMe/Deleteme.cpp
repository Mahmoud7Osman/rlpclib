// This is Super easy hahaha.

#include "../../CVenom.h"
#include "../../EvasionTools.h"
#include "../../RuntimeTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	EvasionTools Evador;
//	RuntimeTools Runner;

	if (Evador.MoveMalware("/tmp/.deleteme"))
		perror("Evador.MoveMalwar(): ");
//	printf("%s\n", Runner.Pwd());
//	Runner.ChangeDir("/tmp/");
//	printf("%s\n", Runner.Pwd());
	cvexit(0);
}
