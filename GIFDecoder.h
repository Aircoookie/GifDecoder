#ifndef _GIFDECODER_H_
#define _GIFDECODER_H_

#include <stdint.h>

typedef void (*callback)(void);
typedef void (*pixel_callback)(int16_t x, int16_t y, uint8_t red, uint8_t green, uint8_t blue);
typedef int (*get_bytes_callback)(void * buffer, int numberOfBytes);
typedef void* (*get_buffer_callback)(void);

void setScreenClearCallback(callback f);
void setUpdateScreenCallback(callback f);
void setDrawPixelCallback(pixel_callback f);
void setStartDrawingCallback(callback f);

// public
int enumerateGIFFiles(const char *directoryName, boolean displayFilenames);
void getGIFFilenameByIndex(const char *directoryName, int index, char *pnBuffer);
void chooseRandomGIFFilename(const char *directoryName, char *pnBuffer);
int processGIFFile(const char * pathname);

// private
 typedef struct rgb_24 {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} rgb_24;


void lzw_decode_init(int csize, get_bytes_callback f);
int lzw_decode(byte *buf, int len, byte *bufend);
void decompressAndDisplayFrame(unsigned long filePositionAfter);
void lzw_setTempBuffer(byte * tempBuffer);

#endif
