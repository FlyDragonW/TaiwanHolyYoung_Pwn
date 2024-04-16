#include <stdio.h>

// gcc -o ret2libc ret2libc.c -fno-stack-protector

int main(){
        setvbuf( stdin, NULL, _IONBF, 0);
        setvbuf(stdout, NULL, _IONBF, 0);
        char address[10];
        char message[16];
        unsigned int addr ;
        puts("Can you return to library?");
        printf("Address of puts: %p\n", puts);
        printf("Address of message: %p\n", message);
        printf("Say some thing :\n");
        gets(message);
        puts("Thanks you ~");
        return 0 ;
}