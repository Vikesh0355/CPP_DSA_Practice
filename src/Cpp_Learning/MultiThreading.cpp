/* What do you mean by thread and give one example in cpp*/
/* Ans: In every applications there is  a default thread which is main, inside this we create other thread */
/* A thread is also known as lightweight process, idea is to achieve parallelism by dividing a process into multiple thread*/
/* E.g A browser have  multiple tab that can be thread */

/* Ways to create thread */
/* 1. Function pointer */
/* 2. Lambda function */
/* 3. Functor */
/* 4  Member function */
/* 5. Static member function */

/*Requirement: Find the addition of all odd nummber from 1 to 1500000000 and all even number from 1 to 1500000000*/ 
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std:: chrono;
using  ull = unsigned long long;


void FindEven(ull start, ull end, ull& localEvenSum)
{
    for(ull i = start; i<=end; ++i)
    {
        if((i & 1) == 0)
        {
            localEvenSum+= i; // We are couting the sum of even number not the total number of odd
        }
    }
}

void FindOdd(ull start, ull end, ull& localOddSum)
{
    for(ull i = start; i<=end; ++i)
    {
        if((i& 1)== 1)
        {
            localOddSum += i; // We are couting the sum of odd number not the total number of odd
        }
    }
}

int  main()
{
    ull start = 0, end = 1500000000;
    auto startTime = high_resolution_clock::now();
    ull localEvenSum = 0;
    ull localOddSum = 0;
    FindEven(start, end, localEvenSum);
    FindOdd(start, end, localOddSum);
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);
    cout<<"OddSum = "<<localOddSum<<endl;
    cout<<"EvenSum = "<<localEvenSum<<endl;
    cout<<"Duration = "<<duration.count()<<"seconds"<<endl;
}

/* With Thread*/

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std:: chrono;
typedef unsigned long long ull;

void FindEven(ull start, ull end, ull& localEvenSum)
{
    for(ull i = start; i<=end; ++i)
    {
        if((i&0) == 0)
        {
            localEvenSum += i;
        }
    }
}

void FindOdd(ull start, ull end, ull& localOddSum)
{
    for(ull i = start; i<=end; ++i)
    {
        if((i&1) == 1)
        {
            localOddSum += i;
        }
    }
}

int main()
{  
    ull start = 0, end = 150000;
    auto startTime = high_resolution_clock::now();
    ull localEvenSum = 0;
    ull localOddSum = 0;
    thread t1(FindEven, start, end, ref(localEvenSum));
    thread t2(FindOdd, start, end, ref(localOddSum));
    t1.join();
    t2.join();
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<seconds>(stopTime - startTime);
    cout<<"oddSum = "<<localOddSum<<endl;
    cout<<"EvenSum = "<<localEvenSum<<endl;
    cout<<"Duration = "<<duration.count()<< "seconds"<<endl;
    return 0;

}

/* How many ways we can create thread: There  are 5 ways to create thread */
/* Note: if we will create multiple thread at the same time, it's not gurantee which thread will start first */

/* 1. Using function pointer */
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std:: chrono;
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
    std:: thread t(func, 10);
    t.join();
    return 0;
}

/* 2. Using lambda Function */
#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std:: chrono;
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

/* 3. Using Functor(Function object)*/
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
    std:: thread t (Base(), 10);
    t.join();
    return 0;
}

/* Using non-static member function*/
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

/* 5. Using Static member functions*/
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
    std::thread t(&Base::run, &b, 10);
    t.join();
    return 0;
}

/* Topic: join(), detach, joinable() in thread c++ */
/* 1. Once the thread is started we wait for this thread to finish by calling join() function on thead object */
/* 2. Double join will leads to programme termination */
/* 3. if need we should check thread is joinable before joining using joinable() function*/

/* Detach  Notes */
/* 1. This is used to detach newly created thread from parent thread*/
/* 2. Always check before detaching a thread that, i tis joinable otherwise we may end up double detaching and double detaching will leads to programme termination*/
/* 3. If we have to detach thread and main function is returning then detach thread execution is suspended  */

#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

void run(int count)
{
 while(count-->0)
 {
    cout<<"vikesh"<<endl;
 }
 std::this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
    std::thread t1(run, 10);
    cout<<"main"<<endl;
    t1.join();
    cout<<"main after"<<endl;
    return 0;

}


#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
using namespace std;

void run(int count)
{
 while(count-->0)
 {
    cout<<"vikesh"<<endl;
 }
 std::this_thread::sleep_for(chrono::seconds(3));
}

int main()
{
    std::thread t1(run, 10);
    cout<<"main"<<endl;
    t1.join();
    t1.join(); /*Two times join() is not allowed it will terminate the thread*/
    cout<<"main after"<<endl;
    return 0;

}

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
  return 0;
}


/* THREAD DETACH*/
/* Detach thread: When you detach a thread using thread.detach(), it runs independently of the main thread.
 This means it will not be joined with main thread and main thread doesn't wait for it to finish*/

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
    std:: thread t1(run, 10);
    cout<<"main"<<endl;
    t1.detach();
    cout<<"main() after"<<endl;
    std::this_thread::sleep_for(chrono::seconds(5));
    return 0;
}

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
  if(t1.joinable()) /**check if is joinable before detaching*/
  t1.detach();
  cout<<"main() after"<<endl;
  std::this_thread::sleep_for(chrono::seconds(5));
  return 0;
}

/* Function to simulate logging */
/* Function to simulate logging */
#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
std:: atomic<bool> keepLogging(true);
void logFunction()
{
    while(keepLogging)
    {
        std::cout<<" Logging data...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout<<" Logging thread terminating....\n";

}

int main()
{
    std::thread logger(logFunction);
    logger.detach();
    std::cout<<"main thread continue execution....\n";
    /* simulate main thread work*/
    std:: this_thread::sleep_for(std::chrono::seconds(5));
    // Signal the logging thread to stop
    keepLogging = false; 
     // Give the logging thread some time to terminate
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "Main thread has finished execution.\n";
    return 0;
}
