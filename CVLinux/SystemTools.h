class SystemTools{
	private:
		char* data;
	public:
		void Restart(){
			system("reboot");
		}
		void Shutdown(){
			system("shutdown now");
		}
		void LogOut(){
			system("(xfce4-session-logout; gnome-session-quit) &> /dev/null");
		}
		int OSName(){
			return LINUX;
		}
		char* CUHome(){
			if ((data=getenv("HOME")) == NULL)
				data=getpwuid(getuid())->pw_dir;
			return data;
		}
};
