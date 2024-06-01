#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o heap_bof heap_bof.c

int main()
{
    setvbuf( stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    
    char *message = malloc(0x20);
    char *key = malloc(0x20);
    const char *secret = "secret";

    puts("What do you want to tell me?");
    gets(message);
    puts("Cool!");

    if(strcmp(key, secret) == 0){
        system("/bin/sh");
    }

    free(message);
    free(key);
    return 0;
}