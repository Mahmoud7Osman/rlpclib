class IOTools{
	private:
		int tmp_i;
	public:
		void CloseIOE(){
			for (tmp_i=0; tmp_i<3; tmp_i++)
				close(tmp_i);
		}

		void Close(int fd){
			close(fd);
		}
		void Redirect(int from, int to){
			dup2(to, from);
		}
		void RedirectIOE(int to){
			dup2(to, 0);
			dup2(to, 1);
			dup2(to, 2);
		}
};
