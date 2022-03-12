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
		pid_t Pid(){
			return getpid();
		}
		char* Pwd(){
			if (tmp){
				free(tmp);
				tmp=NULL;
			}
			tmp=(char*)malloc(PAMAX);
			return getcwd(tmp, PAMAX);
		}
		int ChangeDir(const char* path){
			if (chdir(path))
				return 1;
			return 0;
		}
		void Wait(int val){
			sleep(val);
		}
		void CriticalProcess(){
			return;
		}
		void Exit(int v=0){
			exit(v);
		}

		void Restart(int rstat=0x00){
			char* arg[]={Current.name, NULL};
			if (tmp)
				free(tmp);
			if (rstat == KEEP_PID){
				execve(Current.name, arg, NULL);
			}

			else{
				Background();
				execve(Current.name, arg, NULL);
			}
		}

		void SystemExecute(const char* path){
			system(path);
		}

		~RuntimeTools(){
			if (tmp)
				free(tmp);
		}
};
