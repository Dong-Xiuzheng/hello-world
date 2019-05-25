#include <unistd.h>
#include <fcntl.h>
#include <iostream>
#include <stdio.h>

using namespace std;

int main(){

    int fd=open("test.txt", O_RDONLY);
    if (fd < 0) {
         cout << "open file error" << endl;
	 printf("error code is %m");
	 return -1;
    }
    
    char buf[2048] = {0};
    int n = read(fd, buf, 20);
    cout << "read len " << n << endl;
    cout << buf << endl;
    return 0;
}

