#ifndef _TERMINAL_H
#define _TERMINAL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
 
//kernel-specific headers
#include <Kernel.h>
#include <String.h>
#include <Terminal.h>
#include <Video.h>

namespace VladOS{

class Terminal{

private:
	size_t terminal_row;
	size_t terminal_column;
	uint8_t terminal_color;
	uint16_t* terminal_buffer;

public:
	Terminal();
	~Terminal();
	void SetColor(uint8_t color);
	void SetCursor(char c, uint8_t color, size_t x, size_t y);
 	void Write(char c);
 	void Write(const char* s, size_t size);
};

}

#endif /* _TERMINAL_H */