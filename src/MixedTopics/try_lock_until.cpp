/*try_lock_until*/
/*Certainly! The try_lock_until function in C++ allows you to attempt to acquire a lock on a mutex until a specified time point. This can be useful when you want to set a deadline for acquiring the lock.

Here's an example using std::timed_mutex and try_lock_until:*/

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::timed_mutex tm;

void thread1() 
{
    std::cout << "Thread 1 trying to lock the timed mutex..." << std::endl;
    auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    if (tm.try_lock_until(deadline))
    {
        std::cout << "Thread 1 has locked the timed mutex." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3)); // Simulate work
        tm.unlock();
        std::cout << "Thread 1 has unlocked the timed mutex." << std::endl;
    } 
    else 
    {
        std::cout << "Thread 1 failed to lock the timed mutex." << std::endl;
    }
}

void thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Ensure thread1 starts first
    std::cout << "Thread 2 trying to lock the timed mutex..." << std::endl;
    auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    if (tm.try_lock_until(deadline))
    {
        std::cout << "Thread 2 has locked the timed mutex." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
        tm.unlock();
        std::cout << "Thread 2 has unlocked the timed mutex." << std::endl;
    } 
    else 
    {
        std::cout << "Thread 2 failed to lock the timed mutex." << std::endl;
    }
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);

    t1.join();
    t2.join();

    return 0;
}

/*  g++ -std=c++14 try_lock_until.cpp -o try_lock_until -pthread */
/* ./try_lock_until  */