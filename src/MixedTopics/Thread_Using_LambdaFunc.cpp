/*2.  Using Lambda function*/
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

int main()
{
    auto func = [](int x)
    {
        while(x-->0)
        {
            cout<<x<<endl;
        }
    };
    std::thread t(func, 10);
    t.join();
    return 0;
}

/*  g++ -std=c++14 Thread_Using_LambdaFunc.cpp -o Thread_Using_LambdaFunc -pthread */
/* ./Thread_Using_LambdaFunc  */