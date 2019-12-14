#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include <Memory.h>

#define MEM_SIZE 123456789
uint8_t _mem_vec[MEM_SIZE];

void* operator new(size_t size){
	return &(_mem_vec[size]);
}

void operator delete (void* ptr){
	*((int*)ptr) = 1;
}

void operator delete (void* ptr, size_t size){
	for(unsigned int i = 0; i < size; i++)
		*((int*)ptr) = 1;
}

void operator delete[](void* ptr){
	*((int*)ptr) = 1;
	return;
}

void* operator new[](size_t size){
	return (void*)&(_mem_vec[size]);
}

void operator delete[](void* ptr, size_t size){
	*((unsigned int*)ptr) = size;
}
