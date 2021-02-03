#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.c"
#include "video.c"
#define NULL 0

int printf(char* str);
int printmulti(char* str, char* str2);
int panic(char* reason);
int strlen(const char* str);
void clear(void);
void halt();
void itoa(int num, char* number);
void *memcpy(char *dst, char *src, int n);

#endif 


