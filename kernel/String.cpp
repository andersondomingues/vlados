#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
 
#include <String.h>

size_t VladOS::String::GetLength(const char* str){
	size_t len = 0;
	while (str[len])
		len++;
	return len;
};