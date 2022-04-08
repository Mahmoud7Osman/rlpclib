class ObfuscationTools{
	private:
		void Do4(){
			return;
		}
		void Do3(){
			Do4();
			return;
		}
		void Do2(){
			Do3();
			return;
		}
		void Do1(){
			Do2();
			Do3();
			Do4();
		}

	public:
		int ObfuscateExecution(){
			Do1();
			return 0;
		}

};
