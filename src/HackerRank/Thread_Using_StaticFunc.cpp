/*5. Using static Member function */
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

class Base
{
  public:
  static void run(int x)
  {
      while(x-->0)
      {
          cout<<x<<endl;
      }
  }
};
int main()
{
    Base b;
    std::thread t(&Base::run, 10);
    t.join();
    return 0;
}

/*  g++ -std=c++14 Thread_Using_StaticFunc.cpp -o Thread_Using_StaticFunc -pthread */
/* ./Thread_Using_StaticFunc  */