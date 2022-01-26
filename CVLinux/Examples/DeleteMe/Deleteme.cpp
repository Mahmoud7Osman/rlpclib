// This is Super easy hahaha.

#include "../../CVenom.hpp"
#include "../../EvasionTools.h"

int main(int argc, char** argv){
	cvinit(argc, argv);

	EvasionTools Evador;

	if (Evador.MoveMalware("/tmp/.deleteme"))
		perror("Evador.MoveMalwar(): ");

	cvexit(0);
}
