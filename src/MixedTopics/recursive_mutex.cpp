/*Recursive Mutex*/
/*1. It is same as mutex but, same thread can lock mutex multiple times using recursive_mutex*/
/*If thread t1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1,now as T1 is running in recursion T1 can call lock/try_lock any number of times there is no issue */
/*But if T1 has acquired 10 times lock/try_lock on mutex m1 then thread t1 will have to unlock it 10 times otherwise no other thread will be able to lock mutex m1*/
/*it means recursive mutex keeps count how many it has locked so that many times it has to unlock the mutex*/

#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex mtx;

void recursiveFunction(int count) {
    if (count <= 0) 
    return;

    mtx.lock();
    std::cout << "Lock acquired, count: " << count << std::endl;

    // Recursive call
    recursiveFunction(count - 1);

    std::cout << "Unlocking, count: " << count << std::endl;
    mtx.unlock();
}

int main()
{
    std::thread t1(recursiveFunction, 3);
    t1.join();
    return 0;
}

/*  g++ -std=c++14 recursive_mutex.cpp -o recursive_mutex -pthread */
/* ./recursive_mutex  */