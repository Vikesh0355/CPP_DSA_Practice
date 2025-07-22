/*Lock Guard in c++: std::lock_guard<std::mutex>*/
/*It acquires mutex lock the moment you  create the object of lock_guard*
/*It automatically removes the lock when it goes out  of scope*/
/*You can exlicitly unlock the lock guard*/

#include <iostream>
#include <thread>
#include <mutex>

std::recursive_mutex mtx;

int Factorial(int num) {
    if (num <= 1) {
        return 1;
    } else {
        return num * Factorial(num - 1);
    }
}

void threadFunction(int num)
{
    std::lock_guard<std::recursive_mutex> lock(mtx);
    int result = Factorial(num);
    std::cout << "Factorial of " << num << " is: " << result << std::endl;
}

int main() {
    int number = 8;
    std::thread t1(threadFunction, number);

    t1.join();

    return 0;
}

/*  g++ -std=c++14 lock_guard.cpp -o lock_guard -pthread */
/* ./lock_guard  */