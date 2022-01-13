class EvasionTools{
	private:
		
	public:
		void ChangePID(void){
                        pid=fork();
                        sid=setsid();
                        if (pid<0)exit(1);
                        if (pid>0)exit(0);
                        if (sid<0)exit(0);
                        if (sid>0);
		}
}
