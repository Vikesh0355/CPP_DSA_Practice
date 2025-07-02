/*1. using function pointer*/
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

void func(int x)
{
    while(x-->0)
    {
        cout<<x<<endl;
    }
}
int main()
{
    std::thread t(func, 10);
    t.join();
    return 0;
}

/*  g++ -std=c++14 Thread_Using_FuncPtr.cpp -o Thread_Using_FuncPtr -pthread */
/* ./Thread_Using_FuncPtr  */

