#include <stdio.h>

//gcc -o ret2text ret2text.c -fno-stack-protector -no-pie

void backdoor(){
    system("/bin/sh");
}

int main() {
    char buffer[8];
    gets(buffer);
    return 0;
}