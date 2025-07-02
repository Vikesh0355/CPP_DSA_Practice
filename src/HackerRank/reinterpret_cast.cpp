/* reintrept_cast in c++ */
/* synatx: reinterpret_cast<new_type>(expression) */
/* 1. It can performs dangerous conversion becasue it can typecast any pointer to any other pointer */
#include <iostream>
using namespace std;

class Mango 
{
	public:
	void eatMango()
	{
		cout<<"Eating mango"<<endl;
	}
};

class Banana 
{
	public:
	void eatBanana()
	{
		cout<<"eating banana"<<endl;
	}
};

int main()
{
	Banana *b = new Banana();
	Mango *m = new Mango();
    Banana *newbanana = reinterpret_cast<Banana*>(m);
	newbanana-> eatBanana();
	return 0;
}

/*  g++ -std=c++14 reinterpret_cast.cpp -o reinterpret_cast -pthread */
/* ./reinterpret_cast  */