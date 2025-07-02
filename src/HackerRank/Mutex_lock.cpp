/*RACE CONDITION:*/
/*1. Race condition is a situation where two oe more thread/process  try to change common data*/
/*2: If there is a race condition then we have to protect it and the protected thread is called critical section/region*/

/*MUTEX: Mutual Exclusion*/
/*1. Mutex is used to avoid RACE contion*
/*2. We used lock(), unlock() on mutex to avoaid race contion*/
/*When you call lock(), the thread will wait (block) until it can acquire the lock on the mutex. If another thread has the lock, your thread will pause and wait until the lock is released.*/

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


/*  g++ -std=c++14 Mutex_lock.cpp -o Mutex_lock -pthread */
/* ./Mutex_lock  */