class DataTools{
	private:
		int		  fd;
		char* 		data;
		struct stat filestat;

	public:
		int TouchFile(const char* path){
			fd=open(path, O_RDONLY | O_CREAT, S_IRUSR | S_IWUSR);
			if (fd < 0) return 1;
			close(fd);
			return 0;
		}
		char* ReadFile(const char* path){
			fd=open(path, O_RDONLY);
			if (fd < 0)
				return NULL;
			fstat(fd, &filestat);
			data=(char*)malloc(filestat.st_size);
			read(fd, data, filestat.st_size);
			close(fd);
			return data;
		}
		int  WriteFile(const char* path, const char* data){
			fd=open(path, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR);
			if (fd < 0)
				return 1;
			write(fd, data, strlen(data));
			close(fd);
			return 0;
		}

		~DataTools(){
			free(data);
		}
};
