/*STD::try_lock() tries to lock all the lockable object passed in it by one in given order*/
/*SYNTAX: std::try:lock(ma, m2,......mn);*/
/*on successfull this function returns -1 else it will return 0 based mutex index number which it couldn't lock*/
/*if it failes to lock any of the mutex then it will release all the mutex it locked before*/
/*if a call to try_lock result in an exception, unlock is called for any locked object before rethrowing*/

#include <iostream>
#include <thread>
#include <mutex>

std::mutex m1, m2, m3;

void thread1() {
    std::unique_lock<std::mutex> lock1(m1, std::defer_lock);
    std::unique_lock<std::mutex> lock2(m2, std::defer_lock);
    std::unique_lock<std::mutex> lock3(m3, std::defer_lock);

    if (std::try_lock(lock1, lock2, lock3) == -1) {
        std::cout << "Thread 1 has locked all three mutexes." << std::endl;
        // Critical section
    } else {
        std::cout << "Thread 1 failed to lock all three mutexes." << std::endl;
    }
}

void thread2() {
    std::unique_lock<std::mutex> lock1(m1, std::defer_lock);
    std::unique_lock<std::mutex> lock2(m2, std::defer_lock);
    std::unique_lock<std::mutex> lock3(m3, std::defer_lock);

    if (std::try_lock(lock1, lock2, lock3) == -1) {
        std::cout << "Thread 2 has locked all three mutexes." << std::endl;
        // Critical section
    } else {
        std::cout << "Thread 2 failed to lock all three mutexes." << std::endl;
    }
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}

/*  g++ -std=c++14 std_try_lock.cpp -o std_try_lock -pthread */
/* ./std_try_lock  */