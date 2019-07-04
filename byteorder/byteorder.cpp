#include <stdio.h>

int main(){
    
    union test_un{
        short s;
        char c[sizeof(short)];
    };

    test_un un;
    un.s = 0x0102;
    if (un.c[0] == 1){
        printf("big endian\n");
    } else {
        printf("little endian\n");
    }


    return 0;
}
