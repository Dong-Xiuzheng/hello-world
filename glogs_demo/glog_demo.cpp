#include <glog/logging.h>  
#include<gflags/gflags.h> 
#include <iostream>

DEFINE_int32(db_type, 1, "db_type. 0=mysql, 1=sqlite");

bool validate_db_type(const char* flag_name, int value){
    if (value < 0 || value > 1){
	    LOG(FATAL) << flag_name << " input error" << std::endl;
	    return false;
    }
    return true;
}
int main(int argc,char* argv[]) {  
     google::RegisterFlagValidator(&FLAGS_db_type, &validate_db_type);
     google::ParseCommandLineFlags(&argc, &argv, true);  

    //Initialize Google's logging library.  
    google::InitGoogleLogging(argv[0]);  

    //需要先在本目录下先建立有个名为“log”的文件夹,否则会报错
    FLAGS_log_dir = "./log";
    //or  google::SetLogDestination(google::GLOG_INFO, "./log_");  
    FLAGS_logtostderr = true; //打印到屏幕
    LOG(INFO) << "hello world" << std::endl; 
    VLOG(1) <<  "debug world" << std::endl;
    VLOG(1) <<  "test flag value " << FLAGS_db_type << std::endl;
    
    return 0;  
} 
