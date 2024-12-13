#include <stdio.h>
#include <stdlib.h>
#include <seccomp.h>
#include <unistd.h>

//gcc -o chal orw.c -fno-stack-protector -z execstack -lseccomp

void vuln() {
    char buffer[100];
    printf("Buffer Address: %p\n", buffer);
    printf("Please enter your name: ");
    gets(buffer);
    printf("Hello, %s!\n", buffer);
}

int main() {
    setvbuf(stdout, NULL, _IONBF, 0); 
    scmp_filter_ctx ctx = seccomp_init(SCMP_ACT_ERRNO(38));
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(rt_sigreturn), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit_group), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(exit), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(open), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(read), 0);
    seccomp_rule_add(ctx, SCMP_ACT_ALLOW, SCMP_SYS(write), 0);
    if (seccomp_load(ctx) < 0) {
        perror("seccomp_load failed");
        seccomp_release(ctx);
        return -1;
    }

    vuln();
    
    seccomp_release(ctx);
    return 0;
}
