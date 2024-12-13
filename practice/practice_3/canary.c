#include <stdio.h>

//gcc -o chal canary.c -no-pie

void backdoor(){
    system("/bin/sh");
}

void vuln() {
    char buf[40];
    printf("Address of buffer: %p\n", buf);
    printf("What do you want to say:");
    gets(buf);
    printf(buf);
    printf("Do you still have nything to say:");
    gets(buf);
    printf("bye~");
}

int main() {
    setvbuf( stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    vuln();
    
    return 0;
}
