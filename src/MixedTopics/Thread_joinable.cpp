/*Thread_joinable */

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

void run(int count)
{
  while(count-->0)
  {
    cout<<"cppNuts"<<endl;
    
  }
  std::this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
  std::thread t1(run,10);
  cout<<"main()"<<endl;
  t1.join();
  if(t1.joinable()) /*calling jonable to check if the thread can join or not*/
  {
  t1.join();
  }
  cout<<"main() after"<<endl;
}
  
/*  g++ -std=c++14 Thread_joinable.cpp -o Thread_joinable -pthread */
/* ./Thread_joinable  */