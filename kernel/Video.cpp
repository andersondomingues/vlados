#include <Video.h>

uint8_t VladOS::Video::GetColor(enum vga_color fg, enum vga_color bg){
	return fg | bg << 4;
}

uint16_t VladOS::Video::GetEntry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}