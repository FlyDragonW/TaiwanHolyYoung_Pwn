#include <stdio.h>

// gcc -o fmt_2 fmt_2.c

char flag[16] = "FLAG{r3aduw4nt!}";

int main()
{
    printf("Address of flag: %p\n", flag);
    char buf[40];
    scanf("%s", buf);
    printf(buf);
    return 0;
}