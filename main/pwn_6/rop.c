#include <stdio.h>

// gcc -o rop rop.c -static -no-pie -fno-stack-protector

char message[16];

int main()
{
    char buf[8];
    puts("Leave some message:");
    read(0, message, 16);

    puts("Show me rop!");

    read(0, buf, 100);

    return 0;
}