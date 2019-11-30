#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
 
//kernel-specific headers
#include <Kernel.h>
#include <String.h>
#include <Terminal.h>
#include <Video.h>

VladOS::Terminal::Terminal(){

	this->terminal_row = 0;
	this->terminal_column = 0;
	this->terminal_color = VladOS::Video::GetColor(VGA_COLOR_LIGHT_GREY, VGA_COLOR_BLACK);
	this->terminal_buffer = (uint16_t*) 0xB8000;
	
	for (size_t y = 0; y < VladOS::Video::VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VladOS::Video::VGA_WIDTH; x++) {
			const size_t index = y * VladOS::Video::VGA_WIDTH + x;
			terminal_buffer[index] = VladOS::Video::GetEntry(' ', terminal_color);
		}
	}
}

VladOS::Terminal::~Terminal(){ /* wut */ }


void VladOS::Terminal::SetColor(uint8_t color){ 
	terminal_color = color;
}

void VladOS::Terminal::SetCursor(char c, uint8_t color, size_t x, size_t y){
	const size_t index = y * VladOS::Video::VGA_WIDTH + x;
	terminal_buffer[index] = VladOS::Video::GetEntry(c, color);
}

void VladOS::Terminal::Write(char c){

	this->SetCursor(c, terminal_color, terminal_column, terminal_row);
	if (++terminal_column == VladOS::Video::VGA_WIDTH) {
		terminal_column = 0;
		if (++terminal_row == VladOS::Video::VGA_HEIGHT)
			terminal_row = 0;
	}
}
 
void VladOS::Terminal::Write(const char* data, size_t size){

	for (size_t i = 0; i < size; i++)
		this->Write(data[i]);
}
