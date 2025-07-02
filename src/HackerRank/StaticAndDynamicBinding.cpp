/*What is Static and Dynamic Binding in c++*/
/*Ans: This is functioin call mechanism determined at compile time or run time*/
/*If function calling is known at compile time then => static binding*/
/*If function call is known at run time then=> dynamic binding*/

#include <iostream>
using namespace std;

class Base 
{
	public:
	int  _b_var;
	virtual void func()
	{
		cout<<"Base func"<<endl;
	}
};  
class Derived : public Base 
{
	int _d_var;
	void func()
	{
		cout<<"Derived func"<<endl;
	}
};

void myfunc(Base *obj)
{
	obj->func();
}

int main()
{
	myfunc(new Base);  /*static binding*/
	myfunc(new Derived); /*Dynamic binding*/
}

/*  g++ -std=c++14 StaticAndDynamicBinding.cpp -o StaticAndDynamicBinding -pthread */
/* ./StaticAndDynamicBinding  */