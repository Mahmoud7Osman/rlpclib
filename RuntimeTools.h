class EvasionTools{
	private:
		int pid;
		int sid;

	public:
		void Background(){
			pid=fork();
			sid=setsid();
			if (pid<0)exit(1);
			if (pid>0)exit(0);
			if (sid<0)exit(0);
			if (sid>0);
		}
		void Exit(int v=0){
			exit(v);
		}
};
