/*SLEEP Vs WAIT in Threading*/
/*sleep
Purpose: Pauses the execution of the current thread for a specified duration.
Usage: Thread.sleep(milliseconds)
Behavior: The thread remains in the TIMED_WAITING state for the specified time and resumes execution afterward.*/
/*wait
Purpose: Causes the current thread to wait until another thread calls notify or notifyAll on the same object.
Usage: object.wait()
Behavior: The thread enters the WAITING state and remains there until it is notified.*/



/*ATOMIC VARIABLE in Threading: if we want to run a simple programme where resource are share among threads without mutex we can use it*/
/*Atomicity: Operations on atomic variables are guaranteed to be atomic, preventing race conditions.*/

#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
using namespace std;

std::atomic<int> counter; /* atomic variable counter is share between t1, t2 so it may leads to race condition, to avoid that we use here atomic variable*/
int times = 100000;
void run()
{
    for(int i = 0; i<times; ++i)
    {
        ++counter;
    }
    cout<<counter<<endl;
}

int main()
{
    std::thread t1(run);
    std::thread t2(run);
    t1.join();
    t2.join();
    return 0;
}

/*std::cout.flush(); ensures that the output is immediately flushed to the console, which can help if the output is being buffered*/

/* g++ -std=c++20 atomic_variable.cpp -o atomic_variable -pthread */

/* ./atomic_variable  */