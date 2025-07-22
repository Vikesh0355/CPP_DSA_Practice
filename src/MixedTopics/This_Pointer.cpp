/*This Pointer: when data member and function argument were declare with same name then it it used to distinguish between them*/
/*The 'this' pointer is passed as a hidden argument to all nonstatic member function*/

#include <iostream>
using namespace std;
class Test
{
	int a, b;
	public:
	void show(int a, int b)
	{
	 this->a= a;
	 this->b= b;

	}
	void display()
	{
	  cout<<"a="<<a<<endl;
	  cout<<"b="<<b<<endl;
	}
};

int main()
{
	Test t;
	t.show(10, 20);
	t.display();
	return 0;
}

/*  g++ -std=c++14 This_Pointer.cpp -o This_Pointer -pthread */
/* ./This_Pointer  */