class EvasionTools{
	private:


	public:
		static void ChangePID(int _s=0){
			return;
		}
		void HandleAllSignals(function Handle){
			for (int tmp=1; tmp<=64; tmp++)
				signal(tmp, Handle);
		}
}
