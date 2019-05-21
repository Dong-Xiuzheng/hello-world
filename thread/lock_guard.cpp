#include <thread>
#include <mutex>
#include <iostream>

std::mutex mtx;

volatile int counter = 0;

void attemp_to_add_1000()
{
	for (int i = 0; i < 1000; i++){
	    std::lock_guard<std::mutex> lck(mtx);
	    counter++;
	}
}

int main(){
    std::thread threads[10];

    for (int i = 0; i < 10; i++){
        threads[i]=std::thread(attemp_to_add_1000);
    }

    for (auto &thd : threads){
        thd.join();
    }

    std::cout << "counter is " << counter << std::endl;
    return 0;
}
