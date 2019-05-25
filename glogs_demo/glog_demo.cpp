#include <glog/logging.h>  
//#include<gflags/flags.h>  
int main(int argc,char* argv[]) {  
    // 要使用下面的api，需要安装额外的gflags,以及添加上面注释的头文件   
    // google::ParseCommandLineFlags(&argc, &argv, true);  

    // Initialize Google's logging library.  
    google::InitGoogleLogging(argv[0]);  

  //需要先在本目录下先建立有个名为“log”的文件夹,否则会报错
    FLAGS_log_dir = "./log";
    //or  google::SetLogDestination(google::GLOG_INFO, "./log_");  

    LOG(INFO) << "hello world";  

    return 0;  
} 
