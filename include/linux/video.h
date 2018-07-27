#ifndef _VIDEO_H
#define _VIDEO_H

#define VGA_VIDEO_COLUMMS 80
#define VGA_VIDEO_LINES 25
#define VGA_VIDEO_CHARACTER_BYTE 2
#define VGA_VIDIO_MEMORY_ADDRESS 0xb8000 //General-Purpose I/O(256bytes 8000~80FF) in Memory-mapped I/O

unsigned int VideoTextNumber = 0;
unsigned int VideoNumber = 0;

void vga_cls(int TextColor)
{
		volatile char *VideoMemory = (volatile char *)VGA_VIDIO_MEMORY_ADDRESS;
	    while(VideoNumber < VGA_VIDEO_COLUMMS * VGA_VIDEO_LINES * VGA_VIDEO_CHARACTER_BYTE) {
		        VideoMemory[VideoNumber] = ' ';
				//VGA Text mode color(0x0F is set background to black and text color white)
		        VideoMemory[VideoNumber + 1] = TextColor; 		
		        VideoNumber = VideoNumber + 2;
	    }
		VideoNumber = 0;
	return;
}

void vga_write(volatile char *VideoText, int TextColor)
{
		volatile char *VideoMemory = (volatile char *)VGA_VIDIO_MEMORY_ADDRESS;
	    while(VideoText[VideoTextNumber] != '\0') {
		        VideoMemory[VideoNumber] = VideoText[VideoTextNumber];
		        VideoMemory[VideoNumber + 1] = TextColor;
		        ++VideoTextNumber;
		        VideoNumber = VideoNumber + 2;
	    }
		VideoTextNumber = 0;

	return;
}
#endif