/*TRYLOCK: try_lock()*/
/* When you call try_lock(), the thread will attempt to acquire the lock on the mutex without waiting. If the mutex is already locked by another thread, try_lock() will return false immediately, and your thread can continue doing other work.*/
/*1. try_lock() tries to lock the mutex. Returns immediately. On successfull lock acquisation returns true otherwise return false*/
/*2. If try_lock is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking calls*/
/*3. If try_lock  called again by same thread which owns the mutex, the behavior is undefined*/
/* it is deadlock situation with undefined behavior. if you want to be able to lock the same mutex by same thread more than one time then go for recursive_mutex*/

/*E.g 1:*/
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>
using namespace std;

int counter = 0;
mutex mtx;

void increaseTheCounterFor100000Time()
{
    for(int i = 0; i<100000; ++i)
    {
        if(mtx.try_lock())
        {
            ++counter;
            mtx.unlock();
        }
    }
}

int main()
{
   thread t1(increaseTheCounterFor100000Time);
   thread t2(increaseTheCounterFor100000Time);
   t1.join();
   t2.join();
   cout<<"Counter couls increase upto:"<<counter<<endl;
   return 0;
}


/*  g++ -std=c++14 Try_lock.cpp -o Try_lock -pthread */
/* ./Try_lock  */