class SystemTools{
	private:
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

};
