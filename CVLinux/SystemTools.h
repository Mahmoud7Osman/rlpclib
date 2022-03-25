class SystemTools{
	private:
	public:
		void Restart(){
			sync();
			reboot(RB_AUTOBOOT);
		}
		void Shutdown(){
			sync();
			system("shutdown now");
		}
}
