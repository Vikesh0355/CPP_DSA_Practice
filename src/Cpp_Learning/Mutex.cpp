/*RACE CONDITION: Race condition is a situation where two or more thread/process try to chnage common data*/
/* If there is a race condition then we have to protect it and the protected thread is called critical section/regions*/

/* MUTEX: Mutual exclusion*/
/*1. Mutex is used to avoid race condition*/
/*2. We use lock(), unlock() on mutex to avoid race condition*/
/* When you will call lock(), the thread will wait(block) untill it can acquire the lock on the mutex. if anotherthread has the lock, 
your thread will pause and wait untill the lock is released */

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

int myAmount = 0;

void addMoney()
{
    ++myAmount;

}

int main()
{
    std::thread t1(addMoney);
    std::thread t2(addMoney);
    t1.join(); /* Here t1 and t2 thread may start at same time try to increment value at same time*/
    t2.join();
    cout<<myAmount<<endl;
    return 0;
}

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include <mutex>
using namespace std;

int myAmount = 0;
std::mutex m;
void addMoney()
{
    m.lock();
    ++myAmount;
    m.unlock();
}

int main()
{
    std:: thread t1(addMoney);
    std:: thread t2(addMoney);
    t1.join();
    t2.join();
    cout<<myAmount<<endl;
    return 0;
}


/* TRYLOCK: ty_lock() */
/* 1. When you call try_lock(), the thread will attempt to  acquire the lock on the mutex without waiting. if the mutex is already locked by another thread,
try_lock() will return false immediately and your thread continue doing other work*/
/* 2. If try_lock is not able to lock mutex, then it doesn't get blocked that's why it is called non-blocking calls */
/* 3. If try_lock() called again by same thread which owns the mutex, the behaviour is undefined */
/* 4. It is deadlock situation with undefined behaviour. If you want to be able to lock the same mutex by same thread more than one timme then go for recursive_mutex()*/

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
    cout<<"Counter could increase upto:"<<counter<<endl;
    return 0;
}

 /* STD::ty_lock() tries to lock all the lockable object passed in it by one in given order*/
 /* SYNTAX: std:: ty_lock(m1, m2, ...mn);*/
 /* On successfull this function returns -1 else it will return 0 based mutex index number which it couldn't lock*/
 /* If it failed to lock any of the mutex then it will release all the mutex it locked before */
 /* If a call to try_lock result in a exception, unlock is called for any locked object before rethrowing*/

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

std::mutex m1, m2, m3;

void thread1()
{
    std::unique_lock<std::mutex> lock1(m1, std::defer_lock);
    std::unique_lock<std::mutex> lock2(m2, std::defer_lock);
    std::unique_lock<std::mutex> lock3(m3, std::defer_lock);
    
    // std::try_lock returns 0 on success when locking multiple mutexes
    if(std::try_lock(lock1, lock2, lock3) == -1)
    {
        std::cout << "Thread1 has locked all the three mutexes" << endl;
        // unique_lock will automatically unlock them when leaving this scope
    }
    else
    {
        std::cout << "Thread1 failed to lock all three mutexes" << endl;
    }
}

void thread2()
{
    std::unique_lock<std::mutex> lock1(m1, std::defer_lock);
    std::unique_lock<std::mutex> lock2(m2, std::defer_lock);
    std::unique_lock<std::mutex> lock3(m3, std::defer_lock);
    
    // std::try_lock returns 0 on success when locking multiple mutexes
    if(std::try_lock(lock1, lock2, lock3) == -1)
    {
        std::cout << "Thread2 has locked all the three mutexes" << endl;
        // unique_lock will automatically unlock them when leaving this scope
    }
    else
    {
        std::cout << "Thread2 failed to lock all three mutexes" << endl;
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

/* Timed Mutex:: A timed mutex in c++ allows you to attempt to acquire a lock on a mutex  for specified duration. This can be useful when you want to avoid blocking a thread indefinitely.
The std:: timed_mutex class provided this functionality*/

/* Example:*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;

std::timed_mutex tmd;
void thread1()
{
    cout<<"Thread1 is trying to lock the timed mutex"<<endl;
    if(tmd.try_lock_for(std::chrono::seconds(2)))
    {
        cout<<"Thread1 has locked the timed mutex"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        tmd.unlock();
        cout<<"Thread1 has unlocked the timed mutex"<<endl;
    }
    else
    {
      cout<<"Thread1 failed to lock the timed mutex"<<endl;    
    }
}

void thread2()
{
  std::this_thread::sleep_for(std::chrono::seconds(5));
  cout<<"Thread2 is trying to lock the timed mutex"<<endl;
  while(!tmd.try_lock_for(std::chrono::seconds(1)))
  {
    cout<<"thread2 failed to lock the timed mutex, retrying..."<<endl;
  }
    cout<<"thread 2 has locked the time dmutex"<<endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    tmd.unlock();
    std::cout<<" Thread 2 has unlocked the timed mutex";
}


int main()
{
 std::thread t1(thread1);
 std::thread t2(thread2);
 t1.join();
 t2.join();
 return 0;
}

/* try_lock_untill*/
/* Certainly the try_lock_untill function in c++ allows you to attempt to acquire a lock on a mutex untill a specified time point. 
This can be useful when you want to set a deadline for acquiring the lock*/

/*Example*/
#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
using namespace std;
std::timed_mutex tmd;

void thread1()
{
    cout<<"thred1 is trying to lock the timed mutex...."<<endl;
    auto deadline = std::chrono::steady_clock::now() + std::chrono::seconds(2);
    if(tmd.try_lock_until(deadline))
    {
        cout<<"Thread1 has locked the timed mutex"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        tmd.unlock();
        std::cout<<"Thread1 has unlocked the timed mutex"<<endl;
    }
    else
    {
       cout<<"Thread1  failed to lock the timed mutex"<<endl; 
    }
}

void thread2()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout<<"thread 2 trying to lock the timed mutex"<<endl;
    auto deadline = std::chrono::steady_clock::now() + std:: chrono::seconds(2);
    if(tmd.try_lock_until(deadline))
    {
        cout<<" thread 2 has locked the time dmutex"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        tmd.unlock();
        cout<<"Thread2 has unclocked the time dmutex"<<endl;
    }
    else
    {
        cout<< "Thread 2 failed to lock the timed mutex"<<endl;
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