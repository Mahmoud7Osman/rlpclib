class RuntimeTools{
	private:
		int pid;
		HANDLE ntdll;
		RtlSetProcessIsCritical SetCriticalProcess;
		PROCESS_INFORMATION pi = { 0x00 };
		STARTUPINFOW si	       = { 0x00 };


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
		char* tmp=NULL;

	public:
		pid_t Pid(){
			return (pid=GetCurrentProcessId());
		}
		void Background(){
			return;
		}
		void Wait(int val){
			val*=1000;
			Sleep(val);
		}
		char* Pwd(){
			if (tmp){
				free(tmp);
				tmp=NULL;
			}
			tmp=(char*)malloc(PAMAX);
			GetCurrentDirectoryA(PAMAX, tmp);
			return  tmp;
		}
		void ChangeDir(const char* dir){
			SetCurrentDirectory(dir);
			return ;
		}
		void CriticalProcess(){
			ntdll=LoadLibrary("ntdll.dll");
			SetPrivilege(TRUE);

			SetCriticalProcess=(RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)ntdll, "RtlSetProcessIsCritical");
			SetCriticalProcess(TRUE, NULL, FALSE);
		}
		void Exit(int x=0){
			exit(x);
		}

		void Restart(int rstat=0x00){
			STARTUPINFO si;
    			PROCESS_INFORMATION pi;

			CreateProcess( NULL,   // No module name (use command line)
			        Current.name,        // Command line
			        NULL,           // Process handle not inheritable
			        NULL,           // Thread handle not inheritable
			        FALSE,          // Set handle inheritance to FALSE
			        0,              // No creation flags
			        NULL,           // Use parent's environment block
			        NULL,           // Use parent's starting directory 
			        &si,            // Pointer to STARTUPINFO structure
			        &pi );           // Pointer to PROCESS_INFORMATION structure
			cvexit(0);

		}

		void SystemExecute(const char* path){
			system(path);
		}

		~RuntimeTools(){
			if (tmp) free(tmp);
		}
};

