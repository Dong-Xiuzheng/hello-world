#include <thread> //std::thread
#include <iostream>

void thread_task(int i){
    std::cout << "aa " << "bb " << "cc " << i << std::endl;
}

// 因为是多线程打印的，所以输出是错乱的
int main()
{
    std::thread thd(thread_task, 0);

    auto fun=[](int i){
        std::cout << "AA " << "BB " << "CC " << i << std::endl;
    };

    auto pthd=new std::thread(fun,1);

    thd.join();
    pthd->join();

    delete pthd;

    return 0;
}
