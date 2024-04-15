#include <stdio.h>
#include <sys/mman.h>

// gcc -o ret2sc ret2sc.c -fno-stack-protector -no-pie -z execstack

char message[50];

int main() {
    setvbuf(stdout,0,2,0);
    void *mem = (void *)0x00404000;
    size_t size = 0x00405000 - 0x00404000;
    mprotect(mem, size, PROT_READ | PROT_WRITE | PROT_EXEC);


    puts("Say something to me?:");
    read(0, message, 50);

    puts("Show me ret2sc!");
    char buffer[100];
    gets(buffer);
    return 0;
}