#ifndef _MEMORY_H
#define _MEMORY_H

void* operator new(size_t size); 
void operator delete (void* ptr);
 
void operator delete (void* ptr, size_t );
void operator delete[](void* ptr);

void* operator new[](size_t size);
void operator delete[](void *, size_t );

#endif /* _MEMORY_H */