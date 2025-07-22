/*DETACH NOTES:
1. This is used to detach newly created thread from parent thread
2. Always check before detaching a thread that, it is joinable otherwise we may end up double detaching and double detaching will leads to programme termination/
3. if we have to detach thread and main function is returning then detached thread execution is suspended*/

/*Either Join or detach should be called on thread object. Otherwise during thread object's destructor it will terminate the programme*/

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
  //t1.join(); /*Two times join() is not allowed it will terminate the thread*/
  cout<<"main() after"<<endl;
  return 0;
}

/*  g++ -std=c++14 Thread_Join_Detach.cpp -o Thread_Join_Detach -pthread */
/* ./Thread_Join_Detach  */