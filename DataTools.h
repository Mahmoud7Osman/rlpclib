class DataTools{
	private:
		int		  fd;
		struct stat filestat;
	public:
		char* ReadFile(char* path){
			fd=open(path, O_RDONLY);
			if (fd<0)
				return NULL;
			fstat(fd, &filestat);
			static char data[filestat.st_size];
			read(fd, data, filestat.st_size);
			return data;
		}
};
