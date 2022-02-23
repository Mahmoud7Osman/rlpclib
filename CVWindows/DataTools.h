class DataTools{
	private:
		HANDLE  fh    = 0x00;
		size_t size   = 0x00;
		char*  data   = 0x00;
		int    tmp    = 0x00;
	public:
		int TouchFile(const char* path){
			fh=CreateFile(path, GENERIC_WRITE | GENERIC_READ, 0x00, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (fh == INVALID_HANDLE_VALUE){
				return 1;
			}
			CloseHandle(fh);
			return 0;
		}
		char* FileRead(const char* path){
			if (data != 0x00){
				free (data);
			    data=0x00;
			}
			fh=CreateFile(path, GENERIC_READ, 0x00, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if(fh == INVALID_HANDLE_VALUE){
				return NULL;
			}
			size=GetFileSize(fh, NULL);
			if (size == 0x00){
				CloseHandle(fh);
				return NULL;
			}
			data=(char*)malloc(size);
			if (data == NULL){
				CloseHandle(fh);
				return NULL;
			}
			tmp=ReadFile(fh,data,size, NULL, NULL);
			if (tmp == 0x00){
				free(data);
				CloseHandle(fh);
				return NULL;
			}
			CloseHandle(fh);
			return data;
		}
		int FileWrite(const char* path, char* buffer){
			fh=CreateFile(path, GENERIC_WRITE, 0x00, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (fh == INVALID_HANDLE_VALUE)
				return 1;
			tmp=WriteFile(fh, buffer, strlen(buffer), NULL, NULL);
			CloseHandle(fh);

			if (tmp==0x00)
				return 1;

			return 0;
		}
		int FileCorrupt(const char* path, size_t fsize=0x00){
			fh=CreateFile(path, GENERIC_WRITE, 0x00, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

			if (fh == INVALID_HANDLE_VALUE)
				return 1;

			size=GetFileSize(fh, NULL);

			if (fsize != 0x00 && fsize < size)
				size=fsize;

			srand(time(0));

			for (tmp=1; tmp<=size; tmp++){
				char byte = (char)(rand() % 255);
				WriteFile(fh, &byte, 1, NULL, NULL);
			}

			CloseHandle(fh);
			return 0;

		}

		int FileMove(const char* oldone, const char* newone){
			if (MoveFile(oldone, newone))
				return 0;
			return 1;
		}
		int FileDelete(const char* path){
			if (DeleteFile(path))
				return 0;
			return 1;
		}
		~DataTools(){
			if (data != 0x00)
				free(data);
		}
	
};
