#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    printf("execv process ok\n");
    if (argc != 1){
        printf("para number error, %u", argc);
        return -1;
    }

    int fd = atoi(argv[0]);
    printf("fd = %u\n", fd);

    int len = write(fd, "execv process, hello world\n", strlen("execv process, hello world\n"));
    if (len <= 0){
        printf("write fail, len=%u, %m\n", len);
    }
    close(fd);
    return 0;
}
