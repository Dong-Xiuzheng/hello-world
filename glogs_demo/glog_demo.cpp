#include <glog/logging.h>  
#include<gflags/gflags.h>  
int main(int argc,char* argv[]) {  
     google::ParseCommandLineFlags(&argc, &argv, true);  

    //Initialize Google's logging library.  
    google::InitGoogleLogging(argv[0]);  

    //需要先在本目录下先建立有个名为“log”的文件夹,否则会报错
    FLAGS_log_dir = "./log";
    //or  google::SetLogDestination(google::GLOG_INFO, "./log_");  

    LOG(INFO) << "hello world";  

    return 0;  
} 
