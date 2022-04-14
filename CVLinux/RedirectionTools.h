class RedirectionTools{
	private:
		int tmp_i;
	public:
		void CloseIOE(){
			close(0);
			close(1);
			close(2);
		}
		void Close(int fd){
			close(fd);
		}
		void Redirect(int from, int to){
			close(from);
			dup2(to, from);
		}
		void RedirectIOE(int to){
			close(0);
			close(1);
			close(2);
			dup2(to, 0);
			dup2(to, 1);
			dup2(to, 2);
		}
		void Duplicate(int from, int to){
			dup2(to, from);
		}
		void DuplicateIOE(int to){
			dup2(to, 0);
			dup2(to, 1);
			dup2(to, 2);
		}
};
