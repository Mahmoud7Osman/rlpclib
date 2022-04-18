class DiskTools{
	private:
		int		     fd=0;
		char* 		data=0x00;
		struct stat      filestat;

	public:
		int FileCreate(const char* path){
			fd=open(path, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
			if (fd < 0)
				return 1;
			close(fd);
			return 0;
		}
		char* FileRead(const char* path){
			if (data){
				free(data);
				data=0x00;
			}
			fd=open(path, O_RDONLY);
			if (fd < 0)
				return NULL;
			fstat(fd, &filestat);
			data=(char*)malloc(filestat.st_size);
			read(fd, data, filestat.st_size);
			close(fd);
			return data;
		}
		int FileWrite(const char* path, const char* data){
			fd=open(path, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
			if (fd < 0)
				return 1;
			write(fd, data, strlen(data));
			close(fd);
			return 0;
		}
		int FileCorrupt(const char* path, long int size=0){
			fd=open(path, O_WRONLY);
			if (fd < 0)
				return 1;
			fstat(fd, &filestat);
			if (size != 0x00 && size < filestat.st_size)
				filestat.st_size=size;

			srand(time(0));

			for (int tmp=0; tmp<=filestat.st_size; tmp++){
				char byte=(char)( rand() % 255 );
				write(fd, &byte, 1);
			}
			close(fd);
			return 0;
		}

		int FileMove(const char* Old, const char* New){
			if (rename(Old, New))
				return 1;
			return 0;
		}

                int FileRename(const char* Old, const char* New){
                        if (rename(Old, New))
                                return 1;
                        return 0;
                }
               	int FolderMove(const char* Old, const char* New){
                        if (rename(Old, New))
                                return 1;
                        return 0;
                }
                int FolderRename(const char* Old, const char* New){
                        if (rename(Old, New))
                                return 1;
                        return 0;
                }
		int FolderCreate(const char* path){
			if (mkdir(path, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH) ==-1)
				return 1;
			return 0;
		}

                int FolderDelete(const char* path){
                        if (remove(path))
                                return 1;
                        return 0;
                }

		int FileDelete(const char* path){
			if (remove(path))
				return 1;
			return 0;
		}

		int FileExists(const char* path){
			if( access( path, F_OK ) == 0 ) {
				return 1;
			}
			else {
				return 0;
			}
		}

		int FileCopy(const char* Old, const char* New){
			fd=open(Old, O_RDONLY);
			if (fd == -1)
				return 1;
			fstat(fd, &filestat);
			data=(char*)malloc(filestat.st_size);
			read(fd, data, filestat.st_size);

			close(fd);
			fd=open(New, O_WRONLY | O_TRUNC | O_CREAT, S_IRWXU);
			if (fd == -1)
				return 1;
			write(fd, data, filestat.st_size);
			close(fd);

			return 0;
		}
		int FolderCopy(const char* oldone, const char* newone){
			char cmd[sizeof(oldone) + sizeof(newone) + 8]="cp ";

			strcat(cmd, oldone);
			strcat(cmd, " ");
			strcat(cmd, newone);
			strcat(cmd, " ");
			strcat(cmd, "-r");

			system(cmd);
			return 0;
		}
		int FolderExists(const char* path){
			DIR* dir = opendir("mydir");
			if (dir) {
			    closedir(dir);
			    return FILE_EXIST;
			} else {
				return FILE_NOT_FOUND;
			}
		}

		~DiskTools(){
			if (data!=0x00)
				free(data);
		}
};
