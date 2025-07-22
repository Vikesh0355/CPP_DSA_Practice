/*unique_lock: std::unique_lock<mutex> lock(m1)*/
/*Key Features of std::unique_lock:
1. Deferred Locking: You can create a std::unique_lock without immediately locking the mutex.
2. Timed Locking: You can attempt to lock the mutex with a timeout.
3. Ownership Transfer: You can transfer ownership of the lock to another std::unique_lock.*/

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

std::timed_mutex m1; // Changed to std::timed_mutex
int buffer = 0;

void task(const char* threadNumber, int loopfor) {
    for (int i = 0; i < loopfor; ++i) {
        std::unique_lock<std::timed_mutex> lock(m1, std::defer_lock);
        if (lock.try_lock_for(std::chrono::milliseconds(100))) {
            buffer++;
            cout << threadNumber << buffer << endl;
        } else {
            cout << threadNumber << " failed to acquire lock" << endl;
        }
    }
}

int main() {
    thread t1(task, "T1 ", 10);
    thread t2(task, "T2 ", 10);
    t1.join();
    t2.join();
    return 0;
}

/*  g++ -std=c++14 unique_lock.cpp -o unique_lock -pthread */
/* ./unique_lock  */