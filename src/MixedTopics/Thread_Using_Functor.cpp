/*3. Functor(Function object)*/
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;
typedef unsigned long long ull;

class Base
{
    public:
    void operator()(int x)
    {
        while(x-->0)
        {
            cout<<x<<endl;
        }
    }
};

int main()
{
    std::thread t(Base(), 10);
    t.join();
    return 0;
}


/*  g++ -std=c++14 Thread_Using_Functor.cpp -o Thread_Using_Functor -pthread */
/* ./Thread_Using_Functor  */