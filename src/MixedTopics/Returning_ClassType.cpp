/*Returning class data Type*/
#include <iostream>
using namespace std;

class Test
{
	int a, b;
	public:
	void getdata();
	void display();
	Test sum(Test);
};

void Test::getdata()
{
 cout<<"Enter the value of a"<<endl;
 cin>>a;
 cout<<"Enter the value of b"<<endl;
 cin>>b;
}

void Test::display()
{
  cout<<"a="<<a<<endl;
  cout<<"b="<<b<<endl;
}

 Test Test::sum(Test t2)
 {
     Test t3;
     t3.a = a+t2.a;
     t3.b = b+t2.b;
     return t3;
 }
int main()
{
	Test t1, t2, t3;
    t1.getdata();
    t2.getdata();
    t3 = t1.sum(t2);
    cout<<"t3 obj data is"<<endl;
	t3.display();
	return 0;
}

/*  g++ -std=c++14 Returning_ClassType.cpp -o Returning_ClassType -pthread */
/* ./Returning_ClassType  */