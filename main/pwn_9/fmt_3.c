#include <stdio.h>

// gcc -o fmt_3 fmt_3.c

char key = 'a';

int main()
{
    setvbuf( stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Address of key: %p\n", &key);
    char buf[40];
    scanf("%s", buf);
    printf(buf);
    if(key == 'b') system("/bin/sh");
    return 0;
}