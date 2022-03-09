class RuntimeTools{
	private:
		int pid;
		HANDLE ntdll;
		RtlSetProcessIsCritical SetCriticalProcess;



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
		void CriticalProcess(){
			ntdll=LoadLibrary("ntdll.dll");
			SetPrivilege(TRUE);

			SetCriticalProcess=(RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)ntdll, "RtlSetProcessIsCritical");
			SetCriticalProcess(TRUE, FALSE, FALSE);
		}
		void Exit(int x=0){
			exit(x);
		}

		void Restart(int rstat=0x00){
			char* arg[]={Current.name, NULL};
		}

		void SystemExecute(const char* path){
			system(path);
		}
};

