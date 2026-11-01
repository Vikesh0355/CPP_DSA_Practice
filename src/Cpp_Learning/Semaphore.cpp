/* Mutex vs semaphore */
/* A semaphore is a synochronistaion primitive used to control access to a shared resource by multiple thread in  concurrent programming. In C++, you can use the std::couting_semaphore and */
#include <iostream>
#include <thread>
# include <sempahore>
using namspace std;
std::couting_semaphore<3> sempahore(3);

void worker(int id)
{
    sempahore.acquire(); // wait for the semaphore
    std::cout<<"Worker "<<id<<"is working...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std:.cout<"Worker "<<id<<"is done"<<endl;
    sempahore.release();
}

int mian()
{
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 4);
    std::thread t3(worker, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    return 0;
}

/* Binary sempahore(std:.binary_semaphore)*/
/* A Binary sempahore has maximum capacity of 1. It can be viewed as lock or signalling switch between two threads(either avilable 1 or taken 0); */
/* Notes: Unlike a mutex, a binary sempahore doesn't have  ownership- meaning Thread A can be acquired() lock() it annd Thread B can release() unlock() it. */

/* Example: Thread Signalling (Task handoff)*/
#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

// Initialized to 0 (starts locked/unavailable)
std::binary_semaphore signalSignal(0);

void workerTask()
{
    cout << "Worker: Waiting for signal to start work...\n";
    
    // Wait until main thread signals us
    signalSignal.acquire(); 
    
    cout << "Worker: Signal received! Doing work...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1));
    cout << "Worker: Done!\n";
}

int main()
{
    thread t(workerTask);
    
    cout << "Main: Doing some setup work for 2 seconds...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    
    cout << "Main: Signaling worker to proceed.\n";
    signalSignal.release(); // Unlocks/increments the semaphore to 1
    
    t.join();
    return 0;
}

/* 2. Counting Semaphore (std::counting_semaphore<N>)
A counting semaphore has a capacity greater than 1 (e.g., N). It is used when you have a finite pool of identical resources 
(like 3 database connection slots, 4 printer queues, or 2 charging stations) and want to allow up to N threads to access them simultaneously.*/


#include <iostream>
#include <thread>
#include <semaphore>
#include <chrono>

using namespace std;

// Allow up to 3 threads to access the resource concurrently
std::counting_semaphore<3> dbConnections(3);

void accessDatabase(int threadId)
{
    cout << "Thread " << threadId << " is waiting for a database connection...\n";
    
    // Acquire one of the 3 available slots
    dbConnections.acquire(); 
    
    cout << "--> Thread " << threadId << " ACQUIRED a connection and is querying...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate work
    
    cout << "<-- Thread " << threadId << " RELEASED the connection.\n";
    
    // Release the slot back to the pool
    dbConnections.release(); 
}

int main()
{
    // Launch 6 threads, but only 3 can run concurrently
    thread t1(accessDatabase, 1);
    thread t2(accessDatabase, 2);
    thread t3(accessDatabase, 3);
    thread t4(accessDatabase, 4);
    thread t5(accessDatabase, 5);
    thread t6(accessDatabase, 6);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    
    return 0;
}