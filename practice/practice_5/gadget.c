#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

//gcc -o chal gadget.c -fno-stack-protector -no-pie

void gadget(){
    __asm__(
        "and %r8, %rsi\n"
        "ret\n"
        "movq %rbp, 8(%rsp)\n"
        "ret\n"
        "mov %rsp, %rsi\n"
        "ret\n"
        "pop %rax\n"
        "ret\n"
        "sub $8, %rbp\n"
        "ret\n"
        "cdq\n"
        "ret\n"
        "movq %rsi, 8(%rsp)\n"
        "ret\n"
        "movq %rdi, 32(%rsp)\n"
        "ret\n"
        "lea 24(%rsp), %rdi\n"
        "ret\n"
        "pop %rdi\n"
        "syscall\n"
    );
}

void vuln() {
    char buffer[64];
    printf("Please enter your name: ");
    gets(buffer);
    printf("Hello, %s!\n", buffer);
}

int main() {
    setvbuf( stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0); 
    vuln();
    return 0;
}
