class RuntimeTools{
	private:
		int pid;
		int sid;

		char* tmp=NULL;
	public:
		void Background(void){
			pid=fork();
			sid=setsid();
			if (pid<0)exit(1);
			if (pid>0)exit(0);
			if (sid<0)exit(0);
			if (sid>0);
		}
		char* Pwd(){
			if (tmp)
				free(tmp);
			tmp=(char*)malloc(PAMAX);
			return getcwd(tmp, PAMAX);
		}
		int ChangeDir(const char* path){
			if (chdir(path))
				return 1;
			return 0;
		}
		void Sleep(int val){
			sleep(val);
		}
		void Exit(int v=0){
			exit(v);
		}
		~RuntimeTools(){
			if (tmp)
				free(tmp);
		}
};
