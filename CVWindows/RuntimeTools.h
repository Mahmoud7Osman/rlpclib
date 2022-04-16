class RuntimeTools{
	private:
		int pid;
		char* tmp=NULL;

	public:
		int ProcessID(){
			return (pid=GetCurrentProcessId());
		}
		void Background(){
			return;
		}
		void Wait(int val){
			val*=1000;
			Sleep(val);
		}
		char* CurrentDirectory(){
			if (tmp){
				free(tmp);
				tmp=NULL;
			}
			tmp=(char*)malloc(PAMAX);
			GetCurrentDirectoryA(PAMAX, tmp);
			return  tmp;
		}
		void ChangeDirectory(const char* dir){
			SetCurrentDirectory(dir);
			return ;
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

		void DetachThread(LPTHREAD_START_ROUTINE fct){
			CreateThread(NULL, 0, fct, NULL, 0, NULL);
		}

		~RuntimeTools(){
			if (tmp) free(tmp);
		}
};

