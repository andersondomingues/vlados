#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
 
//kernel-specific headers
#include <Kernel.h>
#include <String.h>
#include <Terminal.h>
#include <Video.h>
#include <Memory.h>

//code init
void kernel_main2(){
	
	VladOS::Terminal* m = new VladOS::Terminal();
	m->Write("Hello, kernel World!\n", 20);	
}
 

//make sure C++ won't change main name
extern "C"{
void kernel_main(void) 
{
	kernel_main2();
}
}
