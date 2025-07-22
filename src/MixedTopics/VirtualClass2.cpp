/**********correct programme: Virtual classes in C++*************/
using namespace std;
#include <iostream>

class C1
{
	public:
	void c1func()
	{
		cout<<"c1 class function called"<<endl;
	}
};

class C2: public  virtual C1
{
	public:
	void c2func()
	{
		cout<<"c2 class function called"<<endl;
	}
};

class C3:public  virtual C1
{
	public:
	void c3func()
	{
		cout<<"c3 class function called"<<endl;
	}
};

class C4: public C2, public C3
{
	public:
	void c4func()
	{
		cout<<"c4 class function called"<<endl;
	}
};
int  main()
{
	C4  obj;
	obj.c1func(); 
	obj.c2func();
	obj.c3func();
	obj.c4func();
	return 0;
}