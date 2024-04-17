#include <stdio.h>

// gcc -o fmt_2 fmt_2.c

char flag[16] = "FLAG{FAKE_FLAG!}";

int main()
{
    setvbuf( stdin, NULL, _IONBF, 0);
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Address of flag: %p\n", flag);
    char buf[40];
    scanf("%s", buf);
    printf(buf);
    return 0;
}