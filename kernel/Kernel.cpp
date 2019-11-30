#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
 
//kernel-specific headers
#include <Kernel.h>
#include <String.h>
#include <Terminal.h>
#include <Video.h>

uint8_t virtual_heap[2000];

//new operator
void * operator new( size_t size ){
	return virtual_heap;
}
void operator delete ( void *){
	return;
}

//code init
void kernel_main2(){
	VladOS::Terminal* m = new VladOS::Terminal();
	m->Write("Hello, kernel World!\n", 20);
//	VladOS::Terminal m;// = VladOS::Terminal();
//	m.Write("Hello, kernel World!\n", 20);
}
 

//make sure C++ won't change main name
extern "C"{
void kernel_main(void) 
{
	kernel_main2();
}
}
