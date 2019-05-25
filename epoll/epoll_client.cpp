#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

int main(){
    int fd=open("test.txt", O_CREAT|O_WRONLY, 0xffffffff);
    if (fd < 0) {
        printf(" open file error! error: %m");
	return -1;
    }

    int i = 0;
    while(true){
	char buf[512] = {0};
	snprintf(buf, 512, "test log num %d\n", i++);
        write(fd, buf, strlen(buf));
	sleep(5);
    }

    close(fd);
    return 0;
}
