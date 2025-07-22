/*Timed Mutex*/
/*A timed mutex in C++ allows you to attempt to acquire a lock on a mutex for a specified duration. This can be useful when you want to avoid blocking a thread indefinitely. The std::timed_mutex class provides this functionality.
Here's an example of how to use std::timed_mutex:*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tm;

void thread1() {
    std::cout << "Thread 1 trying to lock the timed mutex..." << std::endl;
    if (tm.try_lock_for(std::chrono::seconds(2))) {
        std::cout << "Thread 1 has locked the timed mutex." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate work
        tm.unlock();
        std::cout << "Thread 1 has unlocked the timed mutex." << std::endl;
    } else {
        std::cout << "Thread 1 failed to lock the timed mutex." << std::endl;
    }
}

void thread2() {
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Ensure thread1 starts first
    std::cout << "Thread 2 trying to lock the timed mutex..." << std::endl;
    while (!tm.try_lock_for(std::chrono::seconds(1))) {
        std::cout << "Thread 2 failed to lock the timed mutex, retrying..." << std::endl;
    }
    std::cout << "Thread 2 has locked the timed mutex." << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    tm.unlock();
    std::cout << "Thread 2 has unlocked the timed mutex." << std::endl;
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}

/*  g++ -std=c++14 timed_mutex.cpp -o timed_mutex -pthread */
/* ./timed_mutex  */