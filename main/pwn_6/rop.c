#include <stdio.h>

// gcc -o rop rop.c -static -no-pie -fno-stack-protector

char message[16];

int main()
{
    setvbuf( stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    char buf[8];
    puts("Leave some message:");
    read(0, message, 16);

    puts("Show me rop!");

    gets(buf);

    return 0;
}