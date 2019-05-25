#include <unistd.h>
#include <string.h>
#include <iostream>
#include <fcntl.h>

using namespace std;
int main(){

    int fd = open("test.txt", O_CREAT|O_APPEND|O_WRONLY,0xffffffff);
    if (fd < 0) cout << "open file error" << endl;
    char buf[2048] = {0};
    snprintf(buf, 2048, "%s\n%s\n%s\n", "test line a!", "test line b!", "tesT line c!"); 
    int n = write(fd, buf, strlen(buf));
    cout << "write len is " << n << endl; 
    return 0;
}
