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

    int serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if (serverfd < 0){
        printf("create socket fail: %m\n");
        return -1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(5678);

    int ret = bind(serverfd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0){
        printf("bind socket fail: %m\n");
        return -1;
    }

    ret = listen(serverfd, 1);
    if (ret < 0){
        printf("listen socket fail: %m\n");
        return -1;
    }
    
    struct sockaddr_in conaddr;
    socklen_t len = sizeof(conaddr);
    int confd = accept(serverfd, (struct sockaddr*)&conaddr, &len);
    if (confd < 0){
        printf("accept socket fail: %m\n");
        return -1;
    }

    int filefd = open("transfile.txt", O_RDONLY);
    if (filefd < 0){
        printf("open file fail: %m\n");
        return -1;
    }

    int count = 0;
    char buff[12] = {0};
    while((count = read(filefd, buff, 12)) > 0){
        write(confd, buff, count);
    }

    shutdown(confd, SHUT_WR);
    read(confd, buff, 12); // 客户端发来FIN时会读取到0字节，不再阻塞

    close(filefd);
    close(confd);
    close(serverfd);


    


    return 0;
}
