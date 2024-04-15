#include <stdio.h>

// gcc -o ret2libc ret2libc.c -fno-stack-protector

int main(){
        char address[10] ;
        char message[16];
        unsigned int addr ;
        puts("Can you return to library?");
        printf("Address of puts: %p\n", puts);
        printf("Address of message: %p\n", message);
        printf("Say some thing :\n");
        read(0,message,256);
        puts("Thanks you ~");
        return 0 ;
}