#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>
#include <errno.h>
#include <arpa/inet.h>

int main(){
    
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0){
        printf("create socket fail, %m\n");
        return -1;
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);;
    addr.sin_port = htons(5678);
    int ret = connect(fd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0){
        printf("connect fail, %m\n");
        return -1;
    }

    while(1){

        char buff[128] = {0};
        int len = read(fd, buff, 128);
        if (len < 0 && errno == EINTR) {
           continue;
        }

        if (len == 0){
            break;
        }

        printf("read: %s", buff);
    }

    close(fd);


    return 0;
    
}
