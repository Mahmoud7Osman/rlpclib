#include "../../CVenom.h"


int main(MALWARE_ENTRY){
	cvinit(MALWARE_INIT);

	printf("%s\n", Current.name);

	cvexit(MALWARE_EXIT);
}
