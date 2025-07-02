#include <iostream>
#include <thread>
#include <semaphore> // Requires C++20
#include <chrono>

using namespace std;

// Allows up to 3 threads to access the resource concurrently
std::counting_semaphore<3> semaphore(3);

void worker(int id) {
    semaphore.acquire(); // Wait (decrement)
    std::cout << "Worker " << id << " is working...\n";
    std::this_thread::sleep_for(std::chrono::seconds(1)); // Simulate work
    std::cout << "Worker " << id << " is done.\n";
    semaphore.release(); // Signal (increment)
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);
    std::thread t4(worker, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}

 /* g++ -std=c++20 semaphore.cpp -o semaphore -pthread */

/* ./semaphore  */