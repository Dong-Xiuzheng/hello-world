#include <thread>
#include <mutex>
#include <iostream>

volatile int counter(0);

std::mutex mtx;

void attempt_to_lock_1000(){
        for (int i=0; i<10000; ++i) { 
	    //mtx.lock();
	    counter++;
	    //mtx.unlock();
	}

}

int main(){
        
	std::thread threads[10];
	for(int i = 0; i < 10; i++){
	    threads[i] = std::thread(attempt_to_lock_1000);
	}

	for (auto& th : threads) th.join();
	std::cout << counter << " successful increases of the counter.\n";
	return 0;
}
