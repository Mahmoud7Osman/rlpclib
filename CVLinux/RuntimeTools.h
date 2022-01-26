class RuntimeTools{
	private:
		int pid;
		int sid;

	public:
		void Background(void){
			pid=fork();
			sid=setsid();
			if (pid<0)exit(1);
			if (pid>0)exit(0);
			if (sid<0)exit(0);
			if (sid>0);
		}
		char* Path(){
			return    _argv__[0];
		}
		pid_t Pid(){
			return      getpid();
		}
		void Sleep(int val){
			sleep(val);
		}
		void Exit(int v=0){
			exit(v);
		}
};
