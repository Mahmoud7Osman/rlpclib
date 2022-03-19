class UITools{
	private:
	public:
		void MessageUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_OK);
		}
		void AlertUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_OK | MB_ICONEXCLAMATION);
		}
		void WarnUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_OK | MB_ICONWARNING);
		}
		void InformateUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_OK | MB_ICONINFORMATION);
		}
		void AskUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_YESNOCANCEL | MB_ICONQUESTION);
		}
		void StopUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_OK | MB_ICONSTOP);
		}
		void ErrorUser(const char* message, const char* title){
			MessageBox(NULL, title, message, MB_OK | MB_ICONERROR);
		}
};
