
unsigned char port_byte_in (unsigned short port) {
    unsigned char result;
    __asm__("in %%dx, %%al" : "=a" (result) : "d" (port));
    return result;
}
void port_byte_ina(unsigned short port, void* target, int lenght) {
    unsigned char data;
    unsigned char* tar = (unsigned char*)target;
    for (int i = 0; i < lenght; i++)
    {
        data = port_byte_in(port);
        tar[i] = data;
    }
}
void port_byte_out (unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned short port_word_in (unsigned short port) {
    unsigned short result;
    __asm__("inw %%dx, %%ax" : "=a" (result) : "d" (port));
    return result;
}
void port_word_ina(unsigned short port, void* target, int lenght) {
    unsigned short data;
    unsigned short* tar = (unsigned short*) target;
    for (int i = 0; i < lenght; i++)
    {
        data = port_word_in(port);
        tar[i] = data;
    }
}
void port_word_out (unsigned short port, unsigned short data) {
    __asm__("outw %%ax, %%dx" : : "a" (data), "d" (port));
}
void port_word_outa(unsigned short port, void* source, int lenght) {
    unsigned short* tar = (unsigned short*) source;
    for (int i = 0; i < lenght; i++)
        port_word_out(port, tar[i]);
}

unsigned int port_int_in (unsigned short port){
    unsigned int result;
    __asm__ volatile("inl %1, %0" : "=a" (result) : "Nd" (port));
    return result;
}
void port_int_ina(unsigned short port, void* target, int lenght) {
    unsigned int data;
    unsigned int* tar = (unsigned int*)target;
    for (int i = 0; i < lenght; i++)
    {
        data = port_int_in(port);
        tar[i] = data;
    }
}
void port_int_out (unsigned short port, unsigned int data){
    __asm__ volatile("outl %0, %1" : : "a"(data), "Nd" (port));
}

