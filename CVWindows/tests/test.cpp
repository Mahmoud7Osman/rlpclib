#include "../CVenom.h"
#include "../DiskTools.h"
#include "../SystemTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	SystemTools		System;
	DiskTools		Disk;

	Disk.FolderCopy("ayre", "zabre");
	printf("%s\n", System.CUHome());

	cvexit(MALWARE_EXIT);
}
