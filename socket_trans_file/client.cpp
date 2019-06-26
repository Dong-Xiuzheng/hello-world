#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <string.h>
#include <arpa/inet.h>

int main(){

    int clientfd = socket(AF_INET, SOCK_STREAM, 0);
    if (clientfd< 0){
        printf("create socket fail: %m\n");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(5678);

    int ret = connect(clientfd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0){
        printf("connect socket fail: %m\n");
        return -1;
    }

    int filefd = open("transfile_copy.txt", O_WRONLY|O_CREAT);
    if (filefd < 0){
        printf("open file fail: %m\n");
        return -1;
    }

    int count = 0;
    char buff[24] = {0};
    while((count = read(clientfd, buff, 24)) > 0){
        write(filefd, buff, count);
    }

    close(filefd);
    close(clientfd);

    return 0;
}
