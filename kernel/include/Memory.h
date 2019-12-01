#ifndef _MEMORY_H
#define _MEMORY_H

uint8_t virtual_heap[2000];


void operator delete ( void *){
	return;
}
 
void *operator new(size_t size)
{
    return virtual_heap; //malloc(size);
}
 
void *operator new[](size_t size)
{
    return virtual_heap; //malloc(size);
}
 
void operator delete(void *p)
{
    return;
}
 
void operator delete (void * , size_t ){
	return;
}
 
void operator delete[](void *p)
{
    return;
}

void operator delete[](void *, size_t ){
    return;
}

#endif /* _MEMORY_H */