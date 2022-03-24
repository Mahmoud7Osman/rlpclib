#include <stdio.h>
#include <windows.h>

int main(void){

ShellExecute( NULL, 
    "runas",  
    "cmd.exe",  
    NULL,     
    NULL,                        // default dir 
    SW_SHOWNORMAL  
); 
}
