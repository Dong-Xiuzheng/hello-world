#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/epoll.h>
#include <sys/inotify.h>
#include <stdio.h>

#define BUFFER_SIZE 2048
#define MAX_EVENTS 10

int main(){
    int epfd = epoll_create(1);
    if (epfd < 0){
        printf("epoll create fail! error %m\n");
	return -1;
    }

    int infd = inotify_init1(IN_NONBLOCK);
    if (infd < 0){
        printf("inotify_init1 fail! error %m\n");
	return -1;
    }

    int wd = inotify_add_watch(infd, "test.txt", IN_CREATE|IN_MODIFY);
    if (wd < 0){
        printf("inotify_add_watch fail! error %m\n");
	return -1;
    }

    struct epoll_event ev, events[MAX_EVENTS];
    ev.events = EPOLLIN;
    ev.data.fd = infd;
    int ret = epoll_ctl(epfd, EPOLL_CTL_ADD, infd, &ev);
    if (0!=ret){
        printf("epoll_ctl fail! %m\n");
	return -1;
    }

    int file_fd = open("test.txt", O_RDONLY);
    if (file_fd < 0){
        printf("open file fail! %m\n");
	return -1;
    }

    char buf[BUFFER_SIZE];
    while(true){
        int nfds = epoll_wait(epfd, events, MAX_EVENTS, -1);
	if (nfds == -1){
	    printf("epoll_wait error! error %m\n");
	    return -1;
	}

	for (int i = 0; i < nfds; ++i){
	    if (infd == events[i].data.fd){
	        int tmp_len = read(infd, buf, BUFFER_SIZE);
		memset(buf, 0, BUFFER_SIZE);
	        //printf("tmp_len is %d\n", tmp_len);
		//int seek_re = lseek(file_fd, -1, SEEK_CUR);
	        int read_len = read(file_fd, buf, BUFFER_SIZE);
	        //printf("read_len is %d\n", read_len);
		printf("%s", buf);	
	    }
	    else{
	        printf("error: unknown fd occurrde!\n");
	    }
	}
    }

    return 0;
}
