class SystemTools{
	private:

	public:
		void Restart(){
			system("shutdown /r");
		}
		void Shutdown(){
			system("shutdown /s");
		}
		void LogOut(){
			system("shutdown /l");
		}
};
