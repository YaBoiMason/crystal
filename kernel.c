#include "stdlib.h"
#include "video.h"
#include "ata.c"
#include "types.h"

void kmain(void){
    init_vga(GREY, BLACK);
    clear();
    crystal_message("early_boot", "Crystal Version 0.1 Alpha");
    crystal_message("early_boot", "Initalizing GDT");
    crystal_message("early_boot", "Identifying disks");
    identify();
    exception("KERNEL EXECUTION END", "MAIN THREAD");
    asm volatile("sti");
}

void exception(char* reason, char* caller){
    crystal_message("Exception", caller);
    crystal_message("Exception", reason);
    while(1);
}

void crystal_message(char* stage, char* message){
    switch_vga_color(BRIGHT_GREEN, BLACK);
    printmulti("[crystal | ", stage);
    printf("] ");
    switch_vga_color(GREY, BLACK);
    printmulti(message, "\n");
}
