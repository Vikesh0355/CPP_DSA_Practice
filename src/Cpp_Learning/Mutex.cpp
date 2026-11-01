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


/* Recursive Mutex:*/
/* 1. It is same as mutex but, same thread can lock mutex multiple times using recursive_mutex*/
/* 2. if thread T1 first call lock/try_lock on recursive mutex m1, then m1 is locked by T1. Now T1 is running in recursion T1 can lock/try_lock any number of times there is no issue*/
/* 3. But if T1 has acquired 10 times lock/tr_lock on mutex M1 then thread t1 will have to unlock it 10 times otherwise no other thread will be able to lock the mutex m1*/
/* 4. it means recursive mutex keeps count how many it has locked so that as many times it has to unlock the mutex*/


#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

recursive_mutex m1;
int buffer = 0;

void recursion(char c, int loopfor)
{
    // Fixed base case: stop when loopfor reaches 0
    if(loopfor <= 0)
    {
        return; 
    }
    
    m1.lock();
    cout << "ThreadID: " << c << " " << buffer++ << endl;
    
    // Pass loopfor - 1 to avoid side-effect issues with prefix/postfix decrements in arguments
    recursion(c, loopfor - 1);
    
    m1.unlock();
    cout << "unlocked by thread " << c << endl;
}

int main()
{
    thread t1(recursion, '1', 3); // Using 3 so output is short and readable
    thread t2(recursion, '2', 3);
    
    t1.join();
    t2.join();
    
    return 0;
}

/*Lock guard in c++: std::lock_guard<std::mutex*/
/* It acquires mutex lock,  the moment you create the object of lock_guard */
/* It automatically removes the lock when it goes out of scope*/
/* You can explictly unlock the lock guard*/


#include <iostream>
#include <thread>
#include <mutex>

std:: recursive_mutex  mtx;
int Factorial(int num)
{
    if(num<=1)
    {
        return 1;
    }
    else
    {
        return num*Factorial(--num);
    }
}

void threadFunction(int num)
{
    std::lock_guard<std::recursive_mutex>lock(mtx);
    int result = Factorial(num);
    std::cout<<"Factorial of "<<num<<" is: "<<result<<std::endl;
}

int main()
{
    int number = 8;
    std:: thread t1(threadFunction , number);
    t1.join();
    return 0;
}


/* unique_lock: std::unique_lock<mutex> lock(m1)*/
/* key feature of std::unique_lock*/
/* 1. Deferred locking: You can create a std::unique_lock wihout immediately locking the mutex*/
/* 2. Timed locking: You can attempt to lock the mutex with a timeout/
/* 3. Ownership Transfer: You can transfer ownership of the lock to another std::unique_lock */

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std:: mutex m1;
int buffer = 0;
void task(const char* threadNumber, int loopfor)
{
    for(int i = 0; i<loopfor; ++i)
    {
        std::unique_lock<std::mutex>lock(m1);
        buffer++;
        cout<<threadNumber<<" "<< buffer<<endl;
    }
}

int main()
{
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();
    return 0;
}

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std:: timed_mutex m1;
int buffer = 0;
void task(const char* threadNumber, int loopfor)
{
    for(int i = 0; i<loopfor; ++i)
    {
        std::unique_lock<std::timed_mutex>lock(m1, std::defer_lock)
        if(lock.try_lock_for(std::chrono::milliseconds(100)))
        {
            buffer++;
            cout<<threadNumber<<" "<<buffer<<endl;
        }
        else
        {
            cout<<Threadnumber <<"failed to acquire the lock"<<endl;
        }
    }
}

int mian()
{
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();
    return 0;
}

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std:: timed_mutex m1;
int buffer = 0;
void task(const char* threadNumber, int loopfor)
{
    for(int i = 0; i<loopfor; ++i)
    {
        std::unique_lock<std::timed_mutex>lock(m1, std::defer_lock);
        if(lock.try_lock_for(std::chrono::milliseconds(100)))
        {
            buffer++;
            cout<<threadNumber<<" "<<buffer<<endl;
        }
        else
        {
            cout<<threadNumber <<"failed to acquire the lock"<<endl;
        }
    }
}

int main()
{
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();
    return 0;
}

/* Condition variable in thread*/
/* Condition variables are used for two purpose */
/* 1. Notify other thread */
/* 2. Waiting for some condition*/
/* 3. Condition variables allows running thread to wait for on some condition and once those condition are met the waiting thread is notify using notify_one/notify_all*/

/* if you need mutex to use condition variables*/
/* If some thread wants to wait on some condition then it has to do these things*/
/* a. Acquire the mutex lock using std::unique_lock<std::mutex>lock(m)*/
/* b. Execute wait, wait_for, wait_untill. The wait operations release the mutex and suspend the execution of thread*/
/* c. When the condtion varables is notified, the thread is awkaned and the mutex is automatically acquire. The thread should then check the condition and resume wake for waiting if the wake was spurious */
/* d. conditon variable are used to synchronised two or more threads*/

#include <iostream>
#include <thread>
#include<mutex>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long Balance;
void addMoney(int money)
{
    std::lock_guard<mutex>lg(m);
    Balance+= money;
    cout<<"Amount added, current balance is : "<<Balance<<endl;
    cv.notify_one();
}

void withdrawMoney(int Money)
{
    std::unique_lock<mutex>ul(m);
    cv.wait(ul, []{return (Balance!=0)?true:false;});
    if(Balance>= Money)
    {
        Balance-=Money;
        
    }
}

int main()
{
   std::thread t1(withdrawMoney, 600);
   //std::this_thread::sleep_for(std::chrono::seconds(2));
   std::thread t2(addMoney, 600);
   t1.join();
   t2.join();
   return 0;
}
