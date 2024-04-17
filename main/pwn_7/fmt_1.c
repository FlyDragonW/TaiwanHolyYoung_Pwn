#include <stdio.h>

// gcc -o fmt_1 fmt_1.c

int main()
{
    char buf[40];
    char flag[16] = "FLAG{FAKE_FLAG!}";
    scanf("%s", buf);
    printf(buf);
    return 0;
}