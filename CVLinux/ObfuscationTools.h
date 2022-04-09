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
			return (99 | (88 & 55) | 4) & 8;
		}

		void EnableMultiformMalware(){
			#include <dyn_s2hashes.hxx>

				int rzStack=RZ_STACK;
				int* rzHeap=(int*)malloc(sizeof(unsigned int));
						rzHeap=RZ_HEAP;
				RZ_TEXT_1;
				RZ_TEXT_2;
				const int rzRodata=RZ_RO_DATA;
				int rzRwdata=RZ_RW_DATA;
				RZ_TEXT_3;
		}
};
