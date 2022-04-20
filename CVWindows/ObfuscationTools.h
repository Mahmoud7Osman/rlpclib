class ObfuscationTools{
	private:
			#include <dyn_s2hashes.hxx>

		int* rzHeap=NULL;

		int aa=1, bb=2, cc=3, dd=4, ee=5, ff=6, rr;

		void Do4(){
			char *b=(char*)malloc(600000000);
			free(b);
			char *c=(char*)malloc(100000000);
			free(c);
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*10;
			return;
		}
		void Do3(){
			Do4();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*10;

			return;
		}
		void Do2(){
			Do3();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*10;

			return;
		}
		void Do1(){
			Do2();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*10;
			Do3();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*10;
			Do4();
		}

		void AntiWarnCall(int a, int b, int c, int d, int e){
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*10;
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*11;
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*12;
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*13;

			return ;
		}
	public:
		int ObfuscateExecution(){
			Do1();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*6;
			Do2();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*7;
			Do3();
			rr = aa/aa+bb/cc+aa/cc+ff-ff*2+RZI1+RZI1*2-RZI1*3/RZI2+aa%RZI3%RZI4-aa*5%5+RZI5/(RZI1+RZI2+RZI3+RZI4%RZI5)*8;
			Do4();
			return 0;
		}

		void EnableMultiformMalware(){
/*			if (rzHeap != NULL)
				free(rzHeap);


				int rzStack=RZ_STACK;
				rzHeap=(int*)malloc(sizeof(unsigned int));
						*rzHeap=RZ_HEAP;
				RZ_TEXT_1;
				RZ_TEXT_2;
				RZ_TEXT_3;

				int something = RZ_RW_DATA;
				int something2= RZ_STACK;

				const int rzRodata=RZ_RO_DATA;
				int rzRwdata=RZ_RW_DATA;

				AntiWarnCall(rzStack, *rzHeap, rzRodata, rzRwdata, Rz3);

*/				return;
		}
};
