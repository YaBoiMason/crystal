#include "video.h"
int printf(char* str){
    uint32 index = 0;
    while(str[index]){
        if(str[index] == '\n'){
            print_new_line();
        } else {
            print_char(str[index]);
        }
        index++;
    }
}

void *memcpy(char *dst, char *src, int n)
{
	char *p = dst;
	while (n--)
		*dst++ = *src++;
	return p;
}

void itoa(int num, char *number)
{
  int dgcount = digit_count(num);
  int index = dgcount - 1;
  char x;
  if(num == 0 && dgcount == 1){
    number[0] = '0';
    number[1] = '\0';
  }else{
    while(num != 0){
      x = num % 10;
      number[index] = x + '0';
      index--;
      num = num / 10;
    }
    number[dgcount] = '\0';
  }
}

int strlen(const char* str)
{
  int length = 0;
  while(str[length])
    length++;
  return length;
}

int printmulti(char* str, char* str2){
    printf(str);
    printf(str2);
}

void halt(){
    __asm__ __volatile__ ("hlt");
    while(1);
}

void clear(void){
    clear_vga_buffer(&vga_buffer, WHITE, BLACK);
}

int panic(char* reason){
    printmulti("KERNEL PANIC: ", reason);
    halt();
}

