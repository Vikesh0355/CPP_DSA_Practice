/*Function to simulate logging**/

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

std::atomic<bool> keepLogging(true); /*Atomic flag to signal the logging thread to stop*/ 

void logFunction() {
    while (keepLogging) {
        std::cout << "Logging data...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "Logging thread terminating...\n";
}

int main() 
{
    // Create a thread for logging
    std::thread logger(logFunction);

    // Detach the logging thread
    logger.detach();

    std::cout << "Main thread continues execution...\n";

    // Simulate main thread work
    std::this_thread::sleep_for(std::chrono::seconds(5));

    // Signal the logging thread to stop
    keepLogging = false;

    // Give the logging thread some time to terminate
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Main thread has finished execution.\n";
    return 0;
}

/*  g++ -std=c++14 Thread_Logging.cpp -o Thread_Logging -pthread */
/* ./Thread_Logging  */