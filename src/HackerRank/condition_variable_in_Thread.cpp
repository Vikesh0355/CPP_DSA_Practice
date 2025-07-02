/*Condition variable in Thread*/
/*Condition variables are used for two purpose*/
/*1. Notify other  thread*/
/*2. Waiting for some condition*/
/*Condition variables allows running threads to wait on some condtions and once those conditions are met the waiting thread is notify using: notify_one()/notify_all()*/
/*you  need mutex to use condition variables*/
/*If some thread wants to wait on some condition then it has to do these things:*/
   /*a. Acquire the mutex lock using std::unique_lock<std:.mutex>lock(m)*/
   /*b. Execute wait, wait_for, wait_until. The wait operations release the mutex and suspend the executio of the thread*/
   /*c. When the condition variable is notified, the thread is awakened and the mutex is automatically acquired. The thread should then check the condition and resume waitinng if the wakeup was spurious*/
/*NOTE: Condition variables are used to snychronize two or more threads*/
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

std::condition_variable cv;
std::mutex m;
long Balance =0;
void addMoney(int money)
{
    std::lock_guard<mutex> lg(m);
    Balance+= money;
    cout<<"Amount added, current balance is: "<<Balance<<endl;
    cv.notify_one(); // Notifies one waiting thread
}

void withdrawMoney(int money)
{
    std::unique_lock<mutex>ul(m);
    cv.wait(ul,[]{return (Balance!=0)?true:false;}); // Waits until Balance is not zero
    if(Balance>=money)
    {
        Balance-=money;
        cout<<"Amount deducted "<<money<<endl;
    }
    else
    {
        cout<<"Amount can't be deducted , current Balance is less than "<<money<<endl;
    }
    cout<<"Current Balance is: "<<Balance<<endl;
}

int main()
{
   std::thread t1(withdrawMoney, 600);
   std::this_thread::sleep_for(std::chrono::seconds(2));
   std::thread t2(addMoney, 600);
   t1.join();
   t2.join();
   return 0;
}

/*  g++ -std=c++14 condition_variable_in_Thread.cpp -o condition_variable_in_Thread -pthread */
/* ./condition_variable_in_Thread  */