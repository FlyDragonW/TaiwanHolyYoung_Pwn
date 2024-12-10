#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>

//gcc -o chal crashme.c -fno-stack-protector -z execstack -no-pie


void flag() {
    printf("🎉 Congrats for Crashing me! FLAG{FAKEFLAG}\n");
}

void segfault_handler(int sig) {
    printf("\n[!] Crashed!! (signal: %d)\n", sig);
    flag();
    exit(1);
}

void vuln() {
    char buffer[64];
    printf("Please enter your name: ");
    gets(buffer);
    printf("Hello, %s!\n", buffer);
}

int main() {
    signal(SIGSEGV, segfault_handler);
    setvbuf(stdout, NULL, _IONBF, 0); 
    vuln();
    return 0;
}
