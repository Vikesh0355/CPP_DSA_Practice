//4. Using Non static Member function
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

class Base
{
  public:
  void run(int x)
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
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
}


/*  g++ -std=c++14 Thread_Using_NonStaticFunc.cpp -o Thread_Using_NonStaticFunc -pthread */
/* ./Thread_Using_NonStaticFunc  */