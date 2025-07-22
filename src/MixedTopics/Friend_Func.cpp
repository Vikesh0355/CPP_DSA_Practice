/*Friend Function: Friend function of a class is defined outside that class' scope but it has the right to access all private and protected members of the class.*/
#include <iostream>
using namespace std;
class sample
{
    int a,b;
    public:
    friend void print(sample& s); /*friend function declaration*/
};
void print(sample& s)  /*friend function definition*/
{
    s.a = 10;
    s.b = 20;
    cout<<"a = "<<s.a<<endl;
    cout<<"b = "<<s.b<<endl;
}

/*Write an program to find big numer between two classes using friend function*/

class Test2;
class Test1
{
    int a;
    public:
    void geta()
    {
        cout<<"Enter the value of a"<<endl;
        cin>>a;
    }
    friend void big(Test1, Test2);
};
class Test2
{
    int b;
    public:
    void getb()
    {
        cout<<"Enter the value of b"<<endl;
        cin>>b;
    }
    friend void  big(Test1, Test2);
};
 void  big(Test1 t1, Test2 t2)
 {
	if(t1.a>t2.b)
	{
		cout<<"a is big "<<t1.a<<endl;
	}
	else if(t2.b>t1.a)
	{
		cout<<"b is big "<<t2.b<<endl;
	}
	else
		cout<<"Both are equal";
    
 }

int main()
{
    sample s;
    print(s);

    Test1 t1;
    Test2 t2;
    t1.geta();
    t2.getb();
    big(t1, t2);

    return 0;
}

/*  g++ -std=c++14 Friend_Func.cpp -o Friend_Func -pthread */
/* ./Friend_Func  */