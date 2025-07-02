/* THREAD DETACH*/
/*Detached Thread: When you detach a thread using thread.detach(), it runs independently of the main thread. This means it will not be joined with the main thread, and the main thread does not wait for it to finish.*/
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
}

int main()
{
  std::thread t1(run,10);
  cout<<"main()"<<endl;
  t1.detach(); /*detaching T1 from main thread*/
  cout<<"main() after"<<endl;
  std::this_thread::sleep_for(chrono::seconds(5));
  return 0;
}

/*  g++ -std=c++14 Thread_detach.cpp -o Thread_detach -pthread */
/* ./Thread_detach  */
    
 
