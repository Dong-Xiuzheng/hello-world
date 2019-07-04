#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <netinet/ip.h>

int main(){
    
    int lifd = socket(AF_INET, SOCK_STREAM, 0);
    if (lifd < 0){
        printf("create socket fail, %m\n");
        return -1;
    }
    
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(5678);
    int ret = bind(lifd, (struct sockaddr*)&addr, sizeof(addr));
    if (ret < 0){
        printf("bind fail, %m\n");
        return -1;
    }

    ret = listen(lifd, 5);
    if (ret < 0){
        printf("listen fail, %m\n");
        return -1;
    }

    while(1){
        int confd = accept(lifd, NULL, NULL);
        if (confd < 0){
            printf("accept fail, %m\n");
            return -1;
        }

        printf("accept success\n");
        
        int pid = fork();
        if (pid == 0){
            printf("fork process ok\n");
            int len = write(confd, "hello world!\n", strlen("hello world!\n"));
            char *argv[2];
            char arg1[2] = {0};
            snprintf(arg1, 2, "%u", confd);
            argv[0] = arg1;
            argv[1] = NULL;
            int ret = execv("./execv", argv);
            if (ret < 0){
                printf("execv fail, %m\n");
                close(confd);
            }

        }else{
            close(confd);
        }

    }

    close(lifd);


    return 0;
    
}
