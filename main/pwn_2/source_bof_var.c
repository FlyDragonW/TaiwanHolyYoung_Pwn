#include <stdio.h>

//gcc -o chal bof_var.c -fno-stack-protector

int main() {
    setvbuf(stdout, NULL, _IONBF, 0);
    int key = 1234;

    puts("Please enter your name:");
    char name[16];
    read(0, name, 100);

    if(key == 0xfaceb00c){
        puts("FLAG{0v3rf1oW!}");
    }
    return 0;
}
