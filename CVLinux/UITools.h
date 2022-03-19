class UITools{
	private:
		const char* command = "zenity  --WIND  --title=TITLE  --text=TEXT  --height=150  --width=300";
		char* tmp;
		char* newcmd;

		char* replace(const char *str, const char *src, const char *trg){
			int tmp1=strlen(str), tmp2=strlen(src), tmp3=strlen(trg);

		    	int newsize=tmp1-tmp2+tmp3;
		    	char *newstr=(char*)malloc(newsize);

		    	for (int i=0; i<=tmp1; i++){
		        	if (strncmp((str+i), src, strlen(src))==0){
			           	strncat(newstr, str, i);
			           	strncat(newstr, trg, tmp3);
			           	strcat (newstr, str+i+tmp2);
		        }
		}
		    return newstr;
		}

	public:
		void MessageUser(const char* title, const char* message){
			newcmd=replace(command, "WIND", "info");
			tmp=newcmd;
			newcmd=replace(tmp, "TITLE", title);

			tmp=newcmd;

			newcmd=replace(tmp, "TEXT", message);

			system(newcmd);
			printf("\n*%s*\n", newcmd);
			free(newcmd);
			free(tmp);
		}
                void InformateUser(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "info");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }
                void WarnUser(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "warning");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }
                void ErrorUser(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "error");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }
                void StopUser(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "error");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }
                void AskUser(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "question");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }
                void AlertUser(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "warning");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }
                void Notification(const char* title, const char* message){
                        newcmd=replace(command, "WIND", "notification");
                        tmp=newcmd;
                        newcmd=replace(tmp, "TITLE", title);

                        tmp=newcmd;

                        newcmd=replace(tmp, "TEXT", message);

                        system(newcmd);
                        free(newcmd);

                }


};
