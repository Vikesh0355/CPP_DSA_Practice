/*Binary Semaphore*/
/*Values: It can be either 0 (locked) or 1 (unlocked).
Purpose: Used to manage access to a single resource, similar to a mutex.
Behavior: When the semaphore is 0, it indicates that the resource is unavailable. When it is 1, the resource is available.
Operations:
Wait (P): Decreases the semaphore value. If the value is already 0, the calling thread is blocked until the semaphore becomes 1.
Signal (V): Increases the semaphore value. If there are any waiting threads, one of them is unblocked.*/

#include <iostream>
#include <thread>
#include <semaphore.h>
#include <unistd.h>

sem_t binary_semaphore;

void thread_function1()
{
    // Wait (P) operation
    sem_wait(&binary_semaphore);
    std::cout << "Thread 1: Entering critical section." << std::endl;
    // Critical section
    sleep(2);
    std::cout << "Thread 1: Leaving critical section." << std::endl;
    // Signal (V) operation
    sem_post(&binary_semaphore);
}

void thread_function2()
{
    // Wait (P) operation
    sem_wait(&binary_semaphore);
    std::cout << "Thread 2: Entering critical section." << std::endl;
    // Critical section
    sleep(2);
    std::cout << "Thread 2: Leaving critical section." << std::endl;
    // Signal (V) operation
    sem_post(&binary_semaphore); /*sem_post function is used in multithreading to unlock a semaphore, effectively signaling that a resource is available.*/
}

int main()
{
    // Initialize the binary semaphore with value 1
    sem_init(&binary_semaphore, 0, 1); /*0: Indicates the semaphore is local to the process and 1: Sets the initial count of the semaphore to 1, meaning one thread can acquire the semaphore without blocking */

    // Create two threads
    std::thread thread1(thread_function1);
    std::thread thread2(thread_function2);

    // Wait for both threads to finish
    thread1.join();
    thread2.join();

    // Destroy the semaphore
    sem_destroy(&binary_semaphore);

    return 0;
}

/* g++ -std=c++20 Binary_Thread.cpp -o Binary_Thread -pthread */

/* ./Binary_Thread  */