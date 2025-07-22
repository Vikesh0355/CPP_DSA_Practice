/*DEADLOCK*/
#include<iostream>
#include <thread>
#include <mutex>
using namespace std;

std::mutex m1;
std::mutex m2;

void thread1()
{
    m1.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m2.lock();
    cout<<"Critical section of thread Thread1"<<endl;
    m1.unlock();
    m2.unlock();
}

void thread2()
{
    m2.lock();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    m1.lock();
    cout<<"Critical section of thread Thread2"<<endl;
    m2.unlock();
    m1.unlock();
}

int main()
{
    thread t1(thread1);
    thread t2(thread2);
    t1.join();
    t2.join();
    return 0;
}

/*  g++ -std=c++14 deadlock.cpp -o deadlock -pthread */
/* ./deadlock  */