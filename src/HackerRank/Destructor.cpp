/******Destructor************/
#include <iostream>
using namespace std;

class sample
{
	int a, b;
	public:
	sample() //constructor
	{
		a=10;
		b=20;
	}
	~sample() //destructor
	{
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;	
		
	}
};

int main()
{
	sample s;
}

/*  g++ -std=c++14 Destructor.cpp -o Destructor -pthread */
/* ./Destructor  */