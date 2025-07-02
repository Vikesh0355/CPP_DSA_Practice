/*With Threads*/
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

void FindEven(ull start, ull end, ull& localEvenSum)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 0)
        {
            localEvenSum += i;
        }
    }
}

void FindOdd(ull start, ull end, ull& localOddSum)
{
    for (ull i = start; i <= end; ++i)
    {
        if ((i & 1) == 1)
        {
            localOddSum += i;
        }
    }
}

int main()
{
    ull start = 0, end = 1500000000; // Reduced range
    auto startTime = high_resolution_clock::now();

    ull localEvenSum = 0;
    ull localOddSum = 0;

    thread t1(FindEven, start, end, ref(localEvenSum));
    thread t2(FindOdd, start, end, ref(localOddSum));

    t1.join();
    t2.join();


    auto stoptime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stoptime - startTime);
    cout << "OddSum = " << localOddSum << endl;
    cout << "EvenSum = " << localEvenSum << endl;
    cout << "Duration = " << duration.count() << "seconds" << endl;

    return 0;
}

/*  g++ -std=c++14 Addition_OddNum.cpp -o Addition_OddNum -pthread */
/* ./Addition_OddNum  */
