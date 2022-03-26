class SystemTools{
	private:

	public:
		void Restart(){
			system("shutdown /r /f /t 0");
		}
		void Shutdown(){
			system("shutdown /s /f /t 0");
		}
		void LogOut(){
			system("shutdown /l");
		}
		int OSName(){
			return WINDOWS;
		}
};
